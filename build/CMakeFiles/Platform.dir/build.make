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
include CMakeFiles/Platform.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Platform.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Platform.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Platform.dir/flags.make

CMakeFiles/Platform.dir/Platform/Platform.cpp.o: CMakeFiles/Platform.dir/flags.make
CMakeFiles/Platform.dir/Platform/Platform.cpp.o: ../Platform/Platform.cpp
CMakeFiles/Platform.dir/Platform/Platform.cpp.o: CMakeFiles/Platform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/amirka/Рабочий стол/C++/DinoGame/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Platform.dir/Platform/Platform.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Platform.dir/Platform/Platform.cpp.o -MF CMakeFiles/Platform.dir/Platform/Platform.cpp.o.d -o CMakeFiles/Platform.dir/Platform/Platform.cpp.o -c "/home/amirka/Рабочий стол/C++/DinoGame/Platform/Platform.cpp"

CMakeFiles/Platform.dir/Platform/Platform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Platform.dir/Platform/Platform.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/amirka/Рабочий стол/C++/DinoGame/Platform/Platform.cpp" > CMakeFiles/Platform.dir/Platform/Platform.cpp.i

CMakeFiles/Platform.dir/Platform/Platform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Platform.dir/Platform/Platform.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/amirka/Рабочий стол/C++/DinoGame/Platform/Platform.cpp" -o CMakeFiles/Platform.dir/Platform/Platform.cpp.s

# Object files for target Platform
Platform_OBJECTS = \
"CMakeFiles/Platform.dir/Platform/Platform.cpp.o"

# External object files for target Platform
Platform_EXTERNAL_OBJECTS =

libPlatform.a: CMakeFiles/Platform.dir/Platform/Platform.cpp.o
libPlatform.a: CMakeFiles/Platform.dir/build.make
libPlatform.a: CMakeFiles/Platform.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/amirka/Рабочий стол/C++/DinoGame/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libPlatform.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Platform.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Platform.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Platform.dir/build: libPlatform.a
.PHONY : CMakeFiles/Platform.dir/build

CMakeFiles/Platform.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Platform.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Platform.dir/clean

CMakeFiles/Platform.dir/depend:
	cd "/home/amirka/Рабочий стол/C++/DinoGame/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/amirka/Рабочий стол/C++/DinoGame" "/home/amirka/Рабочий стол/C++/DinoGame" "/home/amirka/Рабочий стол/C++/DinoGame/build" "/home/amirka/Рабочий стол/C++/DinoGame/build" "/home/amirka/Рабочий стол/C++/DinoGame/build/CMakeFiles/Platform.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Platform.dir/depend

