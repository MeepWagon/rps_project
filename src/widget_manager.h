#ifndef WIDGET_MANAGER_H
#define WIDGET_MANAGER_H

void widget_manager_setup(char** widget_id_array, int array_length);
GtkWidget* manager_get_widget(const char* widget_name);

#endif
