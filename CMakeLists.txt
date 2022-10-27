cmake_minimum_required(VERSION 3.12)
project(Test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

add_definitions(-DFM_SPEED_DEFAULT=ESpeedNormal)
add_compile_options(-O3)
add_compile_options(-Wall)

add_executable(TestMain TestMain.cpp)
target_include_directories(TestMain PUBLIC ${PROJECT_SOURCE_DIR})

# ## complie for Zero
# file(GLOB_RECURSE ZERO_SOURCES ${ZERO_SOURCES_DIR}/*.cpp)
# add_subdirectory(./test)