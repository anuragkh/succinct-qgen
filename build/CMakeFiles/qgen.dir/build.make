# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.2.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.2.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anuragk/Work/Succinct/succinct-qgen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anuragk/Work/Succinct/succinct-qgen/build

# Include any dependencies generated for this target.
include CMakeFiles/qgen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/qgen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qgen.dir/flags.make

CMakeFiles/qgen.dir/src/search_terms_generator.cc.o: CMakeFiles/qgen.dir/flags.make
CMakeFiles/qgen.dir/src/search_terms_generator.cc.o: ../src/search_terms_generator.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/anuragk/Work/Succinct/succinct-qgen/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/qgen.dir/src/search_terms_generator.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/qgen.dir/src/search_terms_generator.cc.o -c /Users/anuragk/Work/Succinct/succinct-qgen/src/search_terms_generator.cc

CMakeFiles/qgen.dir/src/search_terms_generator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qgen.dir/src/search_terms_generator.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/anuragk/Work/Succinct/succinct-qgen/src/search_terms_generator.cc > CMakeFiles/qgen.dir/src/search_terms_generator.cc.i

CMakeFiles/qgen.dir/src/search_terms_generator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qgen.dir/src/search_terms_generator.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/anuragk/Work/Succinct/succinct-qgen/src/search_terms_generator.cc -o CMakeFiles/qgen.dir/src/search_terms_generator.cc.s

CMakeFiles/qgen.dir/src/search_terms_generator.cc.o.requires:
.PHONY : CMakeFiles/qgen.dir/src/search_terms_generator.cc.o.requires

CMakeFiles/qgen.dir/src/search_terms_generator.cc.o.provides: CMakeFiles/qgen.dir/src/search_terms_generator.cc.o.requires
	$(MAKE) -f CMakeFiles/qgen.dir/build.make CMakeFiles/qgen.dir/src/search_terms_generator.cc.o.provides.build
.PHONY : CMakeFiles/qgen.dir/src/search_terms_generator.cc.o.provides

CMakeFiles/qgen.dir/src/search_terms_generator.cc.o.provides.build: CMakeFiles/qgen.dir/src/search_terms_generator.cc.o

# Object files for target qgen
qgen_OBJECTS = \
"CMakeFiles/qgen.dir/src/search_terms_generator.cc.o"

# External object files for target qgen
qgen_EXTERNAL_OBJECTS =

qgen: CMakeFiles/qgen.dir/src/search_terms_generator.cc.o
qgen: CMakeFiles/qgen.dir/build.make
qgen: CMakeFiles/qgen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable qgen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qgen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qgen.dir/build: qgen
.PHONY : CMakeFiles/qgen.dir/build

CMakeFiles/qgen.dir/requires: CMakeFiles/qgen.dir/src/search_terms_generator.cc.o.requires
.PHONY : CMakeFiles/qgen.dir/requires

CMakeFiles/qgen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/qgen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/qgen.dir/clean

CMakeFiles/qgen.dir/depend:
	cd /Users/anuragk/Work/Succinct/succinct-qgen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anuragk/Work/Succinct/succinct-qgen /Users/anuragk/Work/Succinct/succinct-qgen /Users/anuragk/Work/Succinct/succinct-qgen/build /Users/anuragk/Work/Succinct/succinct-qgen/build /Users/anuragk/Work/Succinct/succinct-qgen/build/CMakeFiles/qgen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qgen.dir/depend
