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
CMAKE_SOURCE_DIR = D:\mystic_melody

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\mystic_melody\cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C.dir/flags.make

CMakeFiles/C.dir/src/main.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/main.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/C.dir/src/main.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\main.c.obj   -c D:\mystic_melody\src\main.c

CMakeFiles/C.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/main.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\main.c > CMakeFiles\C.dir\src\main.c.i

CMakeFiles/C.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/main.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\main.c -o CMakeFiles\C.dir\src\main.c.s

CMakeFiles/C.dir/src/config/database_config.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/config/database_config.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/config/database_config.c.obj: ../src/config/database_config.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/C.dir/src/config/database_config.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\config\database_config.c.obj   -c D:\mystic_melody\src\config\database_config.c

CMakeFiles/C.dir/src/config/database_config.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/config/database_config.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\config\database_config.c > CMakeFiles\C.dir\src\config\database_config.c.i

CMakeFiles/C.dir/src/config/database_config.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/config/database_config.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\config\database_config.c -o CMakeFiles\C.dir\src\config\database_config.c.s

CMakeFiles/C.dir/src/view/intro_view.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/view/intro_view.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/view/intro_view.c.obj: ../src/view/intro_view.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/C.dir/src/view/intro_view.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\view\intro_view.c.obj   -c D:\mystic_melody\src\view\intro_view.c

CMakeFiles/C.dir/src/view/intro_view.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/view/intro_view.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\view\intro_view.c > CMakeFiles\C.dir\src\view\intro_view.c.i

CMakeFiles/C.dir/src/view/intro_view.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/view/intro_view.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\view\intro_view.c -o CMakeFiles\C.dir\src\view\intro_view.c.s

CMakeFiles/C.dir/src/view/components/menu.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/view/components/menu.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/view/components/menu.c.obj: ../src/view/components/menu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/C.dir/src/view/components/menu.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\view\components\menu.c.obj   -c D:\mystic_melody\src\view\components\menu.c

CMakeFiles/C.dir/src/view/components/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/view/components/menu.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\view\components\menu.c > CMakeFiles\C.dir\src\view\components\menu.c.i

CMakeFiles/C.dir/src/view/components/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/view/components/menu.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\view\components\menu.c -o CMakeFiles\C.dir\src\view\components\menu.c.s

CMakeFiles/C.dir/src/view/components/music_bar.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/view/components/music_bar.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/view/components/music_bar.c.obj: ../src/view/components/music_bar.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/C.dir/src/view/components/music_bar.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\view\components\music_bar.c.obj   -c D:\mystic_melody\src\view\components\music_bar.c

CMakeFiles/C.dir/src/view/components/music_bar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/view/components/music_bar.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\view\components\music_bar.c > CMakeFiles\C.dir\src\view\components\music_bar.c.i

CMakeFiles/C.dir/src/view/components/music_bar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/view/components/music_bar.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\view\components\music_bar.c -o CMakeFiles\C.dir\src\view\components\music_bar.c.s

CMakeFiles/C.dir/src/view/components/search_bar.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/view/components/search_bar.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/view/components/search_bar.c.obj: ../src/view/components/search_bar.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/C.dir/src/view/components/search_bar.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\view\components\search_bar.c.obj   -c D:\mystic_melody\src\view\components\search_bar.c

CMakeFiles/C.dir/src/view/components/search_bar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/view/components/search_bar.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\view\components\search_bar.c > CMakeFiles\C.dir\src\view\components\search_bar.c.i

CMakeFiles/C.dir/src/view/components/search_bar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/view/components/search_bar.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\view\components\search_bar.c -o CMakeFiles\C.dir\src\view\components\search_bar.c.s

CMakeFiles/C.dir/src/view/sign_in_view.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/view/sign_in_view.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/view/sign_in_view.c.obj: ../src/view/sign_in_view.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/C.dir/src/view/sign_in_view.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\view\sign_in_view.c.obj   -c D:\mystic_melody\src\view\sign_in_view.c

CMakeFiles/C.dir/src/view/sign_in_view.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/view/sign_in_view.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\view\sign_in_view.c > CMakeFiles\C.dir\src\view\sign_in_view.c.i

CMakeFiles/C.dir/src/view/sign_in_view.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/view/sign_in_view.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\view\sign_in_view.c -o CMakeFiles\C.dir\src\view\sign_in_view.c.s

CMakeFiles/C.dir/src/models/users.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/models/users.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/models/users.c.obj: ../src/models/users.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/C.dir/src/models/users.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\models\users.c.obj   -c D:\mystic_melody\src\models\users.c

CMakeFiles/C.dir/src/models/users.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/models/users.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\models\users.c > CMakeFiles\C.dir\src\models\users.c.i

CMakeFiles/C.dir/src/models/users.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/models/users.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\models\users.c -o CMakeFiles\C.dir\src\models\users.c.s

CMakeFiles/C.dir/src/control/sign_in_control.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/control/sign_in_control.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/control/sign_in_control.c.obj: ../src/control/sign_in_control.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/C.dir/src/control/sign_in_control.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\control\sign_in_control.c.obj   -c D:\mystic_melody\src\control\sign_in_control.c

CMakeFiles/C.dir/src/control/sign_in_control.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/control/sign_in_control.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\control\sign_in_control.c > CMakeFiles\C.dir\src\control\sign_in_control.c.i

CMakeFiles/C.dir/src/control/sign_in_control.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/control/sign_in_control.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\control\sign_in_control.c -o CMakeFiles\C.dir\src\control\sign_in_control.c.s

CMakeFiles/C.dir/src/view/main_board_view.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/view/main_board_view.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/view/main_board_view.c.obj: ../src/view/main_board_view.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/C.dir/src/view/main_board_view.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\view\main_board_view.c.obj   -c D:\mystic_melody\src\view\main_board_view.c

CMakeFiles/C.dir/src/view/main_board_view.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/view/main_board_view.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\view\main_board_view.c > CMakeFiles\C.dir\src\view\main_board_view.c.i

CMakeFiles/C.dir/src/view/main_board_view.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/view/main_board_view.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\view\main_board_view.c -o CMakeFiles\C.dir\src\view\main_board_view.c.s

CMakeFiles/C.dir/src/view/sign_up_view.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/view/sign_up_view.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/view/sign_up_view.c.obj: ../src/view/sign_up_view.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/C.dir/src/view/sign_up_view.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\view\sign_up_view.c.obj   -c D:\mystic_melody\src\view\sign_up_view.c

CMakeFiles/C.dir/src/view/sign_up_view.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/view/sign_up_view.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\view\sign_up_view.c > CMakeFiles\C.dir\src\view\sign_up_view.c.i

CMakeFiles/C.dir/src/view/sign_up_view.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/view/sign_up_view.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\view\sign_up_view.c -o CMakeFiles\C.dir\src\view\sign_up_view.c.s

CMakeFiles/C.dir/src/control/sign_up_control.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/control/sign_up_control.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/control/sign_up_control.c.obj: ../src/control/sign_up_control.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/C.dir/src/control/sign_up_control.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\control\sign_up_control.c.obj   -c D:\mystic_melody\src\control\sign_up_control.c

CMakeFiles/C.dir/src/control/sign_up_control.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/control/sign_up_control.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\control\sign_up_control.c > CMakeFiles\C.dir\src\control\sign_up_control.c.i

CMakeFiles/C.dir/src/control/sign_up_control.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/control/sign_up_control.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\control\sign_up_control.c -o CMakeFiles\C.dir\src\control\sign_up_control.c.s

CMakeFiles/C.dir/src/control/main_board_control.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/control/main_board_control.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/control/main_board_control.c.obj: ../src/control/main_board_control.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/C.dir/src/control/main_board_control.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\control\main_board_control.c.obj   -c D:\mystic_melody\src\control\main_board_control.c

CMakeFiles/C.dir/src/control/main_board_control.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/control/main_board_control.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\control\main_board_control.c > CMakeFiles\C.dir\src\control\main_board_control.c.i

CMakeFiles/C.dir/src/control/main_board_control.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/control/main_board_control.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\control\main_board_control.c -o CMakeFiles\C.dir\src\control\main_board_control.c.s

CMakeFiles/C.dir/src/models/songs.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/models/songs.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/models/songs.c.obj: ../src/models/songs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/C.dir/src/models/songs.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\models\songs.c.obj   -c D:\mystic_melody\src\models\songs.c

CMakeFiles/C.dir/src/models/songs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/models/songs.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\models\songs.c > CMakeFiles\C.dir\src\models\songs.c.i

CMakeFiles/C.dir/src/models/songs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/models/songs.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\models\songs.c -o CMakeFiles\C.dir\src\models\songs.c.s

CMakeFiles/C.dir/src/models/playlist.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/models/playlist.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/models/playlist.c.obj: ../src/models/playlist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/C.dir/src/models/playlist.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\models\playlist.c.obj   -c D:\mystic_melody\src\models\playlist.c

CMakeFiles/C.dir/src/models/playlist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/models/playlist.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\models\playlist.c > CMakeFiles\C.dir\src\models\playlist.c.i

CMakeFiles/C.dir/src/models/playlist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/models/playlist.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\models\playlist.c -o CMakeFiles\C.dir\src\models\playlist.c.s

CMakeFiles/C.dir/src/view/components/upload.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/view/components/upload.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/view/components/upload.c.obj: ../src/view/components/upload.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/C.dir/src/view/components/upload.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\view\components\upload.c.obj   -c D:\mystic_melody\src\view\components\upload.c

CMakeFiles/C.dir/src/view/components/upload.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/view/components/upload.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\view\components\upload.c > CMakeFiles\C.dir\src\view\components\upload.c.i

CMakeFiles/C.dir/src/view/components/upload.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/view/components/upload.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\view\components\upload.c -o CMakeFiles\C.dir\src\view\components\upload.c.s

CMakeFiles/C.dir/src/view/components/add_playlist.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/src/view/components/add_playlist.c.obj: CMakeFiles/C.dir/includes_C.rsp
CMakeFiles/C.dir/src/view/components/add_playlist.c.obj: ../src/view/components/add_playlist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/C.dir/src/view/components/add_playlist.c.obj"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C.dir\src\view\components\add_playlist.c.obj   -c D:\mystic_melody\src\view\components\add_playlist.c

CMakeFiles/C.dir/src/view/components/add_playlist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/src/view/components/add_playlist.c.i"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\mystic_melody\src\view\components\add_playlist.c > CMakeFiles\C.dir\src\view\components\add_playlist.c.i

CMakeFiles/C.dir/src/view/components/add_playlist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/src/view/components/add_playlist.c.s"
	C:\msys64\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\mystic_melody\src\view\components\add_playlist.c -o CMakeFiles\C.dir\src\view\components\add_playlist.c.s

# Object files for target C
C_OBJECTS = \
"CMakeFiles/C.dir/src/main.c.obj" \
"CMakeFiles/C.dir/src/config/database_config.c.obj" \
"CMakeFiles/C.dir/src/view/intro_view.c.obj" \
"CMakeFiles/C.dir/src/view/components/menu.c.obj" \
"CMakeFiles/C.dir/src/view/components/music_bar.c.obj" \
"CMakeFiles/C.dir/src/view/components/search_bar.c.obj" \
"CMakeFiles/C.dir/src/view/sign_in_view.c.obj" \
"CMakeFiles/C.dir/src/models/users.c.obj" \
"CMakeFiles/C.dir/src/control/sign_in_control.c.obj" \
"CMakeFiles/C.dir/src/view/main_board_view.c.obj" \
"CMakeFiles/C.dir/src/view/sign_up_view.c.obj" \
"CMakeFiles/C.dir/src/control/sign_up_control.c.obj" \
"CMakeFiles/C.dir/src/control/main_board_control.c.obj" \
"CMakeFiles/C.dir/src/models/songs.c.obj" \
"CMakeFiles/C.dir/src/models/playlist.c.obj" \
"CMakeFiles/C.dir/src/view/components/upload.c.obj" \
"CMakeFiles/C.dir/src/view/components/add_playlist.c.obj"

# External object files for target C
C_EXTERNAL_OBJECTS =

C.exe: CMakeFiles/C.dir/src/main.c.obj
C.exe: CMakeFiles/C.dir/src/config/database_config.c.obj
C.exe: CMakeFiles/C.dir/src/view/intro_view.c.obj
C.exe: CMakeFiles/C.dir/src/view/components/menu.c.obj
C.exe: CMakeFiles/C.dir/src/view/components/music_bar.c.obj
C.exe: CMakeFiles/C.dir/src/view/components/search_bar.c.obj
C.exe: CMakeFiles/C.dir/src/view/sign_in_view.c.obj
C.exe: CMakeFiles/C.dir/src/models/users.c.obj
C.exe: CMakeFiles/C.dir/src/control/sign_in_control.c.obj
C.exe: CMakeFiles/C.dir/src/view/main_board_view.c.obj
C.exe: CMakeFiles/C.dir/src/view/sign_up_view.c.obj
C.exe: CMakeFiles/C.dir/src/control/sign_up_control.c.obj
C.exe: CMakeFiles/C.dir/src/control/main_board_control.c.obj
C.exe: CMakeFiles/C.dir/src/models/songs.c.obj
C.exe: CMakeFiles/C.dir/src/models/playlist.c.obj
C.exe: CMakeFiles/C.dir/src/view/components/upload.c.obj
C.exe: CMakeFiles/C.dir/src/view/components/add_playlist.c.obj
C.exe: CMakeFiles/C.dir/build.make
C.exe: C:/msys64/msys64/mingw64/lib/libsqlite3.dll.a
C.exe: CMakeFiles/C.dir/linklibs.rsp
C.exe: CMakeFiles/C.dir/objects1.rsp
C.exe: CMakeFiles/C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking C executable C.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\C.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C.dir/build: C.exe

.PHONY : CMakeFiles/C.dir/build

CMakeFiles/C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\C.dir\cmake_clean.cmake
.PHONY : CMakeFiles/C.dir/clean

CMakeFiles/C.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\mystic_melody D:\mystic_melody D:\mystic_melody\cmake-build-debug-coverage D:\mystic_melody\cmake-build-debug-coverage D:\mystic_melody\cmake-build-debug-coverage\CMakeFiles\C.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C.dir/depend
