cmake_minimum_required(VERSION 3.20)

project(teatime VERSION 1.0.0 LANGUAGES C CXX ASM)


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


# get the git commit hash
set(PROJECT_GIT_COMMIT_HASH "")
execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE PROJECT_GIT_COMMIT_HASH
    RESULT_VARIABLE PROJECT_GIT_COMMIT_HASH_SUCCESS
)
string(STRIP
    "${PROJECT_GIT_COMMIT_HASH}"
    PROJECT_GIT_COMMIT_HASH
)
message("Git hash: ${PROJECT_GIT_COMMIT_HASH}")

# create the Version.h include file
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Version.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/Version.h
)
message("Created Version.h in ${CMAKE_CURRENT_BINARY_DIR}")


# ------------------------------------------------------------------------------------------------


# The remainder of the compilation process depends on the VARIANT variable,
# which must be either "Firmware" or "Simulator".

if (VARIANT STREQUAL "Firmware")

    add_subdirectory(firmware)

elseif (VARIANT STREQUAL "Simulator")

    # add the SDL2 package
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED IMPORTED_TARGET sdl2)

    # add the submodule libraries (LVGL, LittleFS and qcbor)
    add_library(lvgl STATIC "")
    add_subdirectory(libs)
    target_compile_options(lvgl
        PUBLIC
            "-DBUILD_SIMULATOR"
    )

    # add the frontend
    add_library(frontend STATIC "")
    add_subdirectory(frontend)

    # add the settings library
    add_library(settings STATIC "")
    add_subdirectory(settings)

    # add the backend mockup
    add_library(backend-mockup STATIC "")
    add_subdirectory(simulator/backend-mockup)

    # add the simulator executable
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

