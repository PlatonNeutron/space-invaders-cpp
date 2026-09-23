# CMakeList.txt : CMake project for space invaders cpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (SpaceInvadersCpp VERSION 0.0.1 LANGUAGES CXX)

#  Include
include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)

FetchContent_MakeAvailable(raylib)

# Add source to this project's executable.
add_executable(SpaceInvadersCpp 
    src/main.cpp
    src/player.cpp
    src/Bullet.cpp
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SpaceInvadersCpp PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
target_include_directories(SpaceInvadersCpp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(SpaceInvadersCpp PRIVATE raylib)