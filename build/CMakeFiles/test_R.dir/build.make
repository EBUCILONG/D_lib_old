# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib/build

# Include any dependencies generated for this target.
include CMakeFiles/test_R.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_R.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_R.dir/flags.make

CMakeFiles/test_R.dir/apps/test_R.cpp.o: CMakeFiles/test_R.dir/flags.make
CMakeFiles/test_R.dir/apps/test_R.cpp.o: ../apps/test_R.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_R.dir/apps/test_R.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_R.dir/apps/test_R.cpp.o -c /Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib/apps/test_R.cpp

CMakeFiles/test_R.dir/apps/test_R.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_R.dir/apps/test_R.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib/apps/test_R.cpp > CMakeFiles/test_R.dir/apps/test_R.cpp.i

CMakeFiles/test_R.dir/apps/test_R.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_R.dir/apps/test_R.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib/apps/test_R.cpp -o CMakeFiles/test_R.dir/apps/test_R.cpp.s

# Object files for target test_R
test_R_OBJECTS = \
"CMakeFiles/test_R.dir/apps/test_R.cpp.o"

# External object files for target test_R
test_R_EXTERNAL_OBJECTS =

test_R: CMakeFiles/test_R.dir/apps/test_R.cpp.o
test_R: CMakeFiles/test_R.dir/build.make
test_R: CMakeFiles/test_R.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_R"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_R.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_R.dir/build: test_R

.PHONY : CMakeFiles/test_R.dir/build

CMakeFiles/test_R.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_R.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_R.dir/clean

CMakeFiles/test_R.dir/depend:
	cd /Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib /Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib /Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib/build /Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib/build /Users/oruqimaru/Desktop/PHD/CPP_item/past_version/D_lib/build/CMakeFiles/test_R.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_R.dir/depend

