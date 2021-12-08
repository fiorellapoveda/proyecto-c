// My Application
//
// By (Your name)

// Libraries
#include <gtk/gtk.h> // GTK Library
#include <stdio.h> // C IO Library (Not needed)


// Function when our button is pressed
void on_clicked(GtkWidget *widget, gpointer data){
    GtkButton *button = (GtkButton*) data;
    gtk_button_set_label(button, "X");
    g_print("Button Clicked\n");

}

// Main function
int main(int argc, char *argv[])
{
  // Variables
  GtkWidget *window; // Window

	GtkBuilder *builder; // GTK Builder variable
  GtkWidget *button1, *button2, *button3, *button4,
  *button5, *button6, *button7, *button8, *button9;




	gtk_init(&argc, &argv); // Start GTK

	builder = gtk_builder_new(); // Create GTK UI Builder
	gtk_builder_add_from_file(builder, "myui2.glade", NULL); // Load our UI file

	// Assign the Variables
	window = GTK_WIDGET(gtk_builder_get_object(builder, "MyWindow")); // Load MyWindow
  button1 = GTK_WIDGET(gtk_builder_get_object(builder, "one"));

  button2 = GTK_WIDGET(gtk_builder_get_object(builder, "two"));
  button3 = GTK_WIDGET(gtk_builder_get_object(builder, "three"));
  button4 = GTK_WIDGET(gtk_builder_get_object(builder, "four"));
  button5 = GTK_WIDGET(gtk_builder_get_object(builder, "five"));
  button6 = GTK_WIDGET(gtk_builder_get_object(builder, "six"));
  button7 = GTK_WIDGET(gtk_builder_get_object(builder, "seven"));
  button8 = GTK_WIDGET(gtk_builder_get_object(builder, "eight"));
  button9 = GTK_WIDGET(gtk_builder_get_object(builder, "nine"));

	// Signals from every widget
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(button1, "clicked", G_CALLBACK(on_clicked), button1);
  g_signal_connect(button2, "clicked", G_CALLBACK(on_clicked), button2);
  g_signal_connect(button3, "clicked", G_CALLBACK(on_clicked), button3);
  g_signal_connect(button4, "clicked", G_CALLBACK(on_clicked), button4);
  g_signal_connect(button5, "clicked", G_CALLBACK(on_clicked), button5);
  g_signal_connect(button6, "clicked", G_CALLBACK(on_clicked), button6);
  g_signal_connect(button7, "clicked", G_CALLBACK(on_clicked), button7);
  g_signal_connect(button8, "clicked", G_CALLBACK(on_clicked), button8);
  g_signal_connect(button9, "clicked", G_CALLBACK(on_clicked), button9);



	gtk_widget_show_all(window); // Show our window
	gtk_main(); // Run our program

	return 0; // Necessary for a c main function
}
