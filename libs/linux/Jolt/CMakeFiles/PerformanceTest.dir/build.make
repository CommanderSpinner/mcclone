# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hui/Downloads/JoltPhysics-master/Build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hui/Downloads/JoltPhysics-master/Build/Linux_BUILD_TYPE=Release

# Include any dependencies generated for this target.
include CMakeFiles/PerformanceTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PerformanceTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PerformanceTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PerformanceTest.dir/flags.make

CMakeFiles/PerformanceTest.dir/codegen:
.PHONY : CMakeFiles/PerformanceTest.dir/codegen

CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.o: CMakeFiles/PerformanceTest.dir/flags.make
CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.o: /home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp
CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.o: CMakeFiles/PerformanceTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hui/Downloads/JoltPhysics-master/Build/Linux_BUILD_TYPE=Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.o -MF CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.o.d -o CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.o -c /home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp

CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp > CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.i

CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp -o CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.s

# Object files for target PerformanceTest
PerformanceTest_OBJECTS = \
"CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.o"

# External object files for target PerformanceTest
PerformanceTest_EXTERNAL_OBJECTS =

PerformanceTest: CMakeFiles/PerformanceTest.dir/home/hui/Downloads/JoltPhysics-master/PerformanceTest/PerformanceTest.cpp.o
PerformanceTest: CMakeFiles/PerformanceTest.dir/build.make
PerformanceTest: CMakeFiles/PerformanceTest.dir/compiler_depend.ts
PerformanceTest: libJolt.a
PerformanceTest: CMakeFiles/PerformanceTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/hui/Downloads/JoltPhysics-master/Build/Linux_BUILD_TYPE=Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PerformanceTest"
	/usr/bin/cmake -E copy_directory /home/hui/Downloads/JoltPhysics-master/Build/..//Assets/ /home/hui/Downloads/JoltPhysics-master/Build/Linux_BUILD_TYPE=Release/Assets/
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PerformanceTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PerformanceTest.dir/build: PerformanceTest
.PHONY : CMakeFiles/PerformanceTest.dir/build

CMakeFiles/PerformanceTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PerformanceTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PerformanceTest.dir/clean

CMakeFiles/PerformanceTest.dir/depend:
	cd /home/hui/Downloads/JoltPhysics-master/Build/Linux_BUILD_TYPE=Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hui/Downloads/JoltPhysics-master/Build /home/hui/Downloads/JoltPhysics-master/Build /home/hui/Downloads/JoltPhysics-master/Build/Linux_BUILD_TYPE=Release /home/hui/Downloads/JoltPhysics-master/Build/Linux_BUILD_TYPE=Release /home/hui/Downloads/JoltPhysics-master/Build/Linux_BUILD_TYPE=Release/CMakeFiles/PerformanceTest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/PerformanceTest.dir/depend

