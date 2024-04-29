# On Ubuntu 18.04, get the latest CMake from https://apt.kitware.com/.
cmake_minimum_required(VERSION 3.18)

project(MeshToVoxelPlayspace LANGUAGES C CXX)

# The options need to be the same as Open3D's default
# If Open3D is configured and built with custom options, you'll also need to
# specify the same custom options.
option(STATIC_WINDOWS_RUNTIME "Use static (MT/MTd) Windows runtime" ON)
if(STATIC_WINDOWS_RUNTIME)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

# Find installed Open3D, which exports Open3D::Open3D
find_package(Open3D REQUIRED)
find_package(Eigen3 REQUIRED)

add_executable(meshvoxel)
target_sources(meshvoxel PRIVATE src/mesh_to_voxel.cpp)
target_link_libraries(meshvoxel PRIVATE Open3D::Open3D)

