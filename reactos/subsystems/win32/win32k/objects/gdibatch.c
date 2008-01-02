
#include <w32k.h>

#define NDEBUG
#include <debug.h>


//
//
// Gdi Batch Flush support functions.
//

//
// DoDeviceSync
//
// based on IntEngEnter from eng/engmisc.c
//
VOID
FASTCALL
DoDeviceSync( SURFOBJ *Surface, PRECTL Rect, FLONG fl)
{
  PGDIDEVICE Device = (GDIDEVICE*)Surface->hdev;
// No punting and "Handle to a surface, provided that the surface is device-managed. 
// Otherwise, dhsurf is zero".
  if (!(Device->flFlags & PDEV_DRIVER_PUNTED_CALL) && (Surface->dhsurf))
  {
     if (Device->DriverFunctions.SynchronizeSurface)
        return Device->DriverFunctions.SynchronizeSurface(Surface, Rect, fl);
     else
     {
       if (Device->DriverFunctions.Synchronize)
          return Device->DriverFunctions.Synchronize(Surface->dhpdev, Rect);
     }
  }
  return;  
}

VOID
FASTCALL
SynchonizeDriver(FLONG Flags)
{
  SURFOBJ *SurfObj; 
  PGDIDEVICE Device;
  
  if (Flags & GCAPS2_SYNCFLUSH)
      Flags = DSS_FLUSH_EVENT;
  if (Flags & GCAPS2_SYNCTIMER)
      Flags = DSS_TIMER_EVENT;

  Device = IntEnumHDev();

  SurfObj = EngLockSurface( Device->pSurface );
  if(!SurfObj) return;
  DoDeviceSync( SurfObj, NULL, Flags);
  EngUnlockSurface(SurfObj);
  return;
}

//
// Process the batch.
//
ULONG
FASTCALL
GdiFlushUserBatch(HDC hDC, PGDIBATCHHDR pHdr)
{
  PDC dc = NULL;
  PDC_ATTR Dc_Attr = NULL;
  if (hDC && !IsObjectDead(hDC))
  {
    dc = DC_LockDc(hDC);
    if (dc)
    {
      Dc_Attr = dc->pDc_Attr;
      if (!Dc_Attr) Dc_Attr = &dc->Dc_Attr;
    }
  }
  // The thread is approaching the end of sunset.
  switch(pHdr->Cmd)
  {
     case GdiBCPatBlt: // Highest pri first!
        break;
     case GdiBCPolyPatBlt:
        break;
     case GdiBCTextOut:
        break;
     case GdiBCExtTextOut:
        break;
     case GdiBCSetBrushOrg:
     {
        PGDIBSSETBRHORG pgSBO;
        if(!dc) break;
        pgSBO = (PGDIBSSETBRHORG) pHdr;
        Dc_Attr->ptlBrushOrigin = pgSBO->ptlBrushOrigin;
        break;
     }
     case GdiBCExtSelClipRgn:
        break;
     case GdiBCSelObj:
     {
        PGDIBSOBJECT pgO;
        if(!dc) break;
        pgO = (PGDIBSOBJECT) pHdr;
        if(NT_SUCCESS(TextIntRealizeFont((HFONT) pgO->hgdiobj)))
                      Dc_Attr->hlfntNew = (HFONT) pgO->hgdiobj;
     }
     case GdiBCDelObj:
     case GdiBCDelRgn:
     {
        PGDIBSOBJECT pgO = (PGDIBSOBJECT) pHdr;
        NtGdiDeleteObject( pgO->hgdiobj );
        break;
     }
     default:
        break;
  }
  if (dc) DC_UnlockDc(dc);
  return pHdr->Size; // Return the full size of the structure.
}

/*
 * NtGdiFlush
 *
 * Flushes the calling thread's current batch.
 */
VOID
APIENTRY
NtGdiFlush(VOID)
{
  SynchonizeDriver(GCAPS2_SYNCFLUSH);
}

/*
 * NtGdiFlushUserBatch
 *
 * Callback for thread batch flush routine.
 *
 * Think small & fast!
 */
NTSTATUS
APIENTRY
NtGdiFlushUserBatch(VOID)
{
  PTEB pTeb = NtCurrentTeb();
  ULONG GdiBatchCount = pTeb->GdiBatchCount;

  if( (GdiBatchCount > 0) && (GdiBatchCount <= (GDIBATCHBUFSIZE/4)))
  {
    HDC hDC = (HDC) pTeb->GdiTebBatch.HDC;
//
//  If hDC is zero and the buffer fills up with delete objects we need to run
//  anyway. So, hard code to the system batch limit.
//
    if ((hDC) || ((!hDC) && (GdiBatchCount >= GDI_BATCH_LIMIT)))
    {
       PULONG pHdr = &pTeb->GdiTebBatch.Buffer[0];
       // No need to init anything, just go!
       for (; GdiBatchCount > 0; GdiBatchCount--)
       {
           // Process Gdi Batch!
           pHdr += GdiFlushUserBatch( hDC, (PGDIBATCHHDR) pHdr );
       }
       // Exit and clear out for the next round.
       pTeb->GdiTebBatch.Offset = 0;
       pTeb->GdiBatchCount = 0;
       pTeb->GdiTebBatch.HDC = 0;
    }
  }
  return STATUS_SUCCESS;
}


