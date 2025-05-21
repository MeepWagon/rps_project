#include "libgen.h"
#include "stdio.h"

// I know this is not a lot of utility functions for a whole file,
// but if I need to expand this helps. Its also just to expose me
// to the structure of how I should logically be separating 
// different parts of my code. 

// Needs error checking
// Not cross platform
void get_exe_dir(char* buffer, int buffer_max) {
    int len = readlink("/proc/self/exe", buffer, buffer_max);
    buffer[len] = '\0';
    buffer = dirname(buffer);
}

void get_ui_path(char* buffer, int buffer_max) {
    get_exe_dir(buffer, buffer_max);
    sprintf(buffer, "%s%s", buffer, "/main.ui");
}