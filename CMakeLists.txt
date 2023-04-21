cmake_minimum_required(VERSION 3.22)
project(vm C)

set(CMAKE_C_STANDARD 23)

##### LIBRARIES #####
# loop trough all folders inside /lib
file(GLOB LIBS "lib/*")

message(STATUS "Starting to build libraries...")
foreach (LIB ${LIBS})
    if (IS_DIRECTORY ${LIB})
        # get the name of the folder
        get_filename_component(LIB_NAME ${LIB} NAME)
        message(STATUS "${LIB_NAME}: ")

        # add the folder as a subdirectory
        add_subdirectory(${LIB})

        # set the output directory of the library
        set_target_properties(${LIB_NAME}_static PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${LIB_NAME})
        message(STATUS "  - static library: ${LIB_NAME}_static")

        set_target_properties(${LIB_NAME}_shared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${LIB_NAME})
        message(STATUS "  - shared library: ${LIB_NAME}_shared")
    endif ()
endforeach ()

#### EXECUTABLE #####
message(STATUS "Starting to build executables...")
add_subdirectory(./gitHub_webhook)
