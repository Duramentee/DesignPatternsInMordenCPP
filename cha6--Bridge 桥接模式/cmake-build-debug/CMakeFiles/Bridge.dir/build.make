# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Bridge.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Bridge.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Bridge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bridge.dir/flags.make

CMakeFiles/Bridge.dir/main.cpp.o: CMakeFiles/Bridge.dir/flags.make
CMakeFiles/Bridge.dir/main.cpp.o: /home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge\ 桥接模式/main.cpp
CMakeFiles/Bridge.dir/main.cpp.o: CMakeFiles/Bridge.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bridge.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Bridge.dir/main.cpp.o -MF CMakeFiles/Bridge.dir/main.cpp.o.d -o CMakeFiles/Bridge.dir/main.cpp.o -c "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/main.cpp"

CMakeFiles/Bridge.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Bridge.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/main.cpp" > CMakeFiles/Bridge.dir/main.cpp.i

CMakeFiles/Bridge.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Bridge.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/main.cpp" -o CMakeFiles/Bridge.dir/main.cpp.s

CMakeFiles/Bridge.dir/Person.cpp.o: CMakeFiles/Bridge.dir/flags.make
CMakeFiles/Bridge.dir/Person.cpp.o: /home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge\ 桥接模式/Person.cpp
CMakeFiles/Bridge.dir/Person.cpp.o: CMakeFiles/Bridge.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Bridge.dir/Person.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Bridge.dir/Person.cpp.o -MF CMakeFiles/Bridge.dir/Person.cpp.o.d -o CMakeFiles/Bridge.dir/Person.cpp.o -c "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/Person.cpp"

CMakeFiles/Bridge.dir/Person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Bridge.dir/Person.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/Person.cpp" > CMakeFiles/Bridge.dir/Person.cpp.i

CMakeFiles/Bridge.dir/Person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Bridge.dir/Person.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/Person.cpp" -o CMakeFiles/Bridge.dir/Person.cpp.s

# Object files for target Bridge
Bridge_OBJECTS = \
"CMakeFiles/Bridge.dir/main.cpp.o" \
"CMakeFiles/Bridge.dir/Person.cpp.o"

# External object files for target Bridge
Bridge_EXTERNAL_OBJECTS =

Bridge: CMakeFiles/Bridge.dir/main.cpp.o
Bridge: CMakeFiles/Bridge.dir/Person.cpp.o
Bridge: CMakeFiles/Bridge.dir/build.make
Bridge: CMakeFiles/Bridge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Bridge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bridge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bridge.dir/build: Bridge
.PHONY : CMakeFiles/Bridge.dir/build

CMakeFiles/Bridge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bridge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bridge.dir/clean

CMakeFiles/Bridge.dir/depend:
	cd "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式" "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式" "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/cmake-build-debug" "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/cmake-build-debug" "/home/drowlia/code_save/DesignPattern/DesignPatternsInMordenCPP/cha6--Bridge 桥接模式/cmake-build-debug/CMakeFiles/Bridge.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Bridge.dir/depend

