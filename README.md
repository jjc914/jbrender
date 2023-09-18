# JBrender
A terminal rasterizer written in C. 

<img src="/res/jbrender.gif" height="300"/>

## Description
JBrender is a simple rasterizer written for educational purposes. It includes a threaded keyboard listener to respond to input and an obj reader to import models. Due to the structure of the codebase, it is easy to edit the scene programmatically, adding, moving, or rotating objects, etc. 

For the time being, the rasterizer lacks significant optimization. Furthermore, the obj reader does not include an effective triangulator for unconventional models. 

## To Build
1. Clone this repo:
```
git clone https://github.com/jjc914/jbrender.git
```
2. Make a build folder within the project folder and change directory:
```
mkdir build
cd build
```
3. Build the project and run:
```
cmake ..
cmake --build .
bin/jbrender
```

## Usage
To render, the following code can be used:
```c
screen_t screen;
scr_alloc(&screen, screenWidth, screenHeight);

camera_t camera;
cam_alloc(&camera, (float)(screenWidth) / w.ws_col, 40, 1, 10);

object_t objects[1];
mesh_t mesh;
if (fobj_read("model.obj", &mesh)) {
    return -1;
}
mesh_triangulate(&mesh);

vector_t position, rotation, scale;
obj_cpy_mesh(&objects[0], &mesh);

obj_setposval(&objects[0], 0, 0, 1);
obj_setrotval(&objects[0], 0, 0, 0);
obj_setscaleval(&objects[0], 1, 1, 1);
mesh_free(&mesh);

world_t world;
world_alloc(&world, &camera, sizeof(objects) / sizeof(object_t), objects);

printf("%s", CURSOR_HIDE);
while (!finished) {
    struct timespec frameStart, frameEnd;
    clock_gettime(CLOCK_MONOTONIC_RAW, &frameStart);
    scr_clear(&screen);
  
    // do something here
  
    scr_render(&screen, &world);
    scr_print(&screen);
    
    clock_gettime(CLOCK_MONOTONIC_RAW, &frameEnd);
    uint64_t deltaTime = (frameEnd.tv_sec - frameStart.tv_sec) * 1000000 + (frameEnd.tv_nsec - frameStart.tv_nsec) / 1000;
    if (5000 > deltaTime) usleep(5000 - deltaTime);
}
printf("%s", CURSOR_SHOW);

// clean up
scr_free(&screen);
cam_free(&camera);
for (int i = 0; i < sizeof(objects) / sizeof(object_t); ++i) {
    obj_free(&objects[i]);
}
```

Additionally, the keyboard listener can be used by the following:
```c
void onKeyPress(char* kseq, int len) {
    // handle key sequence kseq with length len
    fflush(stdout);
}

int main() {
    char keys[18] = {
        'q',   0,   0, // q
         27,   0,   0, // esc
         27, '[', 'A', // up
         27, '[', 'B', // down
         27, '[', 'C', // right
         27, '[', 'D'  // left
    };

    kblistener_t kbl;
    kbl_alloc(&kbl, 6, 3, &onKeyPress); // allocate keyboard with number of key sequences and keys per sequence
    kbl_set(&kbl, keys, 18);
    kbl_start(&kbl);

    while (!finished) {
        // do whatever
    }

    kbl_stop(&kbl);
    kbl_free(&kbl);
}
```

For further examples, read `main.cpp`. 

## To Do
- [ ] Implement Phong shading model
- [ ] Improved triangulation algorithm for non-quad geometry
- [ ] Only check point-triangle intersection for triangles within the bounding box of the frustum
- [ ] Different materials for objects
- [ ] Read materials from obj
- [ ] Remove global variables and find a better way for the keyboard listener to interact with main code
