#include <string>
#include <iostream>
#include "open3d/Open3D.h"
#include "Eigen/Dense"

int main(int argc, char *argv[]) {
    std::cout << "Starting the example" << std::endl;

    // First load in the data 
    open3d::data::BunnyMesh bunny_data;
    auto bunny_mesh = open3d::io::CreateMeshFromFile(bunny_data.GetPath());

    // measure time
    auto start = std::chrono::high_resolution_clock::now();

    // Second convert to voxelgrid
    auto bunny_voxel_grid = open3d::geometry::VoxelGrid::CreateFromTriangleMesh(*bunny_mesh, 0.02);
    // Extract only the voxels (is a std::vector of type open3d::geometry::voxelgrid::voxel)
    auto voxels = bunny_voxel_grid->GetVoxels();
    std::cout << "size of voxelgrid is: " << voxels.size() << std::endl;

    // measure time
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // the time one mesh->voxelization takes
    std::cout << duration.count() << std::endl;

    // Inspect some random vertex indices
    auto first_random = voxels[0]; 
    auto second_random = voxels[1];

    std::cout << "first example index: " << first_random.grid_index_ << " second example index " << second_random.grid_index_ << std::endl;

    return 0;
}

