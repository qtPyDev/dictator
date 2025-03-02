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

// , gpointer user_data
static void activate(GtkApplication* app) {
    GtkWidget *window;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), APP_NAME);
    gtk_window_set_default_size(GTK_WINDOW(window), APP_SIZE_X, APP_SIZE_Y);
    gtk_window_present(GTK_WINDOW(window));
}


int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    test_proj_export();

    return status;
}
