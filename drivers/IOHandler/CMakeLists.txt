cmake_minimum_required(VERSION 3.5)

set(SOURCES IOHandler.cpp)

idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS .
    REQUIRES driver
)
