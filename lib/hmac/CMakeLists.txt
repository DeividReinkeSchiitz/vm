cmake_minimum_required(VERSION 3.22)

# include openssl
find_package(OpenSSL REQUIRED)
link_libraries(${OPENSSL_LIBRARIES})

include(../defaults.cmake)

project(${PROJECT_NAME} C)

