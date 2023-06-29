target_sources(backend-mockup
    PRIVATE
        MockupBackend.cc
        MockupBattery.cc
        MockupBluetooth.cc
        MockupDateTime.cc
        MockupDisplay.cc
        MockupFirmwareValidation.cc
        MockupMotion.cc
        MockupWatchdog.cc
)

target_include_directories(backend-mockup
    PUBLIC
        .
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/libs
)
