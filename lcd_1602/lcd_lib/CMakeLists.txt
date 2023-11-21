add_library(lcd_lib STATIC 
    lcd_lib.h
    lcd_lib.c)

target_include_directories(lcd_lib PUBLIC
${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(lcd_lib hardware_i2c)