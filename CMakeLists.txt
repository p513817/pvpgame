# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(PvpGame LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directory for headers
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set output directories for executables and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Gather all source files in src directory to build a library
file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Create a static library from src files
add_library(PvpGameLib STATIC ${SRC_FILES})

# Add each .cpp file in tests/ as a separate executable and link to PvpGameLib
file(GLOB CPP_FILES "${CMAKE_SOURCE_DIR}/tests/*.cpp")

foreach(CPP_FILE ${CPP_FILES})
    # Get the file name without the extension
    get_filename_component(EXEC_NAME ${CPP_FILE} NAME_WE)
    
    # Add executable for each .cpp file in tests directory
    add_executable(${EXEC_NAME} ${CPP_FILE})
    
    # Link the executable to the library
    target_link_libraries(${EXEC_NAME} PvpGameLib)
endforeach()
