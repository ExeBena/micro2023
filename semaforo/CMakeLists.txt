cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(semaforo_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(semaforo
semaforo.c
)
pico_enable_stdio_usb(semaforo 0)
pico_enable_stdio_uart(semaforo 0)
pico_add_extra_outputs(semaforo)
target_link_libraries(semaforo pico_stdlib pico_time)
