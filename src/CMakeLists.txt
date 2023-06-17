cmake_minimum_required(VERSION 3.20)

project(teatime VERSION 1.0.0 LANGUAGES C CXX)


# ------------------------------------------------------------------------------------------------


# C/C++ standards and extensions setup

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# ------------------------------------------------------------------------------------------------


# build the libraries (LVGL, LittleFS and qcbor)

add_library(lvgl STATIC "")
add_subdirectory(libs)


# build the frontend

add_library(frontend STATIC "")
add_subdirectory(frontend)


# build the settings library

add_library(settings STATIC "")
add_subdirectory(settings)


# ------------------------------------------------------------------------------------------------


# The remainder of the compilation process depends on the VARIANT variable,
# which must be either "Firmware" or "Simulator".

if (VARIANT STREQUAL "Firmware")

elseif (VARIANT STREQUAL "Simulator")

    # add the SDL2 package
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED IMPORTED_TARGET sdl2)

    # build the backend mockup
    add_library(backend-mockup STATIC "")
    add_subdirectory(simulator/backend-mockup)

    # build the simulator executable
    add_executable(tt-sim "")
    target_sources(tt-sim
        PRIVATE
            simulator/main.cc
    )
    target_include_directories(tt-sim
        PUBLIC
            ${SDL2_INCLUDE_DIRS}
            .
            ..
            libs/lvgl
    )
    target_compile_options(tt-sim
        PUBLIC
            ${SDL2_CFLAGS_OTHER}
    )
    target_link_libraries(tt-sim
        PUBLIC
            PkgConfig::SDL2
            lvgl
            frontend
            settings
            backend-mockup
    )

else()
    message(FATAL_ERROR "You have to specify the VARIANT variable (Firmware or Simulator).")
endif()

