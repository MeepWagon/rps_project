#include "gtk-4.0/gtk/gtk.h"

// Types
typedef struct {
    GtkWidget* after_element;
} confirm_data;

typedef struct {
    int selection_number;
    GtkWidget* image;
} selection_data;

// Public Methods
void on_selection(GtkWidget* button, gpointer selection_number);
void on_selection_confirm(GtkButton* button, gpointer data);
