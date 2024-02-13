#include <cstdio>

#include <QApplication>
#include "mainWindow.h"
#include "mainWindow.cpp"

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);
  QWidget widget;

  //using generated code
  //Ui::Form ui;
  //ui.setupUi(&widget);

  //using my code
  Interface interface{&widget};
  //interface.setupUi(&widget);

  widget.show();

  printf("hello world robot-control-surface package\n");  
  return app.exec();
}