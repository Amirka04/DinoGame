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
include CMakeFiles/VectorLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/VectorLib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/VectorLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VectorLib.dir/flags.make

CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.o: CMakeFiles/VectorLib.dir/flags.make
CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.o: ../Vectors/Vector2D.cpp
CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.o: CMakeFiles/VectorLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/amirka/Рабочий стол/C++/DinoGame/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.o -MF CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.o.d -o CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.o -c "/home/amirka/Рабочий стол/C++/DinoGame/Vectors/Vector2D.cpp"

CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/amirka/Рабочий стол/C++/DinoGame/Vectors/Vector2D.cpp" > CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.i

CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/amirka/Рабочий стол/C++/DinoGame/Vectors/Vector2D.cpp" -o CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.s

# Object files for target VectorLib
VectorLib_OBJECTS = \
"CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.o"

# External object files for target VectorLib
VectorLib_EXTERNAL_OBJECTS =

libVectorLib.a: CMakeFiles/VectorLib.dir/Vectors/Vector2D.cpp.o
libVectorLib.a: CMakeFiles/VectorLib.dir/build.make
libVectorLib.a: CMakeFiles/VectorLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/amirka/Рабочий стол/C++/DinoGame/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libVectorLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/VectorLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VectorLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VectorLib.dir/build: libVectorLib.a
.PHONY : CMakeFiles/VectorLib.dir/build

CMakeFiles/VectorLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VectorLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VectorLib.dir/clean

CMakeFiles/VectorLib.dir/depend:
	cd "/home/amirka/Рабочий стол/C++/DinoGame/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/amirka/Рабочий стол/C++/DinoGame" "/home/amirka/Рабочий стол/C++/DinoGame" "/home/amirka/Рабочий стол/C++/DinoGame/build" "/home/amirka/Рабочий стол/C++/DinoGame/build" "/home/amirka/Рабочий стол/C++/DinoGame/build/CMakeFiles/VectorLib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/VectorLib.dir/depend

