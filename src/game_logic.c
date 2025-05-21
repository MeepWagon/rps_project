#include "gtk-4.0/gtk/gtk.h"

typedef struct {
    GtkBox* box;
    GtkWidget* after_element;
    bool Success;
} buttondata;

int player_selection = 1;

void on_selection(int selection_number) {    
    player_selection = selection_number;
}

void on_selection_confirm(GtkButton* button, gpointer data) {
    buttondata* button_data = (buttondata*) data;
    
    GtkWidget* label = gtk_label_new("testing");
    gtk_box_insert_child_after(button_data->box, label, button_data->after_element);
}