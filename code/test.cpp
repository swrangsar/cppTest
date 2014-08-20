#include <gtk/gtk.h>
 
int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *label;
 
    gtk_init(&argc, &argv);
 
    /* Create the main, top level window */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 
    /* Give it the title */
    gtk_window_set_title(GTK_WINDOW(window), "Lightening");
    gtk_window_set_resizable(GTK_WINDOW(window), true);
 
    /* Center the window */
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
 
    /* Set the window's default size */
    gtk_window_set_default_size(GTK_WINDOW(window), 700, 70);
    GtkWidget * vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *hbox = gtk_hbox_new(FALSE, 5);
    gtk_container_set_border_width(GTK_CONTAINER(hbox), 5);
    gtk_container_add(GTK_CONTAINER(vbox), hbox);
    GtkWidget *button = gtk_button_new_with_label("Hey!");
    gtk_container_add(GTK_CONTAINER(hbox), button);
    GtkWidget *button1 = gtk_button_new_with_label("Lol");
    gtk_container_add(GTK_CONTAINER(hbox), button1);

    GtkWidget *combo = gtk_combo_box_new_text();
    gtk_container_add(GTK_CONTAINER(hbox), combo);
    
    gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "Spanish");
    gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "English");
    gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "French");

    GtkAdjustment *adj;
    adj = (GtkAdjustment*)gtk_adjustment_new(0, 1, 10, 1, 1, 10);
    GtkWidget *spin = gtk_spin_button_new(adj, 1.0, 0);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(spin), TRUE);
    gtk_container_add(GTK_CONTAINER(hbox), spin);



 
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
    label = gtk_label_new("\u00A9 s\u00f8rangsar 2014. \u05d0 Caf\u00e9 na\u00efve!");
 
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
