#include "app.hpp"

static void activate(GtkApplication *app, gpointer user_data) {
  (void)user_data;
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "General Kenobi!");
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);

  gtk_window_present(GTK_WINDOW(window));
}

Surface::Surface() : Node("controlSurface") {
  app = gtk_application_new("ros.controlSurface", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  g_application_run(G_APPLICATION(app), 0, NULL);
}

Surface::~Surface() { g_object_unref(app); }

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Surface>());
  rclcpp::shutdown();
  return 0;
};
