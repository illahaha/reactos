
list(APPEND SOURCE
    main.c
    negotiate.c
    ntlm.c
    schannel.c
    secur32.c
    testlist.c)

add_executable(secur32_winetest ${SOURCE})
set_module_type(secur32_winetest win32cui)
add_importlibs(secur32_winetest advapi32 ws2_32 msvcrt kernel32)
add_cd_file(TARGET secur32_winetest DESTINATION reactos/bin FOR all)
