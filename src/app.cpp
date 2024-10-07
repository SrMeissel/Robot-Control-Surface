#include "app.hpp"

using std::placeholders::_1;

extern "C" {

static void activate(GtkApplication *app, gpointer user_data) {
  (void)user_data;
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "General Kenobi!");
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

  GtkWidget *col = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_set_homogeneous(GTK_BOX(col), TRUE);
  gtk_window_set_child(GTK_WINDOW(window), col);

  GtkWidget *textLabel = gtk_label_new("Topic");
  // gtk_window_set_child(GTK_WINDOW(window), textLabel);
  gtk_box_append(GTK_BOX(col), textLabel);

  GtkWidget *textView = gtk_text_view_new();
  GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));
  gtk_text_buffer_set_text(buffer, "Hello there, ", -1);
  gtk_text_view_set_editable(GTK_TEXT_VIEW(textView), FALSE);
  gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(textView), FALSE);
  // gtk_window_set_child(GTK_WINDOW(window), textView);
  GtkWidget *frame = gtk_frame_new(NULL);
  gtk_frame_set_child(GTK_FRAME(frame), textView);
  gtk_box_append(GTK_BOX(col), frame);

  gtk_window_present(GTK_WINDOW(window));
}

static void writeToTextView() {};

// this does not work as intended, but serves a useful concept.
static void closeWindow(GtkApplication *app, gpointer user_data) {
  (void)app;
  Surface *p = (Surface *)user_data;
  p->~Surface();
}
}

Surface::Surface() : Node("controlSurface") {
  createWindow();

  sub = this->create_subscription<geometry_msgs::msg::Twist>(
      "/turtle1/cmd_vel", 10, std::bind(&Surface::printSomething, this, _1));
}

Surface::~Surface() { g_object_unref(app); }

int Surface::createWindow() {
  app = gtk_application_new("ros.controlSurface", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  // g_signal_connect(app, "shutdown", G_CALLBACK(closeWindow), this);
  return g_application_run(G_APPLICATION(app), 0, NULL);
}

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Surface>());
  rclcpp::shutdown();
  return 0;
};
