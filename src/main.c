#include <gtk-4.0/gtk/gtk.h>

#include "application.h"

int main (int argc, char **argv) {
    int status;

    gtk_init();
    app = gtk_application_new("com.github.rps-example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);

    app_exit();
    
    return status;
}
