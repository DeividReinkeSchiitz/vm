cmake_minimum_required(VERSION 3.22)
project(vm C)

set(CMAKE_C_STANDARD 23)

##### LIBRARIES #####
add_subdirectory(./lib)

#### EXECUTABLE #####
message(STATUS "Starting to build executables...")

#add_subdirectory(./gitHub_webhook)
add_subdirectory(./sorter_comp)
add_subdirectory(./cep_reader)
