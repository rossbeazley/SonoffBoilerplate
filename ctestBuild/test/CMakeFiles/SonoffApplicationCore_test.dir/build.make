# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rdlb/programing/arduino/SonoffBoilerplate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild

# Include any dependencies generated for this target.
include test/CMakeFiles/SonoffApplicationCore_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/SonoffApplicationCore_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/SonoffApplicationCore_test.dir/flags.make

test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o: test/CMakeFiles/SonoffApplicationCore_test.dir/flags.make
test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o: ../src/SonoffApplicationCore.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o"
	cd /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o -c /home/rdlb/programing/arduino/SonoffBoilerplate/src/SonoffApplicationCore.cpp

test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.i"
	cd /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rdlb/programing/arduino/SonoffBoilerplate/src/SonoffApplicationCore.cpp > CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.i

test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.s"
	cd /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rdlb/programing/arduino/SonoffBoilerplate/src/SonoffApplicationCore.cpp -o CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.s

test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o.requires:

.PHONY : test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o.requires

test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o.provides: test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/SonoffApplicationCore_test.dir/build.make test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o.provides.build
.PHONY : test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o.provides

test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o.provides.build: test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o


test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o: test/CMakeFiles/SonoffApplicationCore_test.dir/flags.make
test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o: ../test/SonoffApplicationCore.t.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o"
	cd /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o -c /home/rdlb/programing/arduino/SonoffBoilerplate/test/SonoffApplicationCore.t.cpp

test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.i"
	cd /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rdlb/programing/arduino/SonoffBoilerplate/test/SonoffApplicationCore.t.cpp > CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.i

test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.s"
	cd /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rdlb/programing/arduino/SonoffBoilerplate/test/SonoffApplicationCore.t.cpp -o CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.s

test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o.requires:

.PHONY : test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o.requires

test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o.provides: test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/SonoffApplicationCore_test.dir/build.make test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o.provides.build
.PHONY : test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o.provides

test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o.provides.build: test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o


# Object files for target SonoffApplicationCore_test
SonoffApplicationCore_test_OBJECTS = \
"CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o" \
"CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o"

# External object files for target SonoffApplicationCore_test
SonoffApplicationCore_test_EXTERNAL_OBJECTS =

test/SonoffApplicationCore_test: test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o
test/SonoffApplicationCore_test: test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o
test/SonoffApplicationCore_test: test/CMakeFiles/SonoffApplicationCore_test.dir/build.make
test/SonoffApplicationCore_test: test/libarduinostub.a
test/SonoffApplicationCore_test: test/CMakeFiles/SonoffApplicationCore_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SonoffApplicationCore_test"
	cd /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SonoffApplicationCore_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/SonoffApplicationCore_test.dir/build: test/SonoffApplicationCore_test

.PHONY : test/CMakeFiles/SonoffApplicationCore_test.dir/build

test/CMakeFiles/SonoffApplicationCore_test.dir/requires: test/CMakeFiles/SonoffApplicationCore_test.dir/__/src/SonoffApplicationCore.cpp.o.requires
test/CMakeFiles/SonoffApplicationCore_test.dir/requires: test/CMakeFiles/SonoffApplicationCore_test.dir/SonoffApplicationCore.t.cpp.o.requires

.PHONY : test/CMakeFiles/SonoffApplicationCore_test.dir/requires

test/CMakeFiles/SonoffApplicationCore_test.dir/clean:
	cd /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/test && $(CMAKE_COMMAND) -P CMakeFiles/SonoffApplicationCore_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/SonoffApplicationCore_test.dir/clean

test/CMakeFiles/SonoffApplicationCore_test.dir/depend:
	cd /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rdlb/programing/arduino/SonoffBoilerplate /home/rdlb/programing/arduino/SonoffBoilerplate/test /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/test /home/rdlb/programing/arduino/SonoffBoilerplate/ctestBuild/test/CMakeFiles/SonoffApplicationCore_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/SonoffApplicationCore_test.dir/depend

