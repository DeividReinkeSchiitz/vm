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
include lib/rwe/CMakeFiles/rwe_shared.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/rwe/CMakeFiles/rwe_shared.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/rwe/CMakeFiles/rwe_shared.dir/progress.make

# Include the compile flags for this target's objects.
include lib/rwe/CMakeFiles/rwe_shared.dir/flags.make

lib/rwe/CMakeFiles/rwe_shared.dir/rwe.c.o: lib/rwe/CMakeFiles/rwe_shared.dir/flags.make
lib/rwe/CMakeFiles/rwe_shared.dir/rwe.c.o: /home/deivid/Source/vm/lib/rwe/rwe.c
lib/rwe/CMakeFiles/rwe_shared.dir/rwe.c.o: lib/rwe/CMakeFiles/rwe_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deivid/Source/vm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/rwe/CMakeFiles/rwe_shared.dir/rwe.c.o"
	cd /home/deivid/Source/vm/cmake-build-debug/lib/rwe && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/rwe/CMakeFiles/rwe_shared.dir/rwe.c.o -MF CMakeFiles/rwe_shared.dir/rwe.c.o.d -o CMakeFiles/rwe_shared.dir/rwe.c.o -c /home/deivid/Source/vm/lib/rwe/rwe.c

lib/rwe/CMakeFiles/rwe_shared.dir/rwe.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rwe_shared.dir/rwe.c.i"
	cd /home/deivid/Source/vm/cmake-build-debug/lib/rwe && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/deivid/Source/vm/lib/rwe/rwe.c > CMakeFiles/rwe_shared.dir/rwe.c.i

lib/rwe/CMakeFiles/rwe_shared.dir/rwe.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rwe_shared.dir/rwe.c.s"
	cd /home/deivid/Source/vm/cmake-build-debug/lib/rwe && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/deivid/Source/vm/lib/rwe/rwe.c -o CMakeFiles/rwe_shared.dir/rwe.c.s

# Object files for target rwe_shared
rwe_shared_OBJECTS = \
"CMakeFiles/rwe_shared.dir/rwe.c.o"

# External object files for target rwe_shared
rwe_shared_EXTERNAL_OBJECTS =

/home/deivid/Source/vm/lib/rwe/librwe_shared.so: lib/rwe/CMakeFiles/rwe_shared.dir/rwe.c.o
/home/deivid/Source/vm/lib/rwe/librwe_shared.so: lib/rwe/CMakeFiles/rwe_shared.dir/build.make
/home/deivid/Source/vm/lib/rwe/librwe_shared.so: lib/rwe/CMakeFiles/rwe_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/deivid/Source/vm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library /home/deivid/Source/vm/lib/rwe/librwe_shared.so"
	cd /home/deivid/Source/vm/cmake-build-debug/lib/rwe && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rwe_shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/rwe/CMakeFiles/rwe_shared.dir/build: /home/deivid/Source/vm/lib/rwe/librwe_shared.so
.PHONY : lib/rwe/CMakeFiles/rwe_shared.dir/build

lib/rwe/CMakeFiles/rwe_shared.dir/clean:
	cd /home/deivid/Source/vm/cmake-build-debug/lib/rwe && $(CMAKE_COMMAND) -P CMakeFiles/rwe_shared.dir/cmake_clean.cmake
.PHONY : lib/rwe/CMakeFiles/rwe_shared.dir/clean

lib/rwe/CMakeFiles/rwe_shared.dir/depend:
	cd /home/deivid/Source/vm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deivid/Source/vm /home/deivid/Source/vm/lib/rwe /home/deivid/Source/vm/cmake-build-debug /home/deivid/Source/vm/cmake-build-debug/lib/rwe /home/deivid/Source/vm/cmake-build-debug/lib/rwe/CMakeFiles/rwe_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/rwe/CMakeFiles/rwe_shared.dir/depend

