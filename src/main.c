#include "gtk-4.0/gtk/gtk.h"
#include "libgen.h"

GtkWidget* window;

GtkBuilder* builder;

// Needs error checking
// does not set null terminator
void get_exe_path(char* buffer, int buffer_max) {
    int len = readlink("/proc/self/exe", buffer, buffer_max);
    buffer[len] = '\0';
}

void get_ui_path(char* buffer, int buffer_max) {
    get_exe_path(buffer, buffer_max);
    char* dir = dirname(buffer);

    sprintf(buffer, "%s%s", dir, "/main.ui");
}

void activate (GtkApplication *app, gpointer user_data) {
    int buffer_max = 428;
    char* ui_path_buffer[buffer_max];
    get_ui_path(ui_path_buffer, buffer_max);
    
    builder = gtk_builder_new_from_file(ui_path_buffer);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    gtk_window_set_application(GTK_WINDOW(window), app);

    // gtk_window_set_title (GTK_WINDOW (window), "Window");
    // gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
    gtk_window_present(GTK_WINDOW (window));
}

int main (int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("RPS.PROJECT", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    
    return status;
}
