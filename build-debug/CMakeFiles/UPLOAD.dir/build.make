# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/nick/project/CubeMX/Clion_MAX_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/project/CubeMX/Clion_MAX_test/build-debug

# Utility rule file for UPLOAD.

# Include the progress variables for this target.
include CMakeFiles/UPLOAD.dir/progress.make

CMakeFiles/UPLOAD:
	/home/nick/openocd/bin/openocd -s /home/nick/openocd/share/openocd/scripts -f board/stm32f429discovery_jlink_swd.cfg reset halt flash write_image unlock /home/nick/project/CubeMX/Clion_MAX_test/build-debug/Clion_MAX_test.bin reset halt reset run -iex disconnect -iex quit quit

UPLOAD: CMakeFiles/UPLOAD
UPLOAD: CMakeFiles/UPLOAD.dir/build.make

.PHONY : UPLOAD

# Rule to build all files generated by this target.
CMakeFiles/UPLOAD.dir/build: UPLOAD

.PHONY : CMakeFiles/UPLOAD.dir/build

CMakeFiles/UPLOAD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UPLOAD.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UPLOAD.dir/clean

CMakeFiles/UPLOAD.dir/depend:
	cd /home/nick/project/CubeMX/Clion_MAX_test/build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/project/CubeMX/Clion_MAX_test /home/nick/project/CubeMX/Clion_MAX_test /home/nick/project/CubeMX/Clion_MAX_test/build-debug /home/nick/project/CubeMX/Clion_MAX_test/build-debug /home/nick/project/CubeMX/Clion_MAX_test/build-debug/CMakeFiles/UPLOAD.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UPLOAD.dir/depend

