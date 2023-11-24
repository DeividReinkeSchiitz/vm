cmake_minimum_required(VERSION 3.22)
set(CMAKE_C_STANDARD 23)
set(BINARY cep_reader)

project(${BINARY} C)

### LIBRARIES ###
add_subdirectory(./lib)

##### INCLUDE THE HEADER FILES ###
set(HOME_INCLUDE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/include)

#set(EXTERNAL_INCLUDE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/../include)
include_directories(${HOME_INCLUDE_FOLDER})

### ALL THE SOURCE FILES ###
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c ${BINARY}.c)
set(SOURCE_FILES ${SOURCE_FILES})

### ENABLE RELEASE ###
# if this option is enabled, the project will be built with the static library
option(RELEASE "Build shared libraries" OFF)

# check if RELEASE is enabled. If it is, link the static libraries, otherwise link the shared libraries
# to use RELEASE, run cmake with the -DRELEASE=ON flag
if (RELEASE)
    set(LIBRARY_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/cep_avl/libcep_avl_static.a
    )
else ()
    set(LIBRARY_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/cep_avl/libcep_avl_shared.so
    )
endif ()
message(STATUS "Building ${BINARY} with ${LIBRARY_FILES}")

### BUILD THE EXECUTABLE ###
add_executable(${BINARY} ${SOURCE_FILES})

### LINK THE LIBRARIES ###
target_link_libraries(${BINARY} ${LIBRARY_FILES})

# set the output directory for the executable and create a copy in ${CMAKE_CURRENT_SOURCE_DIR}/../bin
set_target_properties(${BINARY} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_custom_command(TARGET ${BINARY} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${BINARY}> ${CMAKE_CURRENT_SOURCE_DIR}/../bin/${BINARY})