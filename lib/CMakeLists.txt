cmake_minimum_required(VERSION 3.22)
set(CMAKE_C_STANDARD 23)

project(libs C)

##### LIBRARIES #####
# loop trough all folders inside /lib
file(GLOB LIBS "*")

message(STATUS "Starting to build libraries...")
foreach (LIB ${LIBS})
    if (IS_DIRECTORY ${LIB} AND EXISTS ${LIB}/CMakeLists.txt)

        # get the name of the folder (is the name of the library)
        get_filename_component(LIB_NAME ${LIB} NAME)
        message(STATUS "${LIB_NAME}: ")

        # add the folder as a subdirectory.
        add_subdirectory(${LIB})

        # set the output directory of the library
        set_target_properties(${LIB_NAME}_static PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${LIB_NAME})
        message(STATUS "  - static library: ${LIB_NAME}_static")

        set_target_properties(${LIB_NAME}_shared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${LIB_NAME})
        message(STATUS "  - shared library: ${LIB_NAME}_shared")
    endif ()
endforeach ()