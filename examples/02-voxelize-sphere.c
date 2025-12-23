#define VOXELIZER_IMPLEMENTATION
#include <voxelizer.h>
#include <stdio.h>


int main() {
    printf("Voxelizing a sphere...\n");

    // Define a sphere geometry
    vx_mesh_t sphere = {
        .vertices = (vx_vertex_t[]){
            {0, 0, -1}, {0.894, 0, -0.447}, {-0.894, 0, -0.447},
            {0.276, 0.851, -0.447}, {-0.724, 0.526, -0.447},
            {-0.724, -0.526, -0.447}, {0.276, -0.851, -0.447},
            {0.724, 0.526, 0.447}, {-0.276, 0.851, 0.447},
            {-0.894, 0, 0.447}, {-0.276, -0.851, 0.447},
            {0.724, -0.526, 0.447}, {0, 0, 1}
        },
        .indices = (unsigned int[]){
            0, 1, 3, 0, 3, 4, 0, 4, 5, 0, 5, 6, 0, 6, 1,
            1, 7, 3, 3, 8, 4, 4, 9, 5, 5, 10, 6, 6, 11, 1,
            7, 8, 3, 8, 9, 4, 9, 10, 5, 10, 11, 6, 11, 7, 1,
            7, 12, 8, 8, 12, 9, 9, 12, 10, 10, 12, 11, 11, 12, 7
        },
        .nvertices = 13,
        .nindices = 60
    };

    // Voxelize the sphere
    vx_point_cloud_t* grid = vx_voxelize_pc(&sphere, 0.05f, 0.05f, 0.05f, 0.005f); // Voxel size = 0.05

    // Output voxel grid information
    printf("Voxel grid contains %zu vertices\n", grid->nvertices);

    // Clean up
    free(grid);
    return 0;
}
