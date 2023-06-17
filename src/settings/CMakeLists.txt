target_sources(settings
    PRIVATE
        Settings.cc
)

target_include_directories(settings
    PUBLIC
        .
        ${CMAKE_SOURCE_DIR}
)