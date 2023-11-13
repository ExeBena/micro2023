cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(adc_vumetro_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(adc_vumetro
adc_vumetro.c
)
# pico_enable_stdio_usb(adc_vumetro 1)
# pico_enable_stdio_uart(adc_vumetro 1)
pico_add_extra_outputs(adc_vumetro)
target_link_libraries(adc_vumetro pico_stdlib hardware_adc hardware_gpio)
