cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(control_servo_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(control_servo
control_servo.c
)
# pico_enable_stdio_usb(control_servo 1)
# pico_enable_stdio_uart(control_servo 1)
pico_add_extra_outputs(control_servo)
target_link_libraries(control_servo pico_stdlib hardware_gpio hardware_pwm pico_time)
