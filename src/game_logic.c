#include "gtk-4.0/gtk/gtk.h"
#include <stdint.h>
#include <stdlib.h>

#include "game_logic.h"
#include "utils.h"

int decision_array[] = {1, 2, 0};

int player_selection = 0;
int cpu_selection = 0;

bool game_state = true;

void on_selection(GtkWidget* button, gpointer data) {    
    selection_data* select_data = (selection_data*)data;
    player_selection = select_data->selection_number;
    
    // Change selection icon
    if (player_selection == 1) {
	load_icon(select_data->image, "rock.svg");
    } else if (player_selection == 2) {
	load_icon(select_data->image, "paper.svg");
    } else if (player_selection == 3) {
	load_icon(select_data->image, "loading.svg");
    }
}

GtkWidget* result_label = NULL; 
void on_selection_confirm(GtkButton* button, gpointer data) {
    confirm_data* button_data = (confirm_data*)data;
    GtkWidget* parent = gtk_widget_get_parent(button_data->after_element);

    if (game_state == false ) {
	gtk_widget_set_visible(result_label, false);
	load_icon(button_data->after_element, "question-mark.svg");
	g_object_set(button, "label", "Confirm Selection", NULL);
	game_state = !game_state;
	return;
    }
    
    // CPU selects an option & changes CPU selection icon
    cpu_selection = rand() % 2;
    if (cpu_selection == 0) {
	load_icon(button_data->after_element, "rock.svg");
    } else if (cpu_selection == 1) {
	load_icon(button_data->after_element, "paper.svg");
    } else if (cpu_selection == 2) {
	load_icon(button_data->after_element, "scissors.svg");
    }
    
    char* winning_status_string;
    if (player_selection == cpu_selection) {
        winning_status_string = "It's a tie!";
    } else if (decision_array[player_selection] == cpu_selection) {
        winning_status_string = "Player wins!";
    } else if (decision_array[cpu_selection] == player_selection) {
        winning_status_string = "CPU wins...";
    } else {
	winning_status_string = "ERROR!";
    }
    
    if (result_label == NULL) {
	//g_log(NULL, G_LOG_LEVEL_ERROR, "aaaa");
	result_label = gtk_label_new(winning_status_string);
	gtk_widget_add_css_class(result_label, "title-font");
	gtk_box_insert_child_after(
	    GTK_BOX(parent),
	    result_label,
	    button_data->after_element
	);
    } else {
	gtk_widget_set_visible(result_label, true);
    }
    
    g_object_set(button, "label", "Restart Game?", NULL);
    game_state = !game_state;
}
