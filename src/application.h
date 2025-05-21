#ifndef APPLICATION_H
#define APPLICATION_H

#include "gtk-4.0/gtk/gtk.h"

extern GtkApplication* app;
extern GtkWidget* window;
extern GtkWidget* image;
extern GtkBuilder* builder;

void app_activate(GtkApplication *app, gpointer user_data);
void app_exit();

#endif