#!/bin/bash

len=$#

if [ $len -eq 1 ]; then
	NOMBRE_PROYECTO=$1
	mkdir $NOMBRE_PROYECTO
	cd "$1"
	touch $NOMBRE_PROYECTO.c
	echo "cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project($NOMBRE_PROYECTO""_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable($NOMBRE_PROYECTO
$NOMBRE_PROYECTO.c
)
pico_enable_stdio_usb($NOMBRE_PROYECTO 1)
pico_enable_stdio_uart($NOMBRE_PROYECTO 1)
pico_add_extra_outputs($NOMBRE_PROYECTO)
target_link_libraries($NOMBRE_PROYECTO pico_stdlib)" >> CMakeLists.txt
	cp $PICO_SDK_PATH/external/pico_sdk_import.cmake .
	mkdir build
fi
