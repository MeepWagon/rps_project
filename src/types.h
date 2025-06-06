#ifndef TYPES_H
#define TYPES_H

#include <gtk-4.0/gtk/gtk.h>

// Widget data types
typedef struct {
    GtkWidget* after_element;
} confirm_data;

typedef struct {
    int selection_number;
    GtkWidget* image;
} selection_data;

// Widget linked list
typedef struct list_node {
    GtkWidget* widget;
    char* name;
    struct list_node* next;
} list_node;

#endif
