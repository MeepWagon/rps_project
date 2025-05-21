#include "gtk-4.0/gtk/gtk.h"

typedef struct {
    GtkWidget* after_element;
    bool Success;
} confirm_data;

int decision_array[3] = {2, 3, 1};

int player_selection = 1;
int cpu_selection = 1;

void on_selection(int selection_number) {    
    player_selection = selection_number;

    // Change selection icon
}

void on_selection_confirm(GtkButton* button, gpointer data) {
    // CPU selects an option

    // change CPU selection icon
    
    GtkBox* parent = gtk_widget_get_parent(button_data->after_element);
    buttondata* button_data = (buttondata*) data;
    char* winning_status_string;
    
    if (player_selection == cpu_selection) {
        winning_status_string = "It's a tie!";
    } else if (decision_array[player_selection] == cpu_selection) {
        winning_status_string = "Player wins!";
    } else if (decision_array[cpu_selection] == player_selection) {
        winning_status_string = "CPU wins...";
    }
    
    if (gtk_widget_find_first_child(parent, "winning_status") == NULL) { return; }
    
    GtkWidget* label = gtk_label_new(winning_status_string);
    gtk_box_insert_child_after(
        parent,
        label,
        button_data->after_element
    );
}