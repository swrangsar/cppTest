#include <gtk/gtk.h>
 
int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *label;
 
    gtk_init(&argc, &argv);
 
    /* Create the main, top level window */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 
    /* Give it the title */
    gtk_window_set_title(GTK_WINDOW(window), "Swrangsar");
 
    /* Center the window */
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
 
    /* Set the window's default size */
    gtk_window_set_default_size(GTK_WINDOW(window), 700, 50);
    
    GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    
    GtkWidget *hbox = gtk_hbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(vbox), hbox);
    
    GtkWidget *button = gtk_button_new_with_label("Hey!");
    gtk_container_add(GTK_CONTAINER(hbox), button);
    
    GtkWidget *button1 = gtk_button_new_with_label("Lol");
    gtk_container_add(GTK_CONTAINER(hbox), button1);
           
    
 
    /*
    ** Map the destroy signal of the window to gtk_main_quit;
    ** When the window is about to be destroyed, we get a notification and
    ** stop the main GTK+ loop by returning 0
    */
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
 
    /*
    ** Assign the variable "label" to a new GTK label,
    ** with the text "Hello, world!"
    */
    label = gtk_label_new("\u00a9 s\u00f8rangsar 2014. \u05d0 Caf\u00e9 na\u00efve!");
 
    /* Plot the label onto the main window */
    gtk_container_add(GTK_CONTAINER(hbox), label);
 
    /* Make sure that everything, window and label, are visible */
    gtk_widget_show_all(window);
 
    /*
    ** Start the main loop, and do nothing (block) until
    ** the application is closed
    */
    gtk_main();
 
    return 0;
}

/*

cc -Wall gtkTest.c -o gtkTest `pkg-config --cflags --libs gtk+-2.0`

*/