cmake_minimum_required(VERSION 3.22)
set(CMAKE_C_STANDARD 23)
set(BINARY gitHub_webhook)

project(${BINARY} C)

set(EXTERNAL_INCLUDE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/../include)
set(HOME_INCLUDE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${EXTERNAL_INCLUDE_FOLDER} ${HOME_INCLUDE_FOLDER})

set(SOURCE_FILES
        ${BINARY}.c
        src/TCPServer_gitHub.c
        include/TCPServer_gitHub.h)

# if this option is enabled, the project will be built with the static library
option(RELEASE "Build shared libraries" OFF)

if (RELEASE)
    set(LIBRARY_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/TCPServer/libTCPServer_static.a
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/sllist/libsllist_static.a
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/JSON/libJSON_static.a
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/hmac/libhmac_static.a)
else ()
    set(LIBRARY_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/TCPServer/libTCPServer_shared.so
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/sllist/libsllist_shared.so
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/JSON/libJSON_shared.so
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/hmac/libhmac_shared.so)
endif ()

message(STATUS "Building ${BINARY} with ${LIBRARY_FILES}")

add_executable(${BINARY} ${SOURCE_FILES})
target_link_libraries(${BINARY} ${LIBRARY_FILES})

# set the output directory for the executable and create a copy in ${CMAKE_CURRENT_SOURCE_DIR}/../bin
set_target_properties(${BINARY} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_custom_command(TARGET ${BINARY} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${BINARY}> ${CMAKE_CURRENT_SOURCE_DIR}/../bin/${BINARY})
