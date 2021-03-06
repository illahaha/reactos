/* Version definitions */
#undef NTDDI_VERSION
#define NTDDI_VERSION NTDDI_WINBLUE
#undef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_WINBLUE

#include <ntifs.h>
#include <ndk/ntndk.h>

#define C_ASSERT_FIELD(Type, Offset, MemberType, MemberName) C_ASSERT(FIELD_OFFSET(Type, MemberName) == Offset);

/* KTHREAD */
C_ASSERT_FIELD(KTHREAD, 0x000, DISPATCHER_HEADER, Header)
C_ASSERT_FIELD(KTHREAD, 0x018, PVOID, SListFaultAddress)
C_ASSERT_FIELD(KTHREAD, 0x020, UINT64, QuantumTarget)
C_ASSERT_FIELD(KTHREAD, 0x028, PVOID, InitialStack)
C_ASSERT_FIELD(KTHREAD, 0x030, PVOID, StackLimit)
C_ASSERT_FIELD(KTHREAD, 0x038, PVOID, StackBase)
C_ASSERT_FIELD(KTHREAD, 0x040, UINT64, ThreadLock)
C_ASSERT_FIELD(KTHREAD, 0x048, UINT64, CycleTime)
C_ASSERT_FIELD(KTHREAD, 0x050, ULONG32, CurrentRunTime)
C_ASSERT_FIELD(KTHREAD, 0x054, ULONG32, ExpectedRunTime)
C_ASSERT_FIELD(KTHREAD, 0x058, PVOID, KernelStack)
C_ASSERT_FIELD(KTHREAD, 0x060, XSAVE_FORMAT*, StateSaveArea)
C_ASSERT_FIELD(KTHREAD, 0x068, KSCHEDULING_GROUP*, SchedulingGroup)
C_ASSERT_FIELD(KTHREAD, 0x070, KWAIT_STATUS_REGISTER, WaitRegister)
C_ASSERT_FIELD(KTHREAD, 0x071, UINT8, Running)
C_ASSERT_FIELD(KTHREAD, 0x072, UINT8[2], Alerted)
C_ASSERT_FIELD(KTHREAD, 0x074, LONG32, MiscFlags)
C_ASSERT_FIELD(KTHREAD, 0x078, LONG32, ThreadFlags)
C_ASSERT_FIELD(KTHREAD, 0x07C, ULONG32, Spare0)
C_ASSERT_FIELD(KTHREAD, 0x080, ULONG32, SystemCallNumber)
C_ASSERT_FIELD(KTHREAD, 0x084, ULONG32, Spare1)
C_ASSERT_FIELD(KTHREAD, 0x088, PVOID, FirstArgument)
C_ASSERT_FIELD(KTHREAD, 0x090, KTRAP_FRAME*, TrapFrame)
C_ASSERT_FIELD(KTHREAD, 0x098, KAPC_STATE, ApcState)
C_ASSERT_FIELD(KTHREAD, 0x0C3, CHAR, Priority)
C_ASSERT_FIELD(KTHREAD, 0x0C4, ULONG32, UserIdealProcessor)
C_ASSERT_FIELD(KTHREAD, 0x0C8, INT64, WaitStatus)
C_ASSERT_FIELD(KTHREAD, 0x0D0, KWAIT_BLOCK*, WaitBlockList)
C_ASSERT_FIELD(KTHREAD, 0x0D8, LIST_ENTRY, WaitListEntry)
C_ASSERT_FIELD(KTHREAD, 0x0D8, SINGLE_LIST_ENTRY, SwapListEntry)
C_ASSERT_FIELD(KTHREAD, 0x0E8, DISPATCHER_HEADER*, Queue)
C_ASSERT_FIELD(KTHREAD, 0x0F0, PVOID, Teb)
C_ASSERT_FIELD(KTHREAD, 0x0F8, UINT64, RelativeTimerBias)
C_ASSERT_FIELD(KTHREAD, 0x100, KTIMER, Timer)
C_ASSERT_FIELD(KTHREAD, 0x140, KWAIT_BLOCK[4], WaitBlock)
C_ASSERT_FIELD(KTHREAD, 0x154, ULONG32, ContextSwitches)
C_ASSERT_FIELD(KTHREAD, 0x184, UINT8, State)
C_ASSERT_FIELD(KTHREAD, 0x185, CHAR, NpxState)
C_ASSERT_FIELD(KTHREAD, 0x186, UINT8, WaitIrql)
C_ASSERT_FIELD(KTHREAD, 0x187, CHAR, WaitMode)
C_ASSERT_FIELD(KTHREAD, 0x1B4, ULONG32, WaitTime)
C_ASSERT_FIELD(KTHREAD, 0x1E4, INT16, KernelApcDisable)
C_ASSERT_FIELD(KTHREAD, 0x1E6, INT16, SpecialApcDisable)
C_ASSERT_FIELD(KTHREAD, 0x1E4, ULONG32, CombinedApcDisable)
C_ASSERT_FIELD(KTHREAD, 0x168, KTHREAD_COUNTERS*, ThreadCounters)
C_ASSERT_FIELD(KTHREAD, 0x198, XSTATE_SAVE*, XStateSave)
C_ASSERT_FIELD(KTHREAD, 0x1C8, PVOID, Win32Thread)
C_ASSERT_FIELD(KTHREAD, 0x1F0, UMS_CONTROL_BLOCK*, Ucb)
C_ASSERT_FIELD(KTHREAD, 0x1F8, KUMS_CONTEXT_HEADER*, Uch)
C_ASSERT_FIELD(KTHREAD, 0x200, PVOID, TebMappedLowVa)
C_ASSERT_FIELD(KTHREAD, 0x208, LIST_ENTRY, QueueListEntry)
C_ASSERT_FIELD(KTHREAD, 0x218, ULONG32, NextProcessor)
C_ASSERT_FIELD(KTHREAD, 0x21C, LONG32, QueuePriority)
C_ASSERT_FIELD(KTHREAD, 0x220, KPROCESS*, Process)
C_ASSERT_FIELD(KTHREAD, 0x228, GROUP_AFFINITY, UserAffinity)
C_ASSERT_FIELD(KTHREAD, 0x232, CHAR, PreviousMode)
C_ASSERT_FIELD(KTHREAD, 0x233, CHAR, BasePriority)
C_ASSERT_FIELD(KTHREAD, 0x234, CHAR, PriorityDecrement)
C_ASSERT_FIELD(KTHREAD, 0x235, UINT8, Preempted)
C_ASSERT_FIELD(KTHREAD, 0x236, UINT8, AdjustReason)
C_ASSERT_FIELD(KTHREAD, 0x237, CHAR, AdjustIncrement)
C_ASSERT_FIELD(KTHREAD, 0x238, GROUP_AFFINITY, Affinity)
C_ASSERT_FIELD(KTHREAD, 0x242, UINT8, ApcStateIndex)
C_ASSERT_FIELD(KTHREAD, 0x243, UINT8, WaitBlockCount)
C_ASSERT_FIELD(KTHREAD, 0x244, ULONG32, IdealProcessor)
C_ASSERT_FIELD(KTHREAD, 0x248, KAPC_STATE*[2], ApcStatePointer)
C_ASSERT_FIELD(KTHREAD, 0x258, KAPC_STATE, SavedApcState)
C_ASSERT_FIELD(KTHREAD, 0x283, UINT8, WaitReason)
C_ASSERT_FIELD(KTHREAD, 0x284, CHAR, SuspendCount)
C_ASSERT_FIELD(KTHREAD, 0x285, CHAR, Saturation)
C_ASSERT_FIELD(KTHREAD, 0x286, UINT16, SListFaultCount)
C_ASSERT_FIELD(KTHREAD, 0x288, KAPC, SchedulerApc)
C_ASSERT_FIELD(KTHREAD, 0x289, UINT8, ResourceIndex)
C_ASSERT_FIELD(KTHREAD, 0x28B, UINT8, QuantumReset)
C_ASSERT_FIELD(KTHREAD, 0x28C, ULONG32, KernelTime)
C_ASSERT_FIELD(KTHREAD, 0x2C8, KPRCB*, WaitPrcb)
C_ASSERT_FIELD(KTHREAD, 0x2D0, PVOID, LegoData)
C_ASSERT_FIELD(KTHREAD, 0x2DB, UINT8, CallbackNestingLevel)
C_ASSERT_FIELD(KTHREAD, 0x2DC, ULONG32, UserTime)
C_ASSERT_FIELD(KTHREAD, 0x2E0, KEVENT, SuspendEvent)
C_ASSERT_FIELD(KTHREAD, 0x2F8, LIST_ENTRY, ThreadListEntry)
C_ASSERT_FIELD(KTHREAD, 0x308, LIST_ENTRY, MutantListHead)
C_ASSERT_FIELD(KTHREAD, 0x318, SINGLE_LIST_ENTRY, LockEntriesFreeList)
C_ASSERT_FIELD(KTHREAD, 0x320, KLOCK_ENTRY[6], LockEntries)
C_ASSERT_FIELD(KTHREAD, 0x560, SINGLE_LIST_ENTRY, PropagateBoostsEntry)
C_ASSERT_FIELD(KTHREAD, 0x568, SINGLE_LIST_ENTRY, IoSelfBoostsEntry)
C_ASSERT_FIELD(KTHREAD, 0x570, UINT8[16], PriorityFloorCounts)
C_ASSERT_FIELD(KTHREAD, 0x580, ULONG32, PriorityFloorSummary)
C_ASSERT_FIELD(KTHREAD, 0x584, LONG32, AbCompletedIoBoostCount)
C_ASSERT_FIELD(KTHREAD, 0x588, INT16, AbReferenceCount)
C_ASSERT_FIELD(KTHREAD, 0x58A, UINT8, AbFreeEntryCount)
C_ASSERT_FIELD(KTHREAD, 0x58B, UINT8, AbWaitEntryCount)
C_ASSERT_FIELD(KTHREAD, 0x58C, ULONG32, ForegroundLossTime)
C_ASSERT_FIELD(KTHREAD, 0x590, LIST_ENTRY, GlobalForegroundListEntry)
C_ASSERT_FIELD(KTHREAD, 0x590, SINGLE_LIST_ENTRY, ForegroundDpcStackListEntry)
C_ASSERT_FIELD(KTHREAD, 0x598, UINT64, InGlobalForegroundList)
C_ASSERT_FIELD(KTHREAD, 0x5A0, INT64, ReadOperationCount)
C_ASSERT_FIELD(KTHREAD, 0x5A8, INT64, WriteOperationCount)
C_ASSERT_FIELD(KTHREAD, 0x5B0, INT64, OtherOperationCount)
C_ASSERT_FIELD(KTHREAD, 0x5B8, INT64, ReadTransferCount)
C_ASSERT_FIELD(KTHREAD, 0x5C0, INT64, WriteTransferCount)
C_ASSERT_FIELD(KTHREAD, 0x5C8, INT64, OtherTransferCount)
