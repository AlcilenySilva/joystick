cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(joystick C CXX ASM)  # Alterado o nome do projeto

pico_sdk_init()

# Alterado o nome do executável e arquivo principal
add_executable(joystick main.c utils/wifi-connection/wifi-connect.c utils/send-data-to-server/send-data.c)

pico_set_program_name(joystick "joystick")  # Atualizado o nome do programa
pico_set_program_version(joystick "0.1")

pico_enable_stdio_uart(joystick 0)
pico_enable_stdio_usb(joystick 1)

# Atualizado todas as referências para o target joystick
target_link_libraries(joystick
    pico_stdlib
    pico_cyw43_arch_lwip_threadsafe_background
    hardware_adc
)

target_include_directories(joystick PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Removida a linha vazia de target_link_libraries (opcional)
# target_link_libraries(joystick)

pico_add_extra_outputs(joystick)