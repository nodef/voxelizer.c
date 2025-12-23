#define VOXELIZER_IMPLEMENTATION
#include <voxelizer.h>
#include <stdio.h>


int main() {
    printf("Voxelizing a complex geometry...\n");

    // Load a complex geometry from file
    vx_mesh_t complexGeom = {
        .vertices = (vx_vertex_t[]){
            {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0},
            {0, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 1, 1},
            {0.5, 0.5, 1.5}, {1.5, 0.5, 0.5}, {0.5, 1.5, 0.5}
        },
        .indices = (unsigned int[]){
            0, 1, 2, 2, 3, 0, // Bottom face
            4, 5, 6, 6, 7, 4, // Top face
            0, 1, 5, 5, 4, 0, // Front face
            2, 3, 7, 7, 6, 2, // Back face
            0, 3, 7, 7, 4, 0, // Left face
            1, 2, 6, 6, 5, 1, // Right face
            8, 4, 5, 8, 5, 6, 8, 6, 7, 8, 7, 4, // Pyramid top
            9, 1, 2, 9, 2, 6, 9, 6, 5, 9, 5, 1, // Side extension
            10, 3, 7, 10, 7, 4, 10, 4, 0, 10, 0, 3  // Side extension
        },
        .nvertices = 11,
        .nindices = 72
    };

    // Voxelize the complex geometry
    vx_point_cloud_t* grid = vx_voxelize_pc(&complexGeom, 0.2f, 0.2f, 0.2f, 0.02f); // Voxel size = 0.2

    // Output voxel grid information
    printf("Voxel grid contains %zu vertices\n", grid->nvertices);

    // Clean up
    free(grid);
    return 0;
}
