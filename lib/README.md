## LIB CREATION

1. Create a folder with the library name in the /lib folder.
2. Create a CMakeLists.txt file in the library folder. The default CMakeLists.txt file is:

```cmake
# You can head this example in the lib lib/log/log.c file

cmake_minimum_required(VERSION 3.22)

include(../defaults.cmake)

project(${PROJECT_NAME} C)

# If your application need to use the another library, include dependencies here:
#target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../log/liblog_static.a)
#target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../d_structs/libd_structs_static.a)
```

3. Create a main file with the library name in the library folder.
4. Create a header file with the library name in the include folder on /include.
5. Create a test folder in the library folder. The test folder must have a
   .cpp file with the library name concated with _test. Ex: log_tests.cpp. the default
   code of the test file is:

```cpp
extern "C"
{
    //#include "libname.h"
}

#include <gtest/gtest.h>
#include <iostream>

TEST(LogTest, LogTest)
{
    EXPECT_TRUE(true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

6. Create a Build folder in the library folder.
   Inside it, you can run: `cmake --build ../ && make` in your terminal. This will
   create a static and a shared library in the library folder and an executable
   in the bin builder folder. The executable will run the tests. You can run
   the executable with `./libname_tests` in your terminal.
7. Check if the library is working properly using valgrind. Inside build dolfer you can run:

8. `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./libname_tests`

### Libraries Default Settings

All libraries must respect this following project structures (based on unix standards):

* Header files are in global /include/libname.h folder
* Source files in /lib/libname/ folder.
* Each library have his own
    * Main file /lib/libname/libname.c.
    * CMakeLists.txt file in /lib/libname/CMakeLists.txt.
    * test folders in /lib/libname/tests/.
        * CMakeLists.txt file in /lib/libname/tests/CMakeLists.txt.
        * Test files in /lib/libname/tests/test_libname.cpp.
    * Internal header files in /lib/libname/internal.h.
    * Static libname_static.a file in /lib/libname/libname_static.a.
    * Shared libname_shared.so file in /lib/libname/libname_shared.so.