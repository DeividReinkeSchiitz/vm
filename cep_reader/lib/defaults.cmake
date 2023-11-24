cmake_minimum_required(VERSION 3.22)
set(CMAKE_C_STANDARD 23)

project(defaults.cmake C CXX)

##### EXTERNAL VENDORS #####
find_package(GTest REQUIRED)
if (NOT GTEST_FOUND)
    message(FATAL_ERROR "GTest not found!")
endif ()

#  get name of folder containing the file
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(INCLUDE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

## set all files terminated with .c and .h
file(GLOB
        SOURCE_FILES
        ./*.c ./*.h
        ./src/*.c
        ./include/*.h
        ${INCLUDE_FOLDER}/${PROJECT_NAME}.h)


# save .a and .so to main directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# create shared and static libraries
add_library(${PROJECT_NAME}_static STATIC ${SOURCE_FILES})
add_library(${PROJECT_NAME}_shared SHARED ${SOURCE_FILES})

# Include the header files
target_include_directories(${PROJECT_NAME}_shared PUBLIC ../../include)
target_include_directories(${PROJECT_NAME}_static PUBLIC ../../include)

########## TESTS ##########
# get shared library to use in tests
set(SHARED_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/lib${PROJECT_NAME}_shared.so)
# get static library to use in tests
set(STATIC_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/lib${PROJECT_NAME}_static.a)

# join all libraries
set(LIBRARIES_FILES  ${SHARED_LIBRARY} ${STATIC_LIBRARY} ${GTEST_BOTH_LIBRARIES})

# create test executable
set(EXECUTABLE_NAME ${PROJECT_NAME}_tests)
add_executable(${EXECUTABLE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/tests/${EXECUTABLE_NAME}.cpp)

# link test executable with libraries
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARIES_FILES} )

## add dependency from test executable to static library
add_dependencies(${EXECUTABLE_NAME} ${PROJECT_NAME}_shared ${PROJECT_NAME}_static)

# include external headers in test executable
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${INCLUDE_FOLDER} GTest::Gtest)