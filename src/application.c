#include <gtk-4.0/gtk/gtk.h>

#include "utils.h"
#include "game_logic.h"
#include "widget_manager.h"

GtkWidget* window;
GdkDisplay* display;
GtkCssProvider* provider;

void app_activate(GtkApplication *app, gpointer user_data) {
    // TODO: Change to PATH_MAX
    int buffer_max = 426;
    // Get UI file path
    char ui_path_buffer[buffer_max];
    get_ui_path(ui_path_buffer, buffer_max);

    // Array of all widget IDs in UI file
    char* widget_id_array[] = {
	"window",
	"selection_confirm",
	"c_side",
	"c_selection_icon",
	"selection_icon",
	"rock",
	"paper",
	"scissors"
    };
    
    // TODO: All initialization of widgets should be done with instance manager
    // Initialize widgets
    window = manager_get_widget("window");
    provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    
    widget_manager_setup(
	    widget_id_array,
	    sizeof(widget_id_array) / sizeof(char*)
    );

    if (!display) {
	g_error("Failed to get default display");
    }
    
    // Configure window
    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_window_set_title(GTK_WINDOW (window), "RPS Project");
    gtk_window_present(GTK_WINDOW (window));
    
    // Load CSS
    // change "build/main.css", not portable.
    char css_path_buffer[buffer_max];
    get_exe_dir(css_path_buffer, buffer_max);
    sprintf(css_path_buffer, "%s%s", css_path_buffer, "/main.css");
    
    gtk_css_provider_load_from_path(provider, css_path_buffer);
    gtk_style_context_add_provider_for_display(
        display,
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );

    GtkWidget* image = manager_get_widget("selection_icon"); 

    // These need to be initialized in the asset manager
    confirm_data* data = (confirm_data*)manager_set_widget_data(
	"after_element",
	manager_get_widget("c_selection_icon"),
	NULL
    )
    confirm_data* data = g_new(confirm_data, 1);
    data->after_element = manager_get_widget("c_selection_icon");
    g_signal_connect(manager_get_widget("selection_confirm"), "clicked", G_CALLBACK(on_selection_confirm), data);

    confirm_data* rock_data = 
    selection_data* rock_data = g_new(selection_data, 1);
    rock_data->image = image;
    rock_data->selection_number = 0; 
    g_signal_connect(manager_get_widget("rock"), "clicked", G_CALLBACK(on_selection), (gpointer)rock_data);

    selection_data* paper_data = g_new(selection_data, 1);
    paper_data->image = image;
    paper_data->selection_number = 1;
    g_signal_connect(manager_get_widget("paper"), "clicked", G_CALLBACK(on_selection), (gpointer)paper_data);

    selection_data* scissors_data = g_new(selection_data, 1);
    scissors_data->image = image;
    scissors_data->selection_number = 2;
    g_signal_connect(manager_get_widget("scissors"), "clicked", G_CALLBACK(on_selection), (gpointer)scissors_data);
}

void app_exit() {
    //gtk_style_context_remove_provider_for_display(display, GTK_STYLE_PROVIDER(provider));
    //g_object_unref(provider);
    //g_object_unref(app);
    //g_object_unref(builder);
}
