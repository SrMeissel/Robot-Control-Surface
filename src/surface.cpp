#include <cstdio>

#include <QApplication>
// #include "mainWindow.h"
#include "Interface.h"

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);
  QWidget widget;

  //using generated code
  //Ui::Form ui;
  //ui.setupUi(&widget);

  //using my code
  Ui_Window window{&widget};
  Interface* interface = new Interface;
  interface->window = &window;

  QObject::connect(window.pushButton, SIGNAL(clicked()), interface, SLOT(onClick()));

  widget.show();

  printf("hello world robot-control-surface package\n");  
  return app.exec();
}