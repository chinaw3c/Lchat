# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/wang/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.6183.77/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/wang/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.6183.77/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wang/Liuaotian/Lchat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wang/Liuaotian/Lchat/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lchat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lchat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lchat.dir/flags.make

CMakeFiles/Lchat.dir/main.cpp.o: CMakeFiles/Lchat.dir/flags.make
CMakeFiles/Lchat.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wang/Liuaotian/Lchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lchat.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lchat.dir/main.cpp.o -c /home/wang/Liuaotian/Lchat/main.cpp

CMakeFiles/Lchat.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lchat.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wang/Liuaotian/Lchat/main.cpp > CMakeFiles/Lchat.dir/main.cpp.i

CMakeFiles/Lchat.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lchat.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wang/Liuaotian/Lchat/main.cpp -o CMakeFiles/Lchat.dir/main.cpp.s

CMakeFiles/Lchat.dir/socket/Server.cc.o: CMakeFiles/Lchat.dir/flags.make
CMakeFiles/Lchat.dir/socket/Server.cc.o: ../socket/Server.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wang/Liuaotian/Lchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lchat.dir/socket/Server.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lchat.dir/socket/Server.cc.o -c /home/wang/Liuaotian/Lchat/socket/Server.cc

CMakeFiles/Lchat.dir/socket/Server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lchat.dir/socket/Server.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wang/Liuaotian/Lchat/socket/Server.cc > CMakeFiles/Lchat.dir/socket/Server.cc.i

CMakeFiles/Lchat.dir/socket/Server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lchat.dir/socket/Server.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wang/Liuaotian/Lchat/socket/Server.cc -o CMakeFiles/Lchat.dir/socket/Server.cc.s

# Object files for target Lchat
Lchat_OBJECTS = \
"CMakeFiles/Lchat.dir/main.cpp.o" \
"CMakeFiles/Lchat.dir/socket/Server.cc.o"

# External object files for target Lchat
Lchat_EXTERNAL_OBJECTS =

Lchat: CMakeFiles/Lchat.dir/main.cpp.o
Lchat: CMakeFiles/Lchat.dir/socket/Server.cc.o
Lchat: CMakeFiles/Lchat.dir/build.make
Lchat: CMakeFiles/Lchat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wang/Liuaotian/Lchat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lchat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lchat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lchat.dir/build: Lchat

.PHONY : CMakeFiles/Lchat.dir/build

CMakeFiles/Lchat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lchat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lchat.dir/clean

CMakeFiles/Lchat.dir/depend:
	cd /home/wang/Liuaotian/Lchat/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wang/Liuaotian/Lchat /home/wang/Liuaotian/Lchat /home/wang/Liuaotian/Lchat/cmake-build-debug /home/wang/Liuaotian/Lchat/cmake-build-debug /home/wang/Liuaotian/Lchat/cmake-build-debug/CMakeFiles/Lchat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lchat.dir/depend

