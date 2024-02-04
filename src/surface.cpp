#include <cstdio>

#include <QApplication>
#include "mainWindow.h"

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);
  QWidget widget;
  Ui::Form ui;
  ui.setupUi(&widget);

  widget.show();

  printf("hello world robot-control-surface package\n");  
  return app.exec();
}