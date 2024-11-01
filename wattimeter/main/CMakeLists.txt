idf_component_register(SRCS "wattimeter.c"
                            "esp32_drivers/adc/adc.c"
                            "application/app.c"
                            "application/acs712.c"
                            "application/voltage.c"
                    INCLUDE_DIRS "." 
                                 "esp32_drivers/adc" 
                                 "application")
