#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

void fill_buffer(uint32_t *array, int width, int height, uint32_t color) {

        for (int y = 0; y<height; y++) {

            for (int x = 0; x<width; x++) {
                array[(y * width) + x] = color;
            }

         }

}

uint32_t make_color(uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
    return a<<24 | r<<16 | g<<8 | b;
}

int main(void) {
    // hardcoded the window size for now, to change later(?)
    int width = 640;
    int height = 480;

    uint32_t color;
    uint8_t alpha;
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    //ask for color:


    color = make_color(alpha, red, green, blue);


    // initialize pixel buffer array
    uint32_t *array = (uint32_t *) malloc(width*height*sizeof(uint32_t));

    if (array == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    // X11 Setup
    Display *display = XOpenDisplay(NULL);
    Window window = XCreateSimpleWindow(display, DefaultRootWindow(display), );
    // Setup the key to exit
    // then XMapWindow
    // then while true loop, with a call to my fill_buffer() function, and waiting for an exit keypress



    //fill_buffer(array, width, height, color);

    free(array);

}
