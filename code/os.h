#pragma once

typedef struct os_window os_window;

void os_init();
os_window* os_create_window(int width, int height, const char* title);

void os_get_pixel_buffer_info(os_window* window, void** pixel_buffer, void** temp_pixel_buffer, int32_t* width, int32_t* height, uint32_t* stride);
