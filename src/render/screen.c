#include "screen.h"

static void raster_triangle(screen_t* screen, vector_t ndcv1, vector_t ndcv2, vector_t ndcv3) {
    // TODO: should only search the bounding box
    // TODO: parallelize
    // convert ndc to pixel
    vector_t v1, v2, v3;
    vec_alloc(&v1, 3);
    v1.data[0] = ((ndcv1.data[0] + 1.0) / 2.0) * screen->bwidth * BLOCK_WIDTH;
    v1.data[1] = ((ndcv1.data[1] + 1.0) / 2.0) * screen->bheight * BLOCK_HEIGHT;
    v1.data[2] = ndcv1.data[2];
    vec_alloc(&v2, 3);
    v2.data[0] = ((ndcv2.data[0] + 1.0) / 2.0) * screen->bwidth * BLOCK_WIDTH;
    v2.data[1] = ((ndcv2.data[1] + 1.0) / 2.0) * screen->bheight * BLOCK_HEIGHT;
    v2.data[2] = ndcv2.data[2];
    vec_alloc(&v3, 3);
    v3.data[0] = ((ndcv3.data[0] + 1.0) / 2.0) * screen->bwidth * BLOCK_WIDTH;
    v3.data[1] = ((ndcv3.data[1] + 1.0) / 2.0) * screen->bheight * BLOCK_HEIGHT;
    v3.data[2] = ndcv3.data[2];
    
    // prepare barycentric coordinates
    float xv1 = v1.data[0];
    float xv2 = v2.data[0];
    float xv3 = v3.data[0];
    float yv1 = v1.data[1];
    float yv2 = v2.data[1];
    float yv3 = v3.data[1];
    
    vector_t point;
    vec_alloc(&point, 3);
    for (point.data[1] = 0; point.data[1] < screen->bheight * BLOCK_HEIGHT; point.data[1]++) {
        for (point.data[0] = 0; point.data[0] < screen->bwidth * BLOCK_WIDTH; point.data[0]++) {
            // barycentric coordinates
            float xp = point.data[0];
            float yp = point.data[1];
            
            float wv1 = ((yv2 - yv3) * (xp - xv3) + (xv3 - xv2) * (yp - yv3)) / ((yv2 - yv3) * (xv1 - xv3) + (xv3 - xv2) * (yv1 - yv3));
            float wv2 = ((yv3 - yv1) * (xp - xv3) + (xv1 - xv3) * (yp - yv3)) / ((yv2 - yv3) * (xv1 - xv3) + (xv3 - xv2) * (yv1 - yv3));
            float wv3 = 1 - wv1 - wv2;
            
            // check triangle-point intersection
            if (wv1 > 0 && wv2 > 0 && wv3 > 0) {
                point.data[2] = v1.data[2] * wv1 + v2.data[2] * wv2 + v3.data[2] * wv3;
                // check depth buffer
                if (point.data[2] >= 0 && point.data[2] <= 1) {
                    if (point.data[2] < screen->depth_buffer[(int)point.data[1] * screen->bwidth * BLOCK_WIDTH + (int)point.data[0]]) {
                        scr_set(screen, point.data[1], point.data[0], 1);
                        screen->depth_buffer[(int)point.data[1] * screen->bwidth * BLOCK_WIDTH + (int)point.data[0]] = point.data[2];
                    }
                }
            }
        }
    }
    vec_free(&v1);
    vec_free(&v2);
    vec_free(&v3);
    vec_free(&point);
}

void block_init(block_t* block) {
    block->color_code = F_DEFAULT;
    block->data = 0b0000;
}

int block_set(block_t* block, int y, int x, int val) {
    if (y < 0 || y > BLOCK_HEIGHT - 1 || x < 0 || x > BLOCK_WIDTH - 1) return 1;
    if (val) {
        block->data |= 0b1000 >> (BLOCK_WIDTH * y + x);
    } else {
        block->data &= ~(0b1000 >> (BLOCK_WIDTH * y + x));
    }
    return 0;
}

void block_setcolor(block_t* block, const char* color) {
    block->color_code = color;
}

int block_setall(block_t* block, uint8_t data, const char* color) {
    if (data < 0b0000 || data > 0b1111) return 1;
    block->color_code = color;
    block->data = data;
    return 0;
}

//void block_print(block_t* block) {
//    printf("%s", block->color_code);
//    switch(block->data) {
//        case 0b000000:
//            printf("⠀");
//            break;
//        case 0b100000:
//            printf("⠁");
//            break;
//        case 0b010000:
//            printf("⠈");
//            break;
//        case 0b001000:
//            printf("⠂");
//            break;
//        case 0b000100:
//            printf("⠐");
//            break;
//        case 0b000010:
//            printf("⠄");
//            break;
//        case 0b000001:
//            printf("⠠");
//            break;
//        case 0b110000:
//            printf("⠉");
//            break;
//        case 0b101000:
//            printf("⠃");
//            break;
//        case 0b100100:
//            printf("⠑");
//            break;
//        case 0b100010:
//            printf("⠅");
//            break;
//        case 0b100001:
//            printf("⠡");
//            break;
//        case 0b011000:
//            printf("⠊");
//            break;
//        case 0b010100:
//            printf("⠘");
//            break;
//        case 0b010010:
//            printf("⠌");
//            break;
//        case 0b010001:
//            printf("⠨");
//            break;
//        case 0b001100:
//            printf("⠒");
//            break;
//        case 0b001010:
//            printf("⠆");
//            break;
//        case 0b001001:
//            printf("⠢");
//            break;
//        case 0b000110:
//            printf("⠔");
//            break;
//        case 0b000101:
//            printf("⠰");
//            break;
//        case 0b000011:
//            printf("⠤");
//            break;
//        case 0b111000:
//            printf("⠋");
//            break;
//        case 0b110100:
//            printf("⠙");
//            break;
//        case 0b110010:
//            printf("⠍");
//            break;
//        case 0b110001:
//            printf("⠩");
//            break;
//        case 0b101100:
//            printf("⠓");
//            break;
//        case 0b101010:
//            printf("⠇");
//            break;
//        case 0b101001:
//            printf("⠣");
//            break;
//        case 0b100110:
//            printf("⠕");
//            break;
//        case 0b100101:
//            printf("⠱");
//            break;
//        case 0b100011:
//            printf("⠥");
//            break;
//        case 0b011100:
//            printf("⠚");
//            break;
//        case 0b011010:
//            printf("⠎");
//            break;
//        case 0b011001:
//            printf("⠪");
//            break;
//        case 0b010110:
//            printf("⠜");
//            break;
//        case 0b010101:
//            printf("⠸");
//            break;
//        case 0b010011:
//            printf("⠬");
//            break;
//        case 0b001110:
//            printf("⠖");
//            break;
//        case 0b001101:
//            printf("⠲");
//            break;
//        case 0b001011:
//            printf("⠦");
//            break;
//        case 0b000111:
//            printf("⠴");
//            break;
//
//        case 0b111100:
//            printf("");
//            break;
//        case 0b111010:
//            printf("");
//            break;
//        case 0b111001:
//            printf("");
//            break;
//        case 0b110110:
//            printf("");
//            break;
//        case 0b110101:
//            printf("");
//            break;
//        case 0b110011:
//            printf("");
//            break;
//        case 0b101110:
//            printf("");
//            break;
//        case 0b101101:
//            printf("");
//            break;
//        case 0b101011:
//            printf("");
//            break;
//        case 0b100111:
//            printf("");
//            break;
//
//        case 0b011110:
//            printf("");
//            break;
//        case 0b011101:
//            printf("");
//            break;
//        case 0b011011:
//            printf("");
//            break;
//        case 0b010111:
//            printf("");
//            break;
//        case 0b001111:
//            printf("");
//            break;
//
//        case 0b111111:
//            printf("⠿");
//            break;
//        default:
//            break;
//    }
//    printf("%s", F_DEFAULT);
//}

void block_print(block_t* block) {
    printf("%s", block->color_code);
    switch(block->data) {
        case 0b0000:
            printf(" ");
            break;
        case 0b1000:
            printf("▘");
            break;
        case 0b1100:
            printf("▀");
            break;
        case 0b1010:
            printf("▌");
            break;
        case 0b1001:
            printf("▚");
            break;
        case 0b1110:
            printf("▛");
            break;
        case 0b1101:
            printf("▜");
            break;
        case 0b1011:
            printf("▙");
            break;
        case 0b0100:
            printf("▝");
            break;
        case 0b0110:
            printf("▞");
            break;
        case 0b0101:
            printf("▐");
            break;
        case 0b0111:
            printf("▟");
            break;
        case 0b1111:
            printf("█");
            break;
        case 0b0010:
            printf("▖");
            break;
        case 0b0011:
            printf("▄");
            break;
        case 0b0001:
            printf("▗");
            break;
        default:
            break;
    }
    printf("%s", F_DEFAULT);
}

void scr_alloc(screen_t* screen, int bheight, int bwidth) {
    screen->bheight = bheight;
    screen->bwidth = bwidth;
    screen->color_buffer = malloc(bheight * bwidth * sizeof(block_t));
    for (int i = 0; i < bheight * bwidth; ++i) {
        block_init(&screen->color_buffer[i]);
    }
    screen->depth_buffer = malloc(bheight * bwidth * BLOCK_HEIGHT * BLOCK_WIDTH * sizeof(float));
    for (int i = 0; i < screen->bheight * screen->bwidth * BLOCK_HEIGHT * BLOCK_WIDTH; ++i) {
        screen->depth_buffer[i] = 2;
    }
}

void scr_free(screen_t* screen) {
    free(screen->color_buffer);
    free(screen->depth_buffer);
}

int scr_set(screen_t* screen, int y, int x, int val) {
    if (y < 0 || y > screen->bheight * BLOCK_HEIGHT - 1 || x < 0 || x > screen->bwidth * BLOCK_WIDTH - 1) return 1;
    int by = y / BLOCK_HEIGHT;
    int bx = x / BLOCK_HEIGHT;
    int dy = y % BLOCK_HEIGHT;
    int dx = x % BLOCK_WIDTH;
    return block_set(&screen->color_buffer[by * screen->bwidth + bx], dy, dx, val);
}

int scr_getblock(screen_t* screen, block_t** block, int y, int x) {
    if (y < 0 || y > screen->bheight - 1 || x < 0 || x > screen->bwidth - 1) return 1;
    *block = &screen->color_buffer[y * screen->bwidth + x];
    return 0;
}

int scr_setall(screen_t* screen, uint8_t* data, int len) {
    if (screen->bheight * screen->bwidth != len) return 1;
    for (int i = 0; i < len; ++i) {
        screen->color_buffer[i].data = data[i];
    }
    return 0;
}

void scr_render(screen_t* screen, world_t* world) {
    camera_t* camera = world->camera;
    object_t* objects = world->objects;
    
    for (int i = 0; i < world->objects_length; ++i) {
        for (int k = 0; k < objects[i].indices_length; k+=3) {
            int i1 = objects[i].indices[k];
            int i2 = objects[i].indices[k+1];
            int i3 = objects[i].indices[k+2];
            
            // local space
            vector_t lv1 = objects[i].vertices[i1];
            vector_t lv2 = objects[i].vertices[i2];
            vector_t lv3 = objects[i].vertices[i3];
            
            // construct mvp matrix
            matrix_t vp, mvp;
            mm_multiply(&vp, camera->projection_matrix, camera->view_matrix);
            mm_multiply(&mvp, vp, objects[i].model_matrix);

            // clip space
            vector_t cv1, cv2, cv3;
            mv_multiply(&cv1, mvp, lv1);
            mv_multiply(&cv2, mvp, lv2);
            mv_multiply(&cv3, mvp, lv3);

            // normalized screen space (perspective divide)
            vec_scale(&cv1, 1 / cv1.data[3]);
            vec_scale(&cv2, 1 / cv2.data[3]);
            vec_scale(&cv3, 1 / cv3.data[3]);

            raster_triangle(screen, cv1, cv2, cv3);
        }
    }

    for (int y = 0; y < screen->bheight; y++) {
        for (int x = 0; x < screen->bwidth; x++) {
            block_t* block;
            scr_getblock(screen, &block, y, x);
            float average = 0;
            for (int dy = 0; dy < BLOCK_HEIGHT; dy++) {
                for (int dx = 0; dx < BLOCK_WIDTH; dx++) {
                    int ry = y * BLOCK_HEIGHT + dy;
                    int rx = x * BLOCK_WIDTH + dx;
                    average += screen->depth_buffer[ry * screen->bwidth * BLOCK_WIDTH + rx];
                }
            }
            average /= (float)BLOCK_HEIGHT * BLOCK_WIDTH;

            const char* color;
            if (average < 0.4) {
                color = F_WHITE;
            } else if (average < 0.6) {
                color = F_DARK_WHITE;
            } else if (average < 0.8) {
                color = F_BRIGHT_BLACK;
            } else {
                color = F_BLACK;
            }
            block_setcolor(block, color);
        }
    }
}

void scr_clear(screen_t* screen) {
    for (int i = 0; i < screen->bheight * screen->bwidth; ++i) {
        block_setall(&screen->color_buffer[i], 0b0000, F_DEFAULT);
    }
    for (int i = 0; i < screen->bheight * screen->bwidth * BLOCK_HEIGHT * BLOCK_WIDTH; ++i) {
        screen->depth_buffer[i] = 2;
    }
}

void scr_print(screen_t* screen) {
    printf("%s", CURSOR_RETURN);
    for (int y = 0; y < screen->bheight; y++) {
        for (int x = 0; x < screen->bwidth; x++) {
            block_print(&screen->color_buffer[y * screen->bwidth + x]);
        }
        printf("\n");
    }
}

