cmake_minimum_required(VERSION 3.22)
set(CMAKE_C_STANDARD 23)

include(../defaults.cmake)

# include dependencies of another libraries
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../log/liblog_static.a)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../sllist/libsllist_static.a)

project(${PROJECT_NAME} C)