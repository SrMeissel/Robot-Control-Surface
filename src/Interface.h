#include <QObject>
#include <QtWidgets/QTextEdit>
#include "mainWindow.h"

class Interface : public QObject {
    Q_OBJECT

    public:
        explicit Interface(QObject *parent = 0);

        Ui_Window* window;

    public slots:
        void onClick();
};