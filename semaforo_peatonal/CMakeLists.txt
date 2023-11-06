cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(semaforo_peatonal_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(semaforo_peatonal
semaforo_peatonal.c
)
# pico_enable_stdio_usb(semaforo_peatonal 1)
# pico_enable_stdio_uart(semaforo_peatonal 1)
pico_add_extra_outputs(semaforo_peatonal)
target_link_libraries(semaforo_peatonal pico_stdlib hardware_gpio pico_time)
