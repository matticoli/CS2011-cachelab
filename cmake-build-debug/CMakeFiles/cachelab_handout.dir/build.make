# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/CS2011/cachelab-handout

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/CS2011/cachelab-handout/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cachelab_handout.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cachelab_handout.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cachelab_handout.dir/flags.make

CMakeFiles/cachelab_handout.dir/cachelab.c.o: CMakeFiles/cachelab_handout.dir/flags.make
CMakeFiles/cachelab_handout.dir/cachelab.c.o: ../cachelab.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2011/cachelab-handout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cachelab_handout.dir/cachelab.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cachelab_handout.dir/cachelab.c.o   -c /home/student/CS2011/cachelab-handout/cachelab.c

CMakeFiles/cachelab_handout.dir/cachelab.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cachelab_handout.dir/cachelab.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/CS2011/cachelab-handout/cachelab.c > CMakeFiles/cachelab_handout.dir/cachelab.c.i

CMakeFiles/cachelab_handout.dir/cachelab.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cachelab_handout.dir/cachelab.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/CS2011/cachelab-handout/cachelab.c -o CMakeFiles/cachelab_handout.dir/cachelab.c.s

CMakeFiles/cachelab_handout.dir/cachelab.c.o.requires:

.PHONY : CMakeFiles/cachelab_handout.dir/cachelab.c.o.requires

CMakeFiles/cachelab_handout.dir/cachelab.c.o.provides: CMakeFiles/cachelab_handout.dir/cachelab.c.o.requires
	$(MAKE) -f CMakeFiles/cachelab_handout.dir/build.make CMakeFiles/cachelab_handout.dir/cachelab.c.o.provides.build
.PHONY : CMakeFiles/cachelab_handout.dir/cachelab.c.o.provides

CMakeFiles/cachelab_handout.dir/cachelab.c.o.provides.build: CMakeFiles/cachelab_handout.dir/cachelab.c.o


CMakeFiles/cachelab_handout.dir/csim.c.o: CMakeFiles/cachelab_handout.dir/flags.make
CMakeFiles/cachelab_handout.dir/csim.c.o: ../csim.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2011/cachelab-handout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cachelab_handout.dir/csim.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cachelab_handout.dir/csim.c.o   -c /home/student/CS2011/cachelab-handout/csim.c

CMakeFiles/cachelab_handout.dir/csim.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cachelab_handout.dir/csim.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/CS2011/cachelab-handout/csim.c > CMakeFiles/cachelab_handout.dir/csim.c.i

CMakeFiles/cachelab_handout.dir/csim.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cachelab_handout.dir/csim.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/CS2011/cachelab-handout/csim.c -o CMakeFiles/cachelab_handout.dir/csim.c.s

CMakeFiles/cachelab_handout.dir/csim.c.o.requires:

.PHONY : CMakeFiles/cachelab_handout.dir/csim.c.o.requires

CMakeFiles/cachelab_handout.dir/csim.c.o.provides: CMakeFiles/cachelab_handout.dir/csim.c.o.requires
	$(MAKE) -f CMakeFiles/cachelab_handout.dir/build.make CMakeFiles/cachelab_handout.dir/csim.c.o.provides.build
.PHONY : CMakeFiles/cachelab_handout.dir/csim.c.o.provides

CMakeFiles/cachelab_handout.dir/csim.c.o.provides.build: CMakeFiles/cachelab_handout.dir/csim.c.o


CMakeFiles/cachelab_handout.dir/test-trans.c.o: CMakeFiles/cachelab_handout.dir/flags.make
CMakeFiles/cachelab_handout.dir/test-trans.c.o: ../test-trans.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2011/cachelab-handout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cachelab_handout.dir/test-trans.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cachelab_handout.dir/test-trans.c.o   -c /home/student/CS2011/cachelab-handout/test-trans.c

CMakeFiles/cachelab_handout.dir/test-trans.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cachelab_handout.dir/test-trans.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/CS2011/cachelab-handout/test-trans.c > CMakeFiles/cachelab_handout.dir/test-trans.c.i

CMakeFiles/cachelab_handout.dir/test-trans.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cachelab_handout.dir/test-trans.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/CS2011/cachelab-handout/test-trans.c -o CMakeFiles/cachelab_handout.dir/test-trans.c.s

CMakeFiles/cachelab_handout.dir/test-trans.c.o.requires:

.PHONY : CMakeFiles/cachelab_handout.dir/test-trans.c.o.requires

CMakeFiles/cachelab_handout.dir/test-trans.c.o.provides: CMakeFiles/cachelab_handout.dir/test-trans.c.o.requires
	$(MAKE) -f CMakeFiles/cachelab_handout.dir/build.make CMakeFiles/cachelab_handout.dir/test-trans.c.o.provides.build
.PHONY : CMakeFiles/cachelab_handout.dir/test-trans.c.o.provides

CMakeFiles/cachelab_handout.dir/test-trans.c.o.provides.build: CMakeFiles/cachelab_handout.dir/test-trans.c.o


CMakeFiles/cachelab_handout.dir/tracegen.c.o: CMakeFiles/cachelab_handout.dir/flags.make
CMakeFiles/cachelab_handout.dir/tracegen.c.o: ../tracegen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2011/cachelab-handout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cachelab_handout.dir/tracegen.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cachelab_handout.dir/tracegen.c.o   -c /home/student/CS2011/cachelab-handout/tracegen.c

CMakeFiles/cachelab_handout.dir/tracegen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cachelab_handout.dir/tracegen.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/CS2011/cachelab-handout/tracegen.c > CMakeFiles/cachelab_handout.dir/tracegen.c.i

CMakeFiles/cachelab_handout.dir/tracegen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cachelab_handout.dir/tracegen.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/CS2011/cachelab-handout/tracegen.c -o CMakeFiles/cachelab_handout.dir/tracegen.c.s

CMakeFiles/cachelab_handout.dir/tracegen.c.o.requires:

.PHONY : CMakeFiles/cachelab_handout.dir/tracegen.c.o.requires

CMakeFiles/cachelab_handout.dir/tracegen.c.o.provides: CMakeFiles/cachelab_handout.dir/tracegen.c.o.requires
	$(MAKE) -f CMakeFiles/cachelab_handout.dir/build.make CMakeFiles/cachelab_handout.dir/tracegen.c.o.provides.build
.PHONY : CMakeFiles/cachelab_handout.dir/tracegen.c.o.provides

CMakeFiles/cachelab_handout.dir/tracegen.c.o.provides.build: CMakeFiles/cachelab_handout.dir/tracegen.c.o


CMakeFiles/cachelab_handout.dir/trans.c.o: CMakeFiles/cachelab_handout.dir/flags.make
CMakeFiles/cachelab_handout.dir/trans.c.o: ../trans.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CS2011/cachelab-handout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/cachelab_handout.dir/trans.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cachelab_handout.dir/trans.c.o   -c /home/student/CS2011/cachelab-handout/trans.c

CMakeFiles/cachelab_handout.dir/trans.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cachelab_handout.dir/trans.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/CS2011/cachelab-handout/trans.c > CMakeFiles/cachelab_handout.dir/trans.c.i

CMakeFiles/cachelab_handout.dir/trans.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cachelab_handout.dir/trans.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/CS2011/cachelab-handout/trans.c -o CMakeFiles/cachelab_handout.dir/trans.c.s

CMakeFiles/cachelab_handout.dir/trans.c.o.requires:

.PHONY : CMakeFiles/cachelab_handout.dir/trans.c.o.requires

CMakeFiles/cachelab_handout.dir/trans.c.o.provides: CMakeFiles/cachelab_handout.dir/trans.c.o.requires
	$(MAKE) -f CMakeFiles/cachelab_handout.dir/build.make CMakeFiles/cachelab_handout.dir/trans.c.o.provides.build
.PHONY : CMakeFiles/cachelab_handout.dir/trans.c.o.provides

CMakeFiles/cachelab_handout.dir/trans.c.o.provides.build: CMakeFiles/cachelab_handout.dir/trans.c.o


# Object files for target cachelab_handout
cachelab_handout_OBJECTS = \
"CMakeFiles/cachelab_handout.dir/cachelab.c.o" \
"CMakeFiles/cachelab_handout.dir/csim.c.o" \
"CMakeFiles/cachelab_handout.dir/test-trans.c.o" \
"CMakeFiles/cachelab_handout.dir/tracegen.c.o" \
"CMakeFiles/cachelab_handout.dir/trans.c.o"

# External object files for target cachelab_handout
cachelab_handout_EXTERNAL_OBJECTS =

cachelab_handout: CMakeFiles/cachelab_handout.dir/cachelab.c.o
cachelab_handout: CMakeFiles/cachelab_handout.dir/csim.c.o
cachelab_handout: CMakeFiles/cachelab_handout.dir/test-trans.c.o
cachelab_handout: CMakeFiles/cachelab_handout.dir/tracegen.c.o
cachelab_handout: CMakeFiles/cachelab_handout.dir/trans.c.o
cachelab_handout: CMakeFiles/cachelab_handout.dir/build.make
cachelab_handout: CMakeFiles/cachelab_handout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/CS2011/cachelab-handout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable cachelab_handout"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cachelab_handout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cachelab_handout.dir/build: cachelab_handout

.PHONY : CMakeFiles/cachelab_handout.dir/build

CMakeFiles/cachelab_handout.dir/requires: CMakeFiles/cachelab_handout.dir/cachelab.c.o.requires
CMakeFiles/cachelab_handout.dir/requires: CMakeFiles/cachelab_handout.dir/csim.c.o.requires
CMakeFiles/cachelab_handout.dir/requires: CMakeFiles/cachelab_handout.dir/test-trans.c.o.requires
CMakeFiles/cachelab_handout.dir/requires: CMakeFiles/cachelab_handout.dir/tracegen.c.o.requires
CMakeFiles/cachelab_handout.dir/requires: CMakeFiles/cachelab_handout.dir/trans.c.o.requires

.PHONY : CMakeFiles/cachelab_handout.dir/requires

CMakeFiles/cachelab_handout.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cachelab_handout.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cachelab_handout.dir/clean

CMakeFiles/cachelab_handout.dir/depend:
	cd /home/student/CS2011/cachelab-handout/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/CS2011/cachelab-handout /home/student/CS2011/cachelab-handout /home/student/CS2011/cachelab-handout/cmake-build-debug /home/student/CS2011/cachelab-handout/cmake-build-debug /home/student/CS2011/cachelab-handout/cmake-build-debug/CMakeFiles/cachelab_handout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cachelab_handout.dir/depend

