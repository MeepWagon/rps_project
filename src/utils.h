#ifndef UTILS_H
#define UTILS_H

#include "gtk-4.0/gtk/gtk.h"
#include "libgen.h"

void get_exe_dir(char* buffer, int buffer_max);
void get_ui_path(char* buffer, int buffer_max);
void load_icon(GtkWidget* image, char* asset_name);

#endif
