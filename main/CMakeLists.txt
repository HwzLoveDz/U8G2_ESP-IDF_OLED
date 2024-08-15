idf_component_register(SRCS 
                                "u8g2_esp32_hal.c"
#                                "example/ssd1306_i2c_staticbuff.c"
                                "example/ssd1306_i2c_dynamicbuff.c"

                        INCLUDE_DIRS 
                                "."
                        )

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
