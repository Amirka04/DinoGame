# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = "/home/amirka/Рабочий стол/C++/DinoGame"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/amirka/Рабочий стол/C++/DinoGame/build"

# Include any dependencies generated for this target.
include CMakeFiles/Textures.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Textures.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Textures.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Textures.dir/flags.make

CMakeFiles/Textures.dir/Textures/Textures.cpp.o: CMakeFiles/Textures.dir/flags.make
CMakeFiles/Textures.dir/Textures/Textures.cpp.o: ../Textures/Textures.cpp
CMakeFiles/Textures.dir/Textures/Textures.cpp.o: CMakeFiles/Textures.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/amirka/Рабочий стол/C++/DinoGame/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Textures.dir/Textures/Textures.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Textures.dir/Textures/Textures.cpp.o -MF CMakeFiles/Textures.dir/Textures/Textures.cpp.o.d -o CMakeFiles/Textures.dir/Textures/Textures.cpp.o -c "/home/amirka/Рабочий стол/C++/DinoGame/Textures/Textures.cpp"

CMakeFiles/Textures.dir/Textures/Textures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Textures.dir/Textures/Textures.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/amirka/Рабочий стол/C++/DinoGame/Textures/Textures.cpp" > CMakeFiles/Textures.dir/Textures/Textures.cpp.i

CMakeFiles/Textures.dir/Textures/Textures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Textures.dir/Textures/Textures.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/amirka/Рабочий стол/C++/DinoGame/Textures/Textures.cpp" -o CMakeFiles/Textures.dir/Textures/Textures.cpp.s

# Object files for target Textures
Textures_OBJECTS = \
"CMakeFiles/Textures.dir/Textures/Textures.cpp.o"

# External object files for target Textures
Textures_EXTERNAL_OBJECTS =

libTextures.a: CMakeFiles/Textures.dir/Textures/Textures.cpp.o
libTextures.a: CMakeFiles/Textures.dir/build.make
libTextures.a: CMakeFiles/Textures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/amirka/Рабочий стол/C++/DinoGame/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libTextures.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Textures.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Textures.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Textures.dir/build: libTextures.a
.PHONY : CMakeFiles/Textures.dir/build

CMakeFiles/Textures.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Textures.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Textures.dir/clean

CMakeFiles/Textures.dir/depend:
	cd "/home/amirka/Рабочий стол/C++/DinoGame/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/amirka/Рабочий стол/C++/DinoGame" "/home/amirka/Рабочий стол/C++/DinoGame" "/home/amirka/Рабочий стол/C++/DinoGame/build" "/home/amirka/Рабочий стол/C++/DinoGame/build" "/home/amirka/Рабочий стол/C++/DinoGame/build/CMakeFiles/Textures.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Textures.dir/depend

