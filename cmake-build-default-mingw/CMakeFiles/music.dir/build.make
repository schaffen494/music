# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\music

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\music\cmake-build-default-mingw

# Include any dependencies generated for this target.
include CMakeFiles/music.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/music.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/music.dir/flags.make

CMakeFiles/music.dir/src/main.c.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/main.c.obj: CMakeFiles/music.dir/includes_C.rsp
CMakeFiles/music.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/music.dir/src/main.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\music.dir\src\main.c.obj   -c D:\music\src\main.c

CMakeFiles/music.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/music.dir/src/main.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\music\src\main.c > CMakeFiles\music.dir\src\main.c.i

CMakeFiles/music.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/music.dir/src/main.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\music\src\main.c -o CMakeFiles\music.dir\src\main.c.s

CMakeFiles/music.dir/src/view/intro.c.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/view/intro.c.obj: CMakeFiles/music.dir/includes_C.rsp
CMakeFiles/music.dir/src/view/intro.c.obj: ../src/view/intro.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/music.dir/src/view/intro.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\music.dir\src\view\intro.c.obj   -c D:\music\src\view\intro.c

CMakeFiles/music.dir/src/view/intro.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/music.dir/src/view/intro.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\music\src\view\intro.c > CMakeFiles\music.dir\src\view\intro.c.i

CMakeFiles/music.dir/src/view/intro.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/music.dir/src/view/intro.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\music\src\view\intro.c -o CMakeFiles\music.dir\src\view\intro.c.s

CMakeFiles/music.dir/src/view/main_board.c.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/view/main_board.c.obj: CMakeFiles/music.dir/includes_C.rsp
CMakeFiles/music.dir/src/view/main_board.c.obj: ../src/view/main_board.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/music.dir/src/view/main_board.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\music.dir\src\view\main_board.c.obj   -c D:\music\src\view\main_board.c

CMakeFiles/music.dir/src/view/main_board.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/music.dir/src/view/main_board.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\music\src\view\main_board.c > CMakeFiles\music.dir\src\view\main_board.c.i

CMakeFiles/music.dir/src/view/main_board.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/music.dir/src/view/main_board.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\music\src\view\main_board.c -o CMakeFiles\music.dir\src\view\main_board.c.s

CMakeFiles/music.dir/src/view/sign_in.c.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/view/sign_in.c.obj: CMakeFiles/music.dir/includes_C.rsp
CMakeFiles/music.dir/src/view/sign_in.c.obj: ../src/view/sign_in.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/music.dir/src/view/sign_in.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\music.dir\src\view\sign_in.c.obj   -c D:\music\src\view\sign_in.c

CMakeFiles/music.dir/src/view/sign_in.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/music.dir/src/view/sign_in.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\music\src\view\sign_in.c > CMakeFiles\music.dir\src\view\sign_in.c.i

CMakeFiles/music.dir/src/view/sign_in.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/music.dir/src/view/sign_in.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\music\src\view\sign_in.c -o CMakeFiles\music.dir\src\view\sign_in.c.s

CMakeFiles/music.dir/src/view/sign_up.c.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/view/sign_up.c.obj: CMakeFiles/music.dir/includes_C.rsp
CMakeFiles/music.dir/src/view/sign_up.c.obj: ../src/view/sign_up.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/music.dir/src/view/sign_up.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\music.dir\src\view\sign_up.c.obj   -c D:\music\src\view\sign_up.c

CMakeFiles/music.dir/src/view/sign_up.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/music.dir/src/view/sign_up.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\music\src\view\sign_up.c > CMakeFiles\music.dir\src\view\sign_up.c.i

CMakeFiles/music.dir/src/view/sign_up.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/music.dir/src/view/sign_up.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\music\src\view\sign_up.c -o CMakeFiles\music.dir\src\view\sign_up.c.s

CMakeFiles/music.dir/src/components/main_menu.c.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/components/main_menu.c.obj: CMakeFiles/music.dir/includes_C.rsp
CMakeFiles/music.dir/src/components/main_menu.c.obj: ../src/components/main_menu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/music.dir/src/components/main_menu.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\music.dir\src\components\main_menu.c.obj   -c D:\music\src\components\main_menu.c

CMakeFiles/music.dir/src/components/main_menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/music.dir/src/components/main_menu.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\music\src\components\main_menu.c > CMakeFiles\music.dir\src\components\main_menu.c.i

CMakeFiles/music.dir/src/components/main_menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/music.dir/src/components/main_menu.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\music\src\components\main_menu.c -o CMakeFiles\music.dir\src\components\main_menu.c.s

CMakeFiles/music.dir/src/model/songs.c.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/model/songs.c.obj: CMakeFiles/music.dir/includes_C.rsp
CMakeFiles/music.dir/src/model/songs.c.obj: ../src/model/songs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/music.dir/src/model/songs.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\music.dir\src\model\songs.c.obj   -c D:\music\src\model\songs.c

CMakeFiles/music.dir/src/model/songs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/music.dir/src/model/songs.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\music\src\model\songs.c > CMakeFiles\music.dir\src\model\songs.c.i

CMakeFiles/music.dir/src/model/songs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/music.dir/src/model/songs.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\music\src\model\songs.c -o CMakeFiles\music.dir\src\model\songs.c.s

CMakeFiles/music.dir/src/model/user.c.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/model/user.c.obj: CMakeFiles/music.dir/includes_C.rsp
CMakeFiles/music.dir/src/model/user.c.obj: ../src/model/user.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/music.dir/src/model/user.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\music.dir\src\model\user.c.obj   -c D:\music\src\model\user.c

CMakeFiles/music.dir/src/model/user.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/music.dir/src/model/user.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\music\src\model\user.c > CMakeFiles\music.dir\src\model\user.c.i

CMakeFiles/music.dir/src/model/user.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/music.dir/src/model/user.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\music\src\model\user.c -o CMakeFiles\music.dir\src\model\user.c.s

CMakeFiles/music.dir/src/db/connectData.c.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/db/connectData.c.obj: CMakeFiles/music.dir/includes_C.rsp
CMakeFiles/music.dir/src/db/connectData.c.obj: ../src/db/connectData.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/music.dir/src/db/connectData.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\music.dir\src\db\connectData.c.obj   -c D:\music\src\db\connectData.c

CMakeFiles/music.dir/src/db/connectData.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/music.dir/src/db/connectData.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\music\src\db\connectData.c > CMakeFiles\music.dir\src\db\connectData.c.i

CMakeFiles/music.dir/src/db/connectData.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/music.dir/src/db/connectData.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\music\src\db\connectData.c -o CMakeFiles\music.dir\src\db\connectData.c.s

CMakeFiles/music.dir/src/model/playlist.c.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/model/playlist.c.obj: CMakeFiles/music.dir/includes_C.rsp
CMakeFiles/music.dir/src/model/playlist.c.obj: ../src/model/playlist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/music.dir/src/model/playlist.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\music.dir\src\model\playlist.c.obj   -c D:\music\src\model\playlist.c

CMakeFiles/music.dir/src/model/playlist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/music.dir/src/model/playlist.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\music\src\model\playlist.c > CMakeFiles\music.dir\src\model\playlist.c.i

CMakeFiles/music.dir/src/model/playlist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/music.dir/src/model/playlist.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\music\src\model\playlist.c -o CMakeFiles\music.dir\src\model\playlist.c.s

CMakeFiles/music.dir/src/model/album.c.obj: CMakeFiles/music.dir/flags.make
CMakeFiles/music.dir/src/model/album.c.obj: CMakeFiles/music.dir/includes_C.rsp
CMakeFiles/music.dir/src/model/album.c.obj: ../src/model/album.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/music.dir/src/model/album.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\music.dir\src\model\album.c.obj   -c D:\music\src\model\album.c

CMakeFiles/music.dir/src/model/album.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/music.dir/src/model/album.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\music\src\model\album.c > CMakeFiles\music.dir\src\model\album.c.i

CMakeFiles/music.dir/src/model/album.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/music.dir/src/model/album.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\music\src\model\album.c -o CMakeFiles\music.dir\src\model\album.c.s

# Object files for target music
music_OBJECTS = \
"CMakeFiles/music.dir/src/main.c.obj" \
"CMakeFiles/music.dir/src/view/intro.c.obj" \
"CMakeFiles/music.dir/src/view/main_board.c.obj" \
"CMakeFiles/music.dir/src/view/sign_in.c.obj" \
"CMakeFiles/music.dir/src/view/sign_up.c.obj" \
"CMakeFiles/music.dir/src/components/main_menu.c.obj" \
"CMakeFiles/music.dir/src/model/songs.c.obj" \
"CMakeFiles/music.dir/src/model/user.c.obj" \
"CMakeFiles/music.dir/src/db/connectData.c.obj" \
"CMakeFiles/music.dir/src/model/playlist.c.obj" \
"CMakeFiles/music.dir/src/model/album.c.obj"

# External object files for target music
music_EXTERNAL_OBJECTS =

music.exe: CMakeFiles/music.dir/src/main.c.obj
music.exe: CMakeFiles/music.dir/src/view/intro.c.obj
music.exe: CMakeFiles/music.dir/src/view/main_board.c.obj
music.exe: CMakeFiles/music.dir/src/view/sign_in.c.obj
music.exe: CMakeFiles/music.dir/src/view/sign_up.c.obj
music.exe: CMakeFiles/music.dir/src/components/main_menu.c.obj
music.exe: CMakeFiles/music.dir/src/model/songs.c.obj
music.exe: CMakeFiles/music.dir/src/model/user.c.obj
music.exe: CMakeFiles/music.dir/src/db/connectData.c.obj
music.exe: CMakeFiles/music.dir/src/model/playlist.c.obj
music.exe: CMakeFiles/music.dir/src/model/album.c.obj
music.exe: CMakeFiles/music.dir/build.make
music.exe: C:/msys64/mingw64/lib/libsqlite3.dll.a
music.exe: CMakeFiles/music.dir/linklibs.rsp
music.exe: CMakeFiles/music.dir/objects1.rsp
music.exe: CMakeFiles/music.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\music\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable music.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\music.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/music.dir/build: music.exe

.PHONY : CMakeFiles/music.dir/build

CMakeFiles/music.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\music.dir\cmake_clean.cmake
.PHONY : CMakeFiles/music.dir/clean

CMakeFiles/music.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\music D:\music D:\music\cmake-build-default-mingw D:\music\cmake-build-default-mingw D:\music\cmake-build-default-mingw\CMakeFiles\music.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/music.dir/depend

