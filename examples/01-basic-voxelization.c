#define VOXELIZER_IMPLEMENTATION
#include <voxelizer.h>
#include <stdio.h>

int main() {
    // Example 1: Basic voxelization of a cube
    printf("Voxelizing a cube...\n");

    // Define a simple cube geometry
    vx_mesh_t cube = {
        .vertices = (vx_vertex_t[]){
            {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0},
            {0, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 1, 1}
        },
        .indices = (unsigned int[]){
            0, 1, 2, 2, 3, 0, // Bottom face
            4, 5, 6, 6, 7, 4, // Top face
            0, 1, 5, 5, 4, 0, // Front face
            2, 3, 7, 7, 6, 2, // Back face
            0, 3, 7, 7, 4, 0, // Left face
            1, 2, 6, 6, 5, 1  // Right face
        },
        .nvertices = 8,
        .nindices = 36
    };

    // Voxelize the cube
    vx_point_cloud_t* grid = vx_voxelize_pc(&cube, 0.1f, 0.1f, 0.1f, 0.01f); // Voxel size = 0.1

    // Output voxel grid information
    printf("Voxel grid contains %zu vertices\n", grid->nvertices);

    // Clean up
    free(grid);
    return 0;
}
