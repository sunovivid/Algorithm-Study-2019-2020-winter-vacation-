# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/divide_and_conquer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/divide_and_conquer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/divide_and_conquer.dir/flags.make

CMakeFiles/divide_and_conquer.dir/main.cpp.obj: CMakeFiles/divide_and_conquer.dir/flags.make
CMakeFiles/divide_and_conquer.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/divide_and_conquer.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\divide_and_conquer.dir\main.cpp.obj -c "C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer\main.cpp"

CMakeFiles/divide_and_conquer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/divide_and_conquer.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer\main.cpp" > CMakeFiles\divide_and_conquer.dir\main.cpp.i

CMakeFiles/divide_and_conquer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/divide_and_conquer.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer\main.cpp" -o CMakeFiles\divide_and_conquer.dir\main.cpp.s

# Object files for target divide_and_conquer
divide_and_conquer_OBJECTS = \
"CMakeFiles/divide_and_conquer.dir/main.cpp.obj"

# External object files for target divide_and_conquer
divide_and_conquer_EXTERNAL_OBJECTS =

divide_and_conquer.exe: CMakeFiles/divide_and_conquer.dir/main.cpp.obj
divide_and_conquer.exe: CMakeFiles/divide_and_conquer.dir/build.make
divide_and_conquer.exe: CMakeFiles/divide_and_conquer.dir/linklibs.rsp
divide_and_conquer.exe: CMakeFiles/divide_and_conquer.dir/objects1.rsp
divide_and_conquer.exe: CMakeFiles/divide_and_conquer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable divide_and_conquer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\divide_and_conquer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/divide_and_conquer.dir/build: divide_and_conquer.exe

.PHONY : CMakeFiles/divide_and_conquer.dir/build

CMakeFiles/divide_and_conquer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\divide_and_conquer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/divide_and_conquer.dir/clean

CMakeFiles/divide_and_conquer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer" "C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer" "C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer\cmake-build-debug" "C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer\cmake-build-debug" "C:\Users\Study_and_Dev\OneDrive - KoreaUniv\notKoreaUniv\Algorithm\freshmen winter vacation algorithm study\divide and conquer\cmake-build-debug\CMakeFiles\divide_and_conquer.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/divide_and_conquer.dir/depend
