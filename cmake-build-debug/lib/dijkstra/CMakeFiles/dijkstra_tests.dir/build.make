# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/deivid/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/deivid/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/deivid/Source/vm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deivid/Source/vm/cmake-build-debug

# Include any dependencies generated for this target.
include lib/dijkstra/CMakeFiles/dijkstra_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/dijkstra/CMakeFiles/dijkstra_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/dijkstra/CMakeFiles/dijkstra_tests.dir/progress.make

# Include the compile flags for this target's objects.
include lib/dijkstra/CMakeFiles/dijkstra_tests.dir/flags.make

lib/dijkstra/CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.o: lib/dijkstra/CMakeFiles/dijkstra_tests.dir/flags.make
lib/dijkstra/CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.o: /home/deivid/Source/vm/lib/dijkstra/tests/dijkstra_tests.cpp
lib/dijkstra/CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.o: lib/dijkstra/CMakeFiles/dijkstra_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deivid/Source/vm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/dijkstra/CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.o"
	cd /home/deivid/Source/vm/cmake-build-debug/lib/dijkstra && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/dijkstra/CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.o -MF CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.o.d -o CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.o -c /home/deivid/Source/vm/lib/dijkstra/tests/dijkstra_tests.cpp

lib/dijkstra/CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.i"
	cd /home/deivid/Source/vm/cmake-build-debug/lib/dijkstra && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deivid/Source/vm/lib/dijkstra/tests/dijkstra_tests.cpp > CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.i

lib/dijkstra/CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.s"
	cd /home/deivid/Source/vm/cmake-build-debug/lib/dijkstra && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deivid/Source/vm/lib/dijkstra/tests/dijkstra_tests.cpp -o CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.s

# Object files for target dijkstra_tests
dijkstra_tests_OBJECTS = \
"CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.o"

# External object files for target dijkstra_tests
dijkstra_tests_EXTERNAL_OBJECTS =

lib/dijkstra/dijkstra_tests: lib/dijkstra/CMakeFiles/dijkstra_tests.dir/tests/dijkstra_tests.cpp.o
lib/dijkstra/dijkstra_tests: lib/dijkstra/CMakeFiles/dijkstra_tests.dir/build.make
lib/dijkstra/dijkstra_tests: /home/deivid/Source/vm/lib/dijkstra/libdijkstra_shared.so
lib/dijkstra/dijkstra_tests: /home/deivid/Source/vm/lib/dijkstra/libdijkstra_static.a
lib/dijkstra/dijkstra_tests: /usr/lib/libgtest_main.so.1.14.0
lib/dijkstra/dijkstra_tests: /usr/lib/libgtest.so.1.14.0
lib/dijkstra/dijkstra_tests: lib/dijkstra/CMakeFiles/dijkstra_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/deivid/Source/vm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dijkstra_tests"
	cd /home/deivid/Source/vm/cmake-build-debug/lib/dijkstra && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dijkstra_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/dijkstra/CMakeFiles/dijkstra_tests.dir/build: lib/dijkstra/dijkstra_tests
.PHONY : lib/dijkstra/CMakeFiles/dijkstra_tests.dir/build

lib/dijkstra/CMakeFiles/dijkstra_tests.dir/clean:
	cd /home/deivid/Source/vm/cmake-build-debug/lib/dijkstra && $(CMAKE_COMMAND) -P CMakeFiles/dijkstra_tests.dir/cmake_clean.cmake
.PHONY : lib/dijkstra/CMakeFiles/dijkstra_tests.dir/clean

lib/dijkstra/CMakeFiles/dijkstra_tests.dir/depend:
	cd /home/deivid/Source/vm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deivid/Source/vm /home/deivid/Source/vm/lib/dijkstra /home/deivid/Source/vm/cmake-build-debug /home/deivid/Source/vm/cmake-build-debug/lib/dijkstra /home/deivid/Source/vm/cmake-build-debug/lib/dijkstra/CMakeFiles/dijkstra_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/dijkstra/CMakeFiles/dijkstra_tests.dir/depend

