cmake_minimum_required(VERSION 3.22)
set(CMAKE_C_STANDARD 23)
set(BINARY order_comp)

project(${BINARY} C)

# Include the header files
set(EXTERNAL_INCLUDE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/../include)
set(HOME_INCLUDE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${EXTERNAL_INCLUDE_FOLDER} ${HOME_INCLUDE_FOLDER})

# Include the .c files
# all file inside the src folder will be included
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
set(SOURCE_FILES ${SOURCE_FILES} )

# if this option is enabled, the project will be built with the static library
option(RELEASE "Build shared libraries" OFF)

# check if RELEASE is enabled. If it is, link the static libraries, otherwise link the shared libraries
# to use RELEASE, run cmake with the -DRELEASE=ON flag
if (RELEASE)
    set(LIBRARY_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/avl/libavl_static.a
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/heap/libheap_static.a
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/bst/libbst_static.a)
else ()
    set(LIBRARY_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/avl/libavl_shared.so
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/heap/libheap_shared.so
            ${CMAKE_CURRENT_SOURCE_DIR}/../lib/bst/libbst_shared.so)
endif ()
message(STATUS "Building ${BINARY} with ${LIBRARY_FILES}")

# create the executable
add_executable(${BINARY} ${SOURCE_FILES})

# link the executable with the libraries
target_link_libraries(${BINARY} ${LIBRARY_FILES})

# set the output directory for the executable and create a copy in ${CMAKE_CURRENT_SOURCE_DIR}/../bin
set_target_properties(${BINARY} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_custom_command(TARGET ${BINARY} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${BINARY}> ${CMAKE_CURRENT_SOURCE_DIR}/../bin/${BINARY})