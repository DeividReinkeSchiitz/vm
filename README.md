#### OBS

if you change the machine, change the LOG_FOLDER inside the log.c file

### INSTALATION

`
sudo apt-get install g++ cmake clang-format valgrind libssl-dev
`

### CLANG-FORMAT

`
clang-format -i -style=file src/*.c src/*/*.c src/*/*.h main.c
`

### RUN

Each library or executable have a build folder. Inside it run:

`
cmake --build ../ && make
`

### Valgrind

`
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./Default
`

### Packages

`
sudo apt-get install g++ cmake clang-format valgrind libssl-dev
`

### Executables Default Settings

All executables must respect this following structures:

* Bust be in the root folder of the project. Ex: gitHub_webhook/
* Must have a main file named with the executable name. Ex: gitHub_webhook.c
* If it had others .c files, they must be in a folder named src. Ex: gitHub_webhook/src/
* If it had others .h files, they must be in a folder named include. Ex: gitHub_webhook/include/
* In gitHub_webhook/bin have the executable file.
* Must be added to the CMakeLists.txt file manually:

```cmake
##### EXECUTABLE #####
add_subdirectory(./gitHub_webhook)
```

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
    * Static libname_static.a file in /lib/libname/libname_static.a.
    * Shared libname_shared.so file in /lib/libname/libname_shared.so.

You can read more about this in the [CMakeLists.txt](./lib/README.md) file.
