# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/zpw/software/clion/clion-2019.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zpw/software/clion/clion-2019.2.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/odom_calib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/odom_calib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/odom_calib.dir/flags.make

CMakeFiles/odom_calib.dir/odom_calib.cpp.o: CMakeFiles/odom_calib.dir/flags.make
CMakeFiles/odom_calib.dir/odom_calib.cpp.o: ../odom_calib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/odom_calib.dir/odom_calib.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/odom_calib.dir/odom_calib.cpp.o -c /home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib/odom_calib.cpp

CMakeFiles/odom_calib.dir/odom_calib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/odom_calib.dir/odom_calib.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib/odom_calib.cpp > CMakeFiles/odom_calib.dir/odom_calib.cpp.i

CMakeFiles/odom_calib.dir/odom_calib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/odom_calib.dir/odom_calib.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib/odom_calib.cpp -o CMakeFiles/odom_calib.dir/odom_calib.cpp.s

# Object files for target odom_calib
odom_calib_OBJECTS = \
"CMakeFiles/odom_calib.dir/odom_calib.cpp.o"

# External object files for target odom_calib
odom_calib_EXTERNAL_OBJECTS =

../odom_calib: CMakeFiles/odom_calib.dir/odom_calib.cpp.o
../odom_calib: CMakeFiles/odom_calib.dir/build.make
../odom_calib: CMakeFiles/odom_calib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../odom_calib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/odom_calib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/odom_calib.dir/build: ../odom_calib

.PHONY : CMakeFiles/odom_calib.dir/build

CMakeFiles/odom_calib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/odom_calib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/odom_calib.dir/clean

CMakeFiles/odom_calib.dir/depend:
	cd /home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib /home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib /home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib/cmake-build-debug /home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib/cmake-build-debug /home/zpw/github/SLAM/Laser_Slam/ch02/odom_calib/cmake-build-debug/CMakeFiles/odom_calib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/odom_calib.dir/depend

