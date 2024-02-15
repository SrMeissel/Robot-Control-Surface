#include "app.hpp"

void App::run(int argc, char ** argv) {
    QApplication app(argc, argv);
    QWidget widget;

    Ui_Window window{&widget};
    Interface* interface = new Interface;
    // Allows interface to reference window members
    interface->window = &window;

    QObject::connect(window.pushButton, SIGNAL(clicked()), interface, SLOT(onClick()));

    widget.show();

    printf("hello world robot-control-surface package\n");  
    app.exec();
}