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
include sorter_comp/CMakeFiles/order_comp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include sorter_comp/CMakeFiles/order_comp.dir/compiler_depend.make

# Include the progress variables for this target.
include sorter_comp/CMakeFiles/order_comp.dir/progress.make

# Include the compile flags for this target's objects.
include sorter_comp/CMakeFiles/order_comp.dir/flags.make

sorter_comp/CMakeFiles/order_comp.dir/src/order_comp.c.o: sorter_comp/CMakeFiles/order_comp.dir/flags.make
sorter_comp/CMakeFiles/order_comp.dir/src/order_comp.c.o: /home/deivid/Source/vm/sorter_comp/src/order_comp.c
sorter_comp/CMakeFiles/order_comp.dir/src/order_comp.c.o: sorter_comp/CMakeFiles/order_comp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deivid/Source/vm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sorter_comp/CMakeFiles/order_comp.dir/src/order_comp.c.o"
	cd /home/deivid/Source/vm/cmake-build-debug/sorter_comp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT sorter_comp/CMakeFiles/order_comp.dir/src/order_comp.c.o -MF CMakeFiles/order_comp.dir/src/order_comp.c.o.d -o CMakeFiles/order_comp.dir/src/order_comp.c.o -c /home/deivid/Source/vm/sorter_comp/src/order_comp.c

sorter_comp/CMakeFiles/order_comp.dir/src/order_comp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/order_comp.dir/src/order_comp.c.i"
	cd /home/deivid/Source/vm/cmake-build-debug/sorter_comp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/deivid/Source/vm/sorter_comp/src/order_comp.c > CMakeFiles/order_comp.dir/src/order_comp.c.i

sorter_comp/CMakeFiles/order_comp.dir/src/order_comp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/order_comp.dir/src/order_comp.c.s"
	cd /home/deivid/Source/vm/cmake-build-debug/sorter_comp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/deivid/Source/vm/sorter_comp/src/order_comp.c -o CMakeFiles/order_comp.dir/src/order_comp.c.s

# Object files for target order_comp
order_comp_OBJECTS = \
"CMakeFiles/order_comp.dir/src/order_comp.c.o"

# External object files for target order_comp
order_comp_EXTERNAL_OBJECTS =

/home/deivid/Source/vm/sorter_comp/bin/order_comp: sorter_comp/CMakeFiles/order_comp.dir/src/order_comp.c.o
/home/deivid/Source/vm/sorter_comp/bin/order_comp: sorter_comp/CMakeFiles/order_comp.dir/build.make
/home/deivid/Source/vm/sorter_comp/bin/order_comp: /home/deivid/Source/vm/sorter_comp/../lib/avl/libavl_shared.so
/home/deivid/Source/vm/sorter_comp/bin/order_comp: /home/deivid/Source/vm/sorter_comp/../lib/heap/libheap_shared.so
/home/deivid/Source/vm/sorter_comp/bin/order_comp: /home/deivid/Source/vm/sorter_comp/../lib/bst/libbst_shared.so
/home/deivid/Source/vm/sorter_comp/bin/order_comp: sorter_comp/CMakeFiles/order_comp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/deivid/Source/vm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable /home/deivid/Source/vm/sorter_comp/bin/order_comp"
	cd /home/deivid/Source/vm/cmake-build-debug/sorter_comp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/order_comp.dir/link.txt --verbose=$(VERBOSE)
	cd /home/deivid/Source/vm/cmake-build-debug/sorter_comp && /home/deivid/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E copy /home/deivid/Source/vm/sorter_comp/bin/order_comp /home/deivid/Source/vm/sorter_comp/../bin/order_comp

# Rule to build all files generated by this target.
sorter_comp/CMakeFiles/order_comp.dir/build: /home/deivid/Source/vm/sorter_comp/bin/order_comp
.PHONY : sorter_comp/CMakeFiles/order_comp.dir/build

sorter_comp/CMakeFiles/order_comp.dir/clean:
	cd /home/deivid/Source/vm/cmake-build-debug/sorter_comp && $(CMAKE_COMMAND) -P CMakeFiles/order_comp.dir/cmake_clean.cmake
.PHONY : sorter_comp/CMakeFiles/order_comp.dir/clean

sorter_comp/CMakeFiles/order_comp.dir/depend:
	cd /home/deivid/Source/vm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deivid/Source/vm /home/deivid/Source/vm/sorter_comp /home/deivid/Source/vm/cmake-build-debug /home/deivid/Source/vm/cmake-build-debug/sorter_comp /home/deivid/Source/vm/cmake-build-debug/sorter_comp/CMakeFiles/order_comp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sorter_comp/CMakeFiles/order_comp.dir/depend

