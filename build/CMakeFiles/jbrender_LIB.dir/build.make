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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build

# Include any dependencies generated for this target.
include CMakeFiles/jbrender_LIB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/jbrender_LIB.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/jbrender_LIB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jbrender_LIB.dir/flags.make

CMakeFiles/jbrender_LIB.dir/lib/input/input.c.o: CMakeFiles/jbrender_LIB.dir/flags.make
CMakeFiles/jbrender_LIB.dir/lib/input/input.c.o: ../lib/input/input.c
CMakeFiles/jbrender_LIB.dir/lib/input/input.c.o: CMakeFiles/jbrender_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/jbrender_LIB.dir/lib/input/input.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/jbrender_LIB.dir/lib/input/input.c.o -MF CMakeFiles/jbrender_LIB.dir/lib/input/input.c.o.d -o CMakeFiles/jbrender_LIB.dir/lib/input/input.c.o -c /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/input/input.c

CMakeFiles/jbrender_LIB.dir/lib/input/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jbrender_LIB.dir/lib/input/input.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/input/input.c > CMakeFiles/jbrender_LIB.dir/lib/input/input.c.i

CMakeFiles/jbrender_LIB.dir/lib/input/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jbrender_LIB.dir/lib/input/input.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/input/input.c -o CMakeFiles/jbrender_LIB.dir/lib/input/input.c.s

CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.o: CMakeFiles/jbrender_LIB.dir/flags.make
CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.o: ../lib/linalg/linalg.c
CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.o: CMakeFiles/jbrender_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.o -MF CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.o.d -o CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.o -c /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/linalg/linalg.c

CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/linalg/linalg.c > CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.i

CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/linalg/linalg.c -o CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.s

CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.o: CMakeFiles/jbrender_LIB.dir/flags.make
CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.o: ../lib/meshtools/fileobj.c
CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.o: CMakeFiles/jbrender_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.o -MF CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.o.d -o CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.o -c /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/meshtools/fileobj.c

CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/meshtools/fileobj.c > CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.i

CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/meshtools/fileobj.c -o CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.s

CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.o: CMakeFiles/jbrender_LIB.dir/flags.make
CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.o: ../lib/meshtools/mesh.c
CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.o: CMakeFiles/jbrender_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.o -MF CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.o.d -o CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.o -c /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/meshtools/mesh.c

CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/meshtools/mesh.c > CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.i

CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/lib/meshtools/mesh.c -o CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.s

CMakeFiles/jbrender_LIB.dir/src/render/screen.c.o: CMakeFiles/jbrender_LIB.dir/flags.make
CMakeFiles/jbrender_LIB.dir/src/render/screen.c.o: ../src/render/screen.c
CMakeFiles/jbrender_LIB.dir/src/render/screen.c.o: CMakeFiles/jbrender_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/jbrender_LIB.dir/src/render/screen.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/jbrender_LIB.dir/src/render/screen.c.o -MF CMakeFiles/jbrender_LIB.dir/src/render/screen.c.o.d -o CMakeFiles/jbrender_LIB.dir/src/render/screen.c.o -c /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/src/render/screen.c

CMakeFiles/jbrender_LIB.dir/src/render/screen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jbrender_LIB.dir/src/render/screen.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/src/render/screen.c > CMakeFiles/jbrender_LIB.dir/src/render/screen.c.i

CMakeFiles/jbrender_LIB.dir/src/render/screen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jbrender_LIB.dir/src/render/screen.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/src/render/screen.c -o CMakeFiles/jbrender_LIB.dir/src/render/screen.c.s

CMakeFiles/jbrender_LIB.dir/src/render/world.c.o: CMakeFiles/jbrender_LIB.dir/flags.make
CMakeFiles/jbrender_LIB.dir/src/render/world.c.o: ../src/render/world.c
CMakeFiles/jbrender_LIB.dir/src/render/world.c.o: CMakeFiles/jbrender_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/jbrender_LIB.dir/src/render/world.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/jbrender_LIB.dir/src/render/world.c.o -MF CMakeFiles/jbrender_LIB.dir/src/render/world.c.o.d -o CMakeFiles/jbrender_LIB.dir/src/render/world.c.o -c /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/src/render/world.c

CMakeFiles/jbrender_LIB.dir/src/render/world.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jbrender_LIB.dir/src/render/world.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/src/render/world.c > CMakeFiles/jbrender_LIB.dir/src/render/world.c.i

CMakeFiles/jbrender_LIB.dir/src/render/world.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jbrender_LIB.dir/src/render/world.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/src/render/world.c -o CMakeFiles/jbrender_LIB.dir/src/render/world.c.s

# Object files for target jbrender_LIB
jbrender_LIB_OBJECTS = \
"CMakeFiles/jbrender_LIB.dir/lib/input/input.c.o" \
"CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.o" \
"CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.o" \
"CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.o" \
"CMakeFiles/jbrender_LIB.dir/src/render/screen.c.o" \
"CMakeFiles/jbrender_LIB.dir/src/render/world.c.o"

# External object files for target jbrender_LIB
jbrender_LIB_EXTERNAL_OBJECTS =

libjbrender_LIB.a: CMakeFiles/jbrender_LIB.dir/lib/input/input.c.o
libjbrender_LIB.a: CMakeFiles/jbrender_LIB.dir/lib/linalg/linalg.c.o
libjbrender_LIB.a: CMakeFiles/jbrender_LIB.dir/lib/meshtools/fileobj.c.o
libjbrender_LIB.a: CMakeFiles/jbrender_LIB.dir/lib/meshtools/mesh.c.o
libjbrender_LIB.a: CMakeFiles/jbrender_LIB.dir/src/render/screen.c.o
libjbrender_LIB.a: CMakeFiles/jbrender_LIB.dir/src/render/world.c.o
libjbrender_LIB.a: CMakeFiles/jbrender_LIB.dir/build.make
libjbrender_LIB.a: CMakeFiles/jbrender_LIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library libjbrender_LIB.a"
	$(CMAKE_COMMAND) -P CMakeFiles/jbrender_LIB.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jbrender_LIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jbrender_LIB.dir/build: libjbrender_LIB.a
.PHONY : CMakeFiles/jbrender_LIB.dir/build

CMakeFiles/jbrender_LIB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jbrender_LIB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jbrender_LIB.dir/clean

CMakeFiles/jbrender_LIB.dir/depend:
	cd /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build /Users/joshuachasnov/Documents/ProgrammingProjects/CProjects/jbrender/build/CMakeFiles/jbrender_LIB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jbrender_LIB.dir/depend
