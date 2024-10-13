#include "app.hpp"

using std::placeholders::_1;

extern "C" {

static void writeToTextView(GtkWidget *widget, gpointer data) {
  (void)widget;
  GtkTextBuffer *buffer = (GtkTextBuffer *)data;

  GtkTextIter iter;
  gtk_text_buffer_get_end_iter(buffer, &iter);
  gtk_text_buffer_insert(buffer, &iter, "WHAT THIS DO?", -1);
};

static void activate(GtkApplication *app, gpointer user_data) {
  (void)user_data;
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "General Kenobi!");
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

  GtkWidget *col = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_set_homogeneous(GTK_BOX(col), TRUE);
  gtk_window_set_child(GTK_WINDOW(window), col);

  GtkWidget *textLabel = gtk_label_new("Topic");
  gtk_box_append(GTK_BOX(col), textLabel);

  GtkWidget *textView = gtk_text_view_new();
  GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));
  gtk_text_buffer_set_text(buffer, "Hello there, ", -1);
  gtk_text_view_set_editable(GTK_TEXT_VIEW(textView), FALSE);
  gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(textView), FALSE);
  GtkWidget *frame = gtk_frame_new(NULL);
  gtk_frame_set_child(GTK_FRAME(frame), textView);
  gtk_box_append(GTK_BOX(col), frame);

  GtkWidget *button = gtk_button_new_with_label("beep boop");
  g_signal_connect(button, "clicked", G_CALLBACK(writeToTextView), buffer);
  gtk_box_append(GTK_BOX(col), button);

  gtk_window_present(GTK_WINDOW(window));
}
}

Surface::Surface() : Node("controlSurface") {
  using namespace std::chrono_literals;

  sub = this->create_subscription<geometry_msgs::msg::Twist>(
      "turtle1/cmd_vel", 10, std::bind(&Surface::printSomething, this, _1));

  app = gtk_application_new("ros.controlSurface", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  context = g_main_context_default();
  g_application_register(G_APPLICATION(app), NULL, NULL);
  g_main_context_acquire(context);
  g_application_activate(G_APPLICATION(app));

  timer = this->create_wall_timer(
      32ms, [&]() { g_main_context_iteration(context, FALSE); });
}

Surface::~Surface() { g_object_unref(app); }

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Surface>());
  rclcpp::shutdown();
  return 0;
};
