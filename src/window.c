#include "window.h"



int test_proj_export() {
    struct scene scn;

    scn.chapter = 1;
    scn.episode = 2;
    strcpy(scn.type, "dialogue");
    strcpy(scn.text, "this is a sentence !");

    export_to_json(scn);

    return 0;
}


int print_hello() {
    printf("Hello, World");
    return 0;
}

// , gpointer user_data
static void activate(GtkApplication* app) {
    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *button;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), APP_NAME);
    gtk_window_set_default_size(GTK_WINDOW(window), APP_SIZE_X, APP_SIZE_Y);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    layout = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), layout);

    button = gtk_button_new_with_label("Export To JSON");
    g_signal_connect(button, "clicked", G_CALLBACK(test_proj_export), NULL);

    gtk_grid_attach(GTK_GRID(layout), button, 0, 0, 1, 1);

    button = gtk_button_new_with_label("Button 2");
    g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

    gtk_grid_attach(GTK_GRID(layout), button, 1, 0, 1, 1);

    button = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);

    gtk_grid_attach(GTK_GRID(layout), button, 0, 1, 2, 1);

    gtk_widget_show_all(window);
}


int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("dev.qtpy.dictator", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
