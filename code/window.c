#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void fill_buffer(uint32_t *array, int width, int height, uint32_t color) {

        for (int y = 0; y<height; y++) {

            for (int x = 0; x<width; x++) {
                array[(y * width) + x] = color;
            }

         }

}

uint32_t make_color(uint8_t r, uint8_t g, uint8_t b) {
    return r<<16 | g<<8 | b;
}

int main(void) {
    int width = 640;
    int height = 480;
    uint32_t color;

    uint8_t red;
    uint8_t green;
    uint8_t blue;

    color = red << 16 | green << 8 | blue;

    uint32_t *array = (uint32_t *) malloc(width*height*sizeof(uint32_t));

    if (array == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    fill_buffer(array, width, height, color);

    free(array);

}
