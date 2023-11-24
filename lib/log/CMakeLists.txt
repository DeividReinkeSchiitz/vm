cmake_minimum_required(VERSION 3.22)
include(../defaults.cmake)

project(${PROJECT_NAME} C)

#add_executable(test_log ./tests/tests.cpp)
#
## include libraries in test executable
#file(GLOB LIBRARIES_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/googletest/build/lib/*.a ${CMAKE_CURRENT_SOURCE_DIR}/liblog_shared.so)
#target_link_libraries(test_log PUBLIC ${LIBRARIES_FILES})
#
## include external headers in test executable
#target_include_directories(test_log PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/../../include
#        ${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/googletest/googletest/include)