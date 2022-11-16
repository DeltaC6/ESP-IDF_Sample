cmake_minimum_required(VERSION 3.5)

set(
    SOURCES
        ./main.cpp
        ./App.cpp
)

idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS .
    REQUIRES
        # Add all ESP related components here
        esp_common

        # FREERTOS
        freertos

        # User libraries here
        IOHandler
)
