
add_definitions(-D__WINESRC__)
include_directories(${REACTOS_SOURCE_DIR}/sdk/include/reactos/wine)
spec2def(fltlib.dll fltlib.spec ADD_IMPORTLIB)

list(APPEND SOURCE
    fltlib.c
    stubs.c
    ${CMAKE_CURRENT_BINARY_DIR}/fltlib.def)

add_library(fltlib SHARED ${SOURCE} rsrc.rc)
set_module_type(fltlib win32dll)
target_link_libraries(fltlib wine)
add_importlibs(fltlib msvcrt kernel32 ntdll)
add_cd_file(TARGET fltlib DESTINATION reactos/system32 FOR all)
