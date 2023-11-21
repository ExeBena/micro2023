cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(lcd_1602_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(lcd_1602
lcd_1602.c
)
add_subdirectory(lcd_lib)
# pico_enable_stdio_usb(lcd_1602 1)
# pico_enable_stdio_uart(lcd_1602 1)
pico_add_extra_outputs(lcd_1602)
target_link_libraries(lcd_1602 pico_stdlib lcd_lib hardware_i2c)
