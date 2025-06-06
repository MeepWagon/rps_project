// TODO:
// Method for creating a widget
// Method for removing a widget
// Method for getting a widget
// Method for changing widget callback

#include <gtk-4.0/gtk/gtk.h>
#include <stdlib.h>
#include <stdarg.h>

#include "types.h"
#include "utils.h"

GtkBuilder* builder = NULL;
list_node* start_node = NULL;
char** widget_id_array = NULL;

void widget_manager_setup(char** _widget_id_array, int array_length) {
    // Create builder
    char ui_path_buffer[PATH_MAX];
    get_ui_path(ui_path_buffer, PATH_MAX);
    builder = gtk_builder_new_from_file(ui_path_buffer);

    // Set globals
    widget_id_array = _widget_id_array;
    
    list_node* old_node = NULL;
    for (int i=0; i<array_length; i++) {
	list_node* node = (list_node*)malloc(sizeof(list_node)); 
	node->widget = GTK_WIDGET(gtk_builder_get_object(builder, widget_id_array[i]));
	node->name = widget_id_array[i];
	if (i > 0) {
	    old_node->next = node;
	} else if (i == 0) {
	    start_node = node;
	}
	old_node = node;

	// In widget_manager_setup(), after getting each widget:
	//g_message("Widget '%s' is type: %s", widget_id_array[i], G_OBJECT_TYPE_NAME(node->widget));
    }
}

void widget_manager_exit() {

}

void manager_set_widget_data() {
}

// Setters
void manager_add_widget() {
}

// Getters
GtkWidget* manager_get_widget(const char* widget_name) {
    list_node* current_node = start_node;
    while (current_node != NULL) {
	if (strcmp(current_node->name, widget_name) == 0) {
		return current_node->widget;
	    } else {
		current_node = current_node->next;
	}
    }

    g_message("%s is NULL", widget_name);
    return NULL;
}

void* 

// Probably unnecessary. Remove later.
GtkBuilder* get_builder() {
    return builder;
}
