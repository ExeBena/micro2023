cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(TEMPLATE_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(TEMPLATE
TEMPLATE.c
)
pico_enable_stdio_usb(TEMPLATE 1)
pico_enable_stdio_uart(TEMPLATE 1)
pico_add_extra_outputs(TEMPLATE)
target_link_libraries(TEMPLATE pico_stdlib)
