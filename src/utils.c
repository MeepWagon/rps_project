#include "gtk-4.0/gtk/gtk.h"

#include "libgen.h"
#include "stdio.h"

// I know this is not a lot of utility functions for a whole file,
// but if I need to expand this helps. Its also just to expose me
// to the structure of how I should logically be separating 
// different parts of my code. 

// TODO: Methods that return path
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

// Note: Maybe it would be better to implement a searching algorithm for this?
// Usage: find_first_child_of_widget(parent_widget*, widget_id)
GtkWidget* find_first_child_of_widget(GtkWidget* Container, const char* id) {
    GtkWidget* child = gtk_widget_get_first_child(Container);
    if (child == NULL) {
        g_error("Container has no children");
    }

    while (child != NULL) {
        if (strcmp(gtk_widget_get_name(child), id) == 0) {
            child = gtk_widget_get_next_sibling(child);
        } else {
            return child;
        }
    }
    
    return NULL;
}

void load_icon(GtkWidget* image, const char* asset_name) {
    // Note: Eventually, I want all the images to be loaded using
    // a gresource file. Or, a macro that says to load resources
    // using a gresource file.
    int image_buffer_max = 428;
    char image_path_buffer[image_buffer_max];
    get_exe_dir(image_path_buffer, image_buffer_max);
    
    char* image_path = g_build_filename(image_path_buffer, "assets", asset_name, NULL);
    //g_message("%s", G_OBJECT_TYPE_NAME(image));
    gtk_image_set_from_file(GTK_IMAGE(image), image_path);

    g_free(image_path);
}
