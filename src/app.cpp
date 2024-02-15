#include "app.hpp"

void App::run(int argc, char ** argv) {
    QApplication app(argc, argv);
    QWidget widget;
    Ui_Window window{&widget};
    
    //interface holds all ui interaction slot (callbacks)
    Interface* interface = new Interface;
    // Allows interface to reference window members
    interface->window = &window;

    QObject::connect(window.pushButton, SIGNAL(clicked()), interface, SLOT(onClick()));

    widget.show();

    // Qt main event loop
    app.exec();
}