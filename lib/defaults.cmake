cmake_minimum_required(VERSION 3.22)
set(CMAKE_C_STANDARD 23)

project(defaults.cmake)

# save .a and .so to main directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../)

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

# create shared and static libraries
add_library(${PROJECT_NAME}_shared SHARED ${SOURCE_FILES})
add_library(${PROJECT_NAME}_static STATIC ${SOURCE_FILES})

# Include the header files
target_include_directories(${PROJECT_NAME}_shared PUBLIC ../../include)
target_include_directories(${PROJECT_NAME}_static PUBLIC ../../include)

########## TESTS ##########
# get google libraries to use in tests
file(GLOB GOOGLE_LIBRARIES ${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/googletest/build/lib/*.a)

# get shared library to use in tests
set(SHARED_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/lib${PROJECT_NAME}_shared.so)

# join all libraries
set(LIBRARIES_FILES ${GOOGLE_LIBRARIES} ${SHARED_LIBRARY})

# create test executable
set(EXECUTABLE_NAME ${PROJECT_NAME}_tests)
add_executable(${EXECUTABLE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/tests/${EXECUTABLE_NAME}.cpp)

# link test executable with libraries
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARIES_FILES})

# include external headers in test executable
target_include_directories(${EXECUTABLE_NAME} PUBLIC
        ${INCLUDE_FOLDER}
        ${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/googletest/googletest/include)