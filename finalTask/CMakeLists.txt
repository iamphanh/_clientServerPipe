add_definitions(-D_HAS_STD_BYTE=0)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

cmake_minimum_required(VERSION 3.10)

include_directories(Header)

file(GLOB SOURCES "Srouce/*.cc")

find_library(WINAPI_LIBRARY_NAME 
    NAMES kernel32 user32 gdi32 ws2_32.lib ws2_32
    PATHS ${CMAKE_SOURCE_DIR}/lib/winapi)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /level='requireAdministrator'")
add_executable(CMakeProject1 ${SOURCES})
target_link_libraries(CMakeProject1 ${WINAPI_LIBRARY_NAME})
install(TARGETS CMakeProject1 DESTINATION "cmakeproject1")