cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(mic_vumetro_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(mic_vumetro
mic_vumetro.c
)
# pico_enable_stdio_usb(mic_vumetro 1)
# pico_enable_stdio_uart(mic_vumetro 1)
pico_add_extra_outputs(mic_vumetro)
target_link_libraries(mic_vumetro pico_stdlib hardware_adc hardware_gpio)
