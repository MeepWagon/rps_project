#include "gtk-4.0/gtk/gtk.h"

typedef struct {
    GtkBox* box;
    GtkWidget* after_element;
    bool success;
} confirm_data;

void on_selection(int selection_number);
void on_selection_confirm(GtkButton* button, gpointer data);

