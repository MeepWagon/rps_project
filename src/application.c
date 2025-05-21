#include <gtk-4.0/gtk/gtk.h>

#include "utils.h"
#include "game_logic.h"

GtkApplication* app;
GtkWidget* window;
GdkDisplay* display;
GtkWidget* image;
GtkBuilder* builder;
GtkCssProvider* provider;
GtkWidget* button;
GtkBox* csidebox;
GtkWidget* c_selection_icon;

void app_activate(GtkApplication *app, gpointer user_data) {
    // Get UI file path
    int buffer_max = 428;
    char ui_path_buffer[buffer_max];
    get_ui_path(ui_path_buffer, buffer_max);
    
    // Initialize widgets
    builder = gtk_builder_new_from_file(ui_path_buffer);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    button = GTK_WIDGET(gtk_builder_get_object(builder, "selection-confirm"));
    csidebox = GTK_BOX(gtk_builder_get_object(builder, "c-side"));
    c_selection_icon = GTK_WIDGET(gtk_builder_get_object(builder, "c-selection-icon"));

    // Configure window
    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_window_set_title (GTK_WINDOW (window), "RPS Project");
    gtk_window_present(GTK_WINDOW (window));

    
    // Load "loading.svg" icon
    // Note: Eventually, I want all the images to be loaded using
    // a gresource file. Or, a special rule to load everything via a
    // gresource file.
    // int image_buffer_max = 428;
    // char* image_path_buffer[image_buffer_max];
    // get_exe_dir(image_path_buffer, image_buffer_max);
    // image = GTK_WIDGET(gtk_builder_get_object(builder, "test_icon"));
    // char* image_path = g_build_filename(image_path_buffer, "assets", "loading.svg", NULL);
    // gtk_image_set_from_file(GTK_IMAGE(image), image_path);
    
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

    buttondata* data = g_new(buttondata, 1);
    data->box = csidebox;
    if (csidebox == NULL) {
        g_error("Failed to get c-side box from builder");
    }
    data->success = true;
    data->after_element = c_selection_icon;
    g_signal_connect(button, "clicked", G_CALLBACK(on_selection_confirm), data);
}

void app_exit() {
    g_object_unref(app);
    g_object_unref(builder);
}