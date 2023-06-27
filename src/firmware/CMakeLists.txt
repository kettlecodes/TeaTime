cmake_minimum_required(VERSION 3.20)


# set the prefix for the firmware output files
set(FIRMWARE_FILE_PREFIX "teatime")


# check if ARM cross-compilation toolkit path has been specified
if (DEFINED ARM_NONE_EABI_TOOLCHAIN_PATH)
    set(ARM_NONE_EABI_TOOLCHAIN_BIN_PATH ${ARM_NONE_EABI_TOOLCHAIN_PATH}/bin)
else()
    message(FATAL_ERROR "You have to specify the ARM_NONE_EABI_TOOLCHAIN_PATH variable!")
endif()

# check if NRF5 SDK path has been specified
if (NOT DEFINED NRF5_SDK_PATH)
    message(FATAL_ERROR "You have to specify the NRF5_SDK_PATH variable!")
endif()

# set up ARM toolchain
message("Including ARM toolchain: ${CMAKE_SOURCE_DIR}/firmware/arm-gcc-toolchain.cmake")
include(${CMAKE_SOURCE_DIR}/firmware/arm-gcc-toolchain.cmake)
message("C Compiler: ${CMAKE_C_COMPILER}")

# set common flags
set(COMMON_FLAGS
    -MP
    -MD
    -mthumb
    -mabi=aapcs
    -ftree-vrp
    -ffunction-sections
    -fdata-sections
    -fno-strict-aliasing
    -fno-builtin
    -fshort-enums
    -mcpu=cortex-m4
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
    -fstack-usage
    -fno-exceptions
    -fno-non-call-exceptions
)

# set warning flags
set(WARNING_FLAGS
    -Wall
    -Wextra
    -Warray-bounds=2
    -Wformat=2
    -Wformat-overflow=2
    -Wformat-truncation=2
    -Wformat-nonliteral
    -Wno-missing-field-initializers
    -Wno-unknown-pragmas
    -Wno-expansion-to-defined
    -Wreturn-type
    -Werror=return-type
    -Werror
)

# some more compiler flags
set(RELEASE_FLAGS -Os)
set(CXX_FLAGS -fno-rtti)
set(ASM_FLAGS -x assembler-with-cpp)

# add the definitions
add_definitions(
    -DCONFIG_GPIO_AS_PINRESET
    -DNIMBLE_CFG_CONTROLLER
    -DOS_CPUTIME_FREQ
    -DNRF52
    -DNRF52832
    -DNRF52832_XXAA
    -DNRF52_PAN_74
    -DNRF52_PAN_64
    -DNRF52_PAN_12
    -DNRF52_PAN_58
    -DNRF52_PAN_54
    -DNRF52_PAN_31
    -DNRF52_PAN_51
    -DNRF52_PAN_36
    -DNRF52_PAN_15
    -DNRF52_PAN_20
    -DNRF52_PAN_55
    -DBOARD_PCA10040
    -DFREERTOS
    -D__STACK_SIZE=1024
    -D__HEAP_SIZE=0
    -DMYNEWT_VAL_BLE_LL_RFMGMT_ENABLE_TIME=1500
    -DTARGET_DEVICE_PINETIME
    -DTARGET_DEVICE_NAME="PINETIME"
    -DDRIVER_PINMAP_PINETIME
    -DCLOCK_CONFIG_LF_SRC=1
)


# ---  NRF SDK  ----------------------------------------------------------------------------------


add_library(nrf-sdk
    STATIC 
        "${NRF5_SDK_PATH}/modules/nrfx/mdk/system_nrf52.c"
        "${NRF5_SDK_PATH}/modules/nrfx/mdk/gcc_startup_nrf52.S"
        "${NRF5_SDK_PATH}/components/boards/boards.c"
        "${NRF5_SDK_PATH}/integration/nrfx/legacy/nrf_drv_clock.c"
        "${NRF5_SDK_PATH}/integration/nrfx/legacy/nrf_drv_clock.h"
        "${NRF5_SDK_PATH}/modules/nrfx/drivers/src/nrfx_clock.c"
        "${NRF5_SDK_PATH}/modules/nrfx/drivers/src/nrfx_gpiote.c"
        "${NRF5_SDK_PATH}/modules/nrfx/soc/nrfx_atomic.c"
        "${NRF5_SDK_PATH}/modules/nrfx/drivers/src/nrfx_saadc.c"
        "${NRF5_SDK_PATH}/external/freertos/source/croutine.c"
        "${NRF5_SDK_PATH}/external/freertos/source/event_groups.c"
        "${NRF5_SDK_PATH}/external/freertos/source/list.c"
        "${NRF5_SDK_PATH}/external/freertos/source/queue.c"
        "${NRF5_SDK_PATH}/external/freertos/source/stream_buffer.c"
        "${NRF5_SDK_PATH}/external/freertos/source/tasks.c"
        "${NRF5_SDK_PATH}/external/freertos/source/timers.c"
        "${NRF5_SDK_PATH}/components/libraries/atomic/nrf_atomic.c"
        "${NRF5_SDK_PATH}/components/libraries/balloc/nrf_balloc.c"
        "${NRF5_SDK_PATH}/components/libraries/util/nrf_assert.c"
        "${NRF5_SDK_PATH}/components/libraries/util/app_error.c"
        "${NRF5_SDK_PATH}/components/libraries/util/app_error_weak.c"
        "${NRF5_SDK_PATH}/components/libraries/util/app_error_handler_gcc.c"
        "${NRF5_SDK_PATH}/components/libraries/util/app_util_platform.c"
        "${NRF5_SDK_PATH}/components/libraries/log/src/nrf_log_backend_rtt.c"
        "${NRF5_SDK_PATH}/components/libraries/log/src/nrf_log_backend_serial.c"
        "${NRF5_SDK_PATH}/components/libraries/log/src/nrf_log_default_backends.c"
        "${NRF5_SDK_PATH}/components/libraries/log/src/nrf_log_frontend.c"
        "${NRF5_SDK_PATH}/components/libraries/log/src/nrf_log_str_formatter.c"
        "${NRF5_SDK_PATH}/components/libraries/memobj/nrf_memobj.c"
        "${NRF5_SDK_PATH}/components/libraries/ringbuf/nrf_ringbuf.c"
        "${NRF5_SDK_PATH}/components/libraries/strerror/nrf_strerror.c"
        "${NRF5_SDK_PATH}/external/segger_rtt/SEGGER_RTT_Syscalls_GCC.c"
        "${NRF5_SDK_PATH}/external/segger_rtt/SEGGER_RTT.c"
        "${NRF5_SDK_PATH}/external/segger_rtt/SEGGER_RTT_printf.c"
        "${NRF5_SDK_PATH}/external/utf_converter/utf.c"
        "${NRF5_SDK_PATH}/external/fprintf/nrf_fprintf.c"
        "${NRF5_SDK_PATH}/external/fprintf/nrf_fprintf_format.c"
        "${NRF5_SDK_PATH}/modules/nrfx/drivers/src/nrfx_twim.c"
        "${NRF5_SDK_PATH}/components/libraries/gpiote/app_gpiote.c"
)

target_include_directories(nrf-sdk
    SYSTEM PUBLIC
        "${CMAKE_SOURCE_DIR}/firmware"
        "${CMAKE_SOURCE_DIR}/firmware/FreeRTOS"
        "${NRF5_SDK_PATH}/components/toolchain/cmsis/include"
        "${NRF5_SDK_PATH}/components/libraries/util"
        "${NRF5_SDK_PATH}/components/libraries/log"
        "${NRF5_SDK_PATH}/components/libraries/log/src"
        "${NRF5_SDK_PATH}/components/libraries/strerror"
        "${NRF5_SDK_PATH}/components/libraries/balloc"
        "${NRF5_SDK_PATH}/components/libraries/atomic"
        "${NRF5_SDK_PATH}/components/libraries/experimental_section_vars"
        "${NRF5_SDK_PATH}/components/drivers_nrf/nrf_soc_nosd"
        "${NRF5_SDK_PATH}/modules/nrfx"
        "${NRF5_SDK_PATH}/modules/nrfx/hal"
        "${NRF5_SDK_PATH}/modules/nrfx/mdk"
        "${NRF5_SDK_PATH}/modules/nrfx/drivers/include"
        "${NRF5_SDK_PATH}/integration/nrfx"
        "${NRF5_SDK_PATH}/integration/nrfx/legacy"
        "${NRF5_SDK_PATH}/external/freertos/source/include"
)

target_compile_options(nrf-sdk
    PRIVATE
        ${COMMON_FLAGS}
        $<$<CONFIG:DEBUG>: ${DEBUG_FLAGS}>
        $<$<CONFIG:RELEASE>: ${RELEASE_FLAGS}>
        $<$<COMPILE_LANGUAGE:CXX>: ${CXX_FLAGS}>
        $<$<COMPILE_LANGUAGE:ASM>: ${ASM_FLAGS}>
        -O3
)


# ---  Nimble  -----------------------------------------------------------------------------------


add_library(nimble
    STATIC
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/npl/freertos/src/nimble_port_freertos.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/npl/freertos/src/npl_os_freertos.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_hci_evt.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_l2cap_sig_cmd.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_l2cap_sig.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_l2cap.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_mbuf.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_sm.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_sm_cmd.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_sm_lgcy.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_sm_alg.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_sm_sc.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_gap.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_gatts.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_gattc.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_conn.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_att_svr.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_store.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_store_util.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_pvcy.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_hci.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_log.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_hci_util.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_hci_cmd.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_cfg.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_uuid.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_id.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_misc.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_att.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_att_clt.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_att_svr.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_att_cmd.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_atomic.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_adv.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_flow.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_mqueue.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_stop.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_hs_startup.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/store/ram/src/ble_store_ram.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/src/ble_monitor.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/transport/ram/src/ble_hci_ram.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_rand.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_conn.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_ctrl.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_hci.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_conn_hci.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_utils.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_scan.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_whitelist.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_adv.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_sched.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_supp_cmd.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_hci_ev.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_rfmgmt.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/src/ble_ll_resolv.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/nimble/src/os_cputime.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/nimble/src/os_cputime_pwr2.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/nimble/src/os_mbuf.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/nimble/src/os_mempool.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/nimble/src/hal_timer.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/nimble/src/mem.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/nimble/src/endian.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/nimble/src/os_msys_init.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/drivers/nrf52/src/ble_hw.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/drivers/nrf52/src/ble_phy.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/services/gap/src/ble_svc_gap.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/services/gatt/src/ble_svc_gatt.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/util/src/addr.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/ext/tinycrypt/src/aes_encrypt.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/ext/tinycrypt/src/utils.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/ext/tinycrypt/src/cmac_mode.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/ext/tinycrypt/src/ecc.c"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/ext/tinycrypt/src/ecc_dh.c"
)

target_include_directories(nimble
    SYSTEM PUBLIC
        "${CMAKE_SOURCE_DIR}/firmware"
        "${CMAKE_SOURCE_DIR}/firmware/FreeRTOS"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/include"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/include"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/store/ram/include"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/services/gap/include"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/services/gatt/include"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/host/util/include"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/controller/include"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/transport/ram/include"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/nimble/drivers/nrf52/include"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/nimble/include"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/porting/npl/freertos/include"
        "${CMAKE_SOURCE_DIR}/libs/mynewt-nimble/ext/tinycrypt/include"
        "${NRF5_SDK_PATH}/components/toolchain/cmsis/include"
        "${NRF5_SDK_PATH}/components/libraries/util"
        "${NRF5_SDK_PATH}/components/drivers_nrf/nrf_soc_nosd"
        "${NRF5_SDK_PATH}/modules/nrfx"
        "${NRF5_SDK_PATH}/modules/nrfx/mdk"
        "${NRF5_SDK_PATH}/modules/nrfx/drivers/include"
        "${NRF5_SDK_PATH}/integration/nrfx"
        "${NRF5_SDK_PATH}/external/freertos/source/include"
        "${NRF5_SDK_PATH}/external/segger_rtt"
)

target_compile_options(nimble
    PRIVATE
        ${COMMON_FLAGS}
        $<$<CONFIG:DEBUG>: ${DEBUG_FLAGS}>
        $<$<CONFIG:RELEASE>: ${RELEASE_FLAGS}>
        $<$<COMPILE_LANGUAGE:CXX>: ${CXX_FLAGS}>
        $<$<COMPILE_LANGUAGE:ASM>: ${ASM_FLAGS}>
)


# ---  LVGL  -------------------------------------------------------------------------------------


add_library(lvgl STATIC "")

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/libs
    ${CMAKE_CURRENT_BINARY_DIR}/libs
)

target_include_directories(lvgl
    SYSTEM PUBLIC
        "${CMAKE_SOURCE_DIR}/firmware"
        "${CMAKE_SOURCE_DIR}/firmware/FreeRTOS"
        "${NRF5_SDK_PATH}/components/toolchain/cmsis/include"
        "${NRF5_SDK_PATH}/components/libraries/util"
        "${NRF5_SDK_PATH}/components/drivers_nrf/nrf_soc_nosd"
        "${NRF5_SDK_PATH}/modules/nrfx/mdk"
        "${NRF5_SDK_PATH}/external/freertos/source/include"
)

target_compile_options(lvgl
    PRIVATE
        ${COMMON_FLAGS}
        $<$<CONFIG:DEBUG>: ${DEBUG_FLAGS}>
        $<$<CONFIG:RELEASE>: ${RELEASE_FLAGS}>
        $<$<COMPILE_LANGUAGE:CXX>: ${CXX_FLAGS}>
        $<$<COMPILE_LANGUAGE:ASM>: ${ASM_FLAGS}>
)


# ---  LittleFS  ---------------------------------------------------------------------------------


add_library(littlefs
    STATIC
        "${CMAKE_SOURCE_DIR}/libs/littlefs/lfs_util.c"
        "${CMAKE_SOURCE_DIR}/libs/littlefs/lfs.c"
)

target_compile_options(littlefs
    PRIVATE
        ${COMMON_FLAGS}
        $<$<CONFIG:DEBUG>: ${DEBUG_FLAGS}>
        $<$<CONFIG:RELEASE>: ${RELEASE_FLAGS}>
        $<$<COMPILE_LANGUAGE:CXX>: ${CXX_FLAGS}>
        $<$<COMPILE_LANGUAGE:ASM>: ${ASM_FLAGS}>
)


# ---  QCBOR  ------------------------------------------------------------------------------------


add_library(QCBOR
    STATIC
        "${CMAKE_SOURCE_DIR}/libs/QCBOR/src/ieee754.c"
        "${CMAKE_SOURCE_DIR}/libs/QCBOR/src/qcbor_decode.c"
        "${CMAKE_SOURCE_DIR}/libs/QCBOR/src/qcbor_encode.c"
        "${CMAKE_SOURCE_DIR}/libs/QCBOR/src/qcbor_err_to_str.c"
        "${CMAKE_SOURCE_DIR}/libs/QCBOR/src/UsefulBuf.c"
)

target_include_directories(QCBOR
    SYSTEM PUBLIC
        "${CMAKE_SOURCE_DIR}/libs/QCBOR/inc"
)

target_compile_definitions(QCBOR
    PUBLIC
        QCBOR_DISABLE_FLOAT_HW_USE
        QCBOR_DISABLE_PREFERRED_FLOAT
        QCBOR_DISABLE_EXP_AND_MANTISSA
        QCBOR_DISABLE_INDEFINITE_LENGTH_STRINGS
        QCBOR_DISABLE_UNCOMMON_TAGS
        USEFULBUF_CONFIG_LITTLE_ENDIAN
)

set_target_properties(QCBOR
    PROPERTIES
        LINKER_LANGUAGE C
)

target_compile_options(QCBOR
    PRIVATE
        ${COMMON_FLAGS}
        $<$<CONFIG:DEBUG>: ${DEBUG_FLAGS}>
        $<$<CONFIG:RELEASE>: ${RELEASE_FLAGS}>
        $<$<COMPILE_LANGUAGE:ASM>: ${ASM_FLAGS}>
        -O3
)


# ---  Frontend  ---------------------------------------------------------------------------------


add_library(frontend STATIC "")

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/frontend
    ${CMAKE_CURRENT_BINARY_DIR}/frontend
)

target_compile_options(frontend
    PUBLIC
        ${COMMON_FLAGS}
        ${WARNING_FLAGS}
        $<$<CONFIG:DEBUG>: ${DEBUG_FLAGS}>
        $<$<CONFIG:RELEASE>: ${RELEASE_FLAGS}>
        $<$<COMPILE_LANGUAGE:CXX>: ${CXX_FLAGS}>
)


# ---  Frontend  ---------------------------------------------------------------------------------


add_library(settings STATIC "")

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/settings
    ${CMAKE_CURRENT_BINARY_DIR}/settings
)

target_compile_options(settings
    PUBLIC
        ${COMMON_FLAGS}
        ${WARNING_FLAGS}
        $<$<CONFIG:DEBUG>: ${DEBUG_FLAGS}>
        $<$<CONFIG:RELEASE>: ${RELEASE_FLAGS}>
        $<$<COMPILE_LANGUAGE:CXX>: ${CXX_FLAGS}>
)


# ---  Autonomous binary without bootloader support  ---------------------------------------------


# set(EXECUTABLE_NAME      "${FIRMWARE_FILE_PREFIX}-app")
# set(EXECUTABLE_FILE_NAME "${EXECUTABLE_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
# set(NRF5_LINKER_SCRIPT   "${CMAKE_SOURCE_DIR}/firmware/gcc_nrf52.ld")
# 
# set(APP_LINK_FLAGS
#     -mthumb
#     -mabi=aapcs
#     -L ${NRF5_SDK_PATH}/modules/nrfx/mdk
#     -T${NRF5_LINKER_SCRIPT}
#     -mcpu=cortex-m4
#     -mfloat-abi=hard
#     -mfpu=fpv4-sp-d16
#     -Wl,--gc-sections
#     -Wl,--print-memory-usage --specs=nano.specs
#     -lc
#     -lnosys
#     -lm
#     -Wl,-Map="${EXECUTABLE_FILE_NAME}.map"
# )
# 
# add_executable(${EXECUTABLE_NAME}
#     # source files...
# )
# 
# target_link_libraries(${EXECUTABLE_NAME}
#     nimble
#     nrf-sdk
#     lvgl
#     littlefs
#     QCBOR
#     frontend
#     settings
# )
# 
# target_compile_options(${EXECUTABLE_NAME}
#     PUBLIC
#         ${COMMON_FLAGS}
#         ${WARNING_FLAGS}
#         $<$<CONFIG:DEBUG>: ${DEBUG_FLAGS}>
#         $<$<CONFIG:RELEASE>: ${RELEASE_FLAGS}>
#         $<$<COMPILE_LANGUAGE:CXX>: ${CXX_FLAGS}>
#         $<$<COMPILE_LANGUAGE:ASM>: ${ASM_FLAGS}>
# )
# 
# set_target_properties(${EXECUTABLE_NAME}
#     PROPERTIES
#         OUTPUT_NAME "${EXECUTABLE_FILE_NAME}"
#         SUFFIX      ".out"
#         LINK_FLAGS  "${APP_LINK_FLAGS}"
# )
# 
# add_custom_command(TARGET ${EXECUTABLE_NAME}
#     POST_BUILD
#     COMMAND ${CMAKE_SIZE_UTIL} ${EXECUTABLE_FILE_NAME}.out
#     COMMAND ${CMAKE_OBJCOPY} -O binary ${EXECUTABLE_FILE_NAME}.out "${EXECUTABLE_FILE_NAME}.bin"
#     COMMAND ${CMAKE_OBJCOPY} -O ihex   ${EXECUTABLE_FILE_NAME}.out "${EXECUTABLE_FILE_NAME}.hex"
#     COMMENT "post build steps for ${EXECUTABLE_FILE_NAME}"
# )
