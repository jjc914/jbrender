#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>

#include "math.h"
#include "input.h"
#include "screen.h"
#include "world.h"
#include "fileobj.h"

/*
 TODO: URGENT
 - add bouding boxes to optimize rasterization algorithm
 - rgb that gets converted into discrete color
 - randomly colored triangles? (so i can see the models better ;-;)
 - finished event should be done better
 
 TODO: NOT URGENT
 - obj writing (extend obj package)
 - implement actual triangulation algorithm instead of just quad triangulation
 */


int finished = 0;

float x = M_PI / 2, y = 0.001, z;
void onKeyPress(char* kseq, int len) {
    switch (kseq[2]) {
        case 'A': // up arrow
            x -= 0.05;
            break;
        case 'B': // down arrow
            x += 0.05;
            break;
        case 'C': // right arrow
            y += 0.05;
            break;
        case 'D': // left arrow
            y -= 0.05;
            break;
        default:
            finished = 1;
            break;
    }
    fflush(stdout);
}

int main() {
    // TODO: wrapper for terminal?
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    char keys[18] = {
        'q',   0,   0,
         27,   0,   0,
         27, '[', 'A',
         27, '[', 'B',
         27, '[', 'C',
         27, '[', 'D'
    };
    kblistener_t kbl;
    kbl_alloc(&kbl, 6, 3, &onKeyPress);
    kbl_set(&kbl, keys, 18);
    kbl_start(&kbl);
    
    screen_t screen;
    scr_alloc(&screen, w.ws_row, w.ws_col);

    camera_t camera;
    const double characterRatio = 1.75966494845;
    cam_alloc(&camera, (float)(w.ws_row) / (w.ws_col) * characterRatio, 40, 1, 10);
    
    object_t objects[3];
    {
        mesh_t mesh;
        if (fobj_read("../skull.obj", &mesh)) {
            return -1;
        }
        mesh_triangulate(&mesh);
        
        vector_t position, rotation, scale;
        obj_cpy_mesh(&objects[0], &mesh);
        
        obj_setposval(&objects[0], -0.5, -0.32, 2.3);
        obj_setrotval(&objects[0], 0, 0, 0);
        obj_setscaleval(&objects[0], 0.4, -0.4, -0.4);
        mesh_free(&mesh);
    }

    {
        mesh_t mesh;
        if (fobj_read("../pyramid.obj", &mesh)) {
            return -1;
        }
        mesh_triangulate(&mesh);
        
        vector_t position, rotation, scale;
        obj_cpy_mesh(&objects[1], &mesh);
        
        obj_setposval(&objects[1], 0.5, -0.32, 2.3);
        obj_setrotval(&objects[1], 0, 0, 0);
        obj_setscaleval(&objects[1], 0.4, -0.4, -0.4);
        mesh_free(&mesh);
    }
    
    {
        mesh_t mesh;
        if (fobj_read("../hello.obj", &mesh)) {
            return -1;
        }
        mesh_triangulate(&mesh);
        
        vector_t position, rotation, scale;
        obj_cpy_mesh(&objects[2], &mesh);
        
        obj_setposval(&objects[2], 0, 0.4, 2.3);
        obj_setrotval(&objects[2], 0, 0, 0);
        obj_setscaleval(&objects[2], 0.9, 0.9, -0.9);
        mesh_free(&mesh);
    }

    world_t world;
    world_alloc(&world, &camera, sizeof(objects) / sizeof(object_t), objects);
    
    printf("%s", CURSOR_HIDE);
    while (!finished) {
        struct timespec frameStart, frameEnd;
        clock_gettime(CLOCK_MONOTONIC_RAW, &frameStart);
        scr_clear(&screen);

        // do things
        obj_setrotval(&objects[0], x-M_PI/2, y, z);
        obj_setrotval(&objects[1], x-M_PI/2, y, z);
        obj_setrotval(&objects[2], x, y, z);

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
    kbl_stop(&kbl);
    kbl_free(&kbl);
    return 0;
}

// TODO: test two objects, seems to have some error