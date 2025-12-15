# Mesh voxelizer
_Header only mesh voxelizer in ANSI C_

![](https://github.com/karimnaaji/voxelizer/blob/master/images/capture.png)

<br>

**About**

Converts meshes and performs triangle-cube intersection to output a voxelized mesh.
By [Karim Naaji](https://github.com/karimnaaji).

<br>

**Installation**

Run:

```sh
$ npm i voxelizer.c
```

And then include `voxelizer.h` as follows:

```c
// main.c
#define VOXELIZER_IMPLEMENTATION
#include "node_modules/voxelizer.c/voxelizer.h"

int main() { /* ... */ }
```

And then compile with `clang` or `gcc` as usual.

```bash
$ clang main.c  # or, use gcc
$ gcc   main.c
```

You may also use a simpler approach:

```c
// main.c
#define VOXELIZER_IMPLEMENTATION
#include <voxelizer.h>

int main() { /* ... */ }
```

If you add the path `node_modules/voxelizer.c` to your compiler's include paths.

```bash
$ clang -I./node_modules/voxelizer.c main.c  # or, use gcc
$ gcc   -I./node_modules/voxelizer.c main.c
```

<br>

**Usage**

To generate a voxelized mesh, create an instance of `vx_mesh_t` and initialize its
vertices and indices like this:

```c
vx_mesh_t* mesh;
vx_mesh_t* result;

mesh = vx_mesh_alloc(nvertices, nindices);

// Add vertices and indices from the original mesh you want to voxelize
// [...]

// Precision factor to reduce "holes" artifact
float precision = 0.01;

// Run voxelization
result = vx_voxelize(mesh, 0.025, 0.025, 0.025, precision);

vx_mesh_free(result);
vx_mesh_free(mesh);
```

<br>
<br>


[![SRC](https://img.shields.io/badge/src-repo-green?logo=Org)](https://github.com/karimnaaji/voxelizer)
[![ORG](https://img.shields.io/badge/org-nodef-green?logo=Org)](https://nodef.github.io)
![](https://ga-beacon.deno.dev/G-RC63DPBH3P:SH3Eq-NoQ9mwgYeHWxu7cw/github.com/nodef/voxelizer.c)
