#include <QApplication>
#include "mainWindow.h"

class Interface : public Ui_Form, QObject {
    //inherits all auto generated code from ui file
    Q_OBJECT

    public:
        Interface(QWidget *Form) {
            setupUi(Form);

            connect(pushButton, SIGNAL(clicked()), SLOT(onClicked()));
        }

    private slots:
        void onClicked() {
            Greivous->append("General Kenobi! \n");
        };      

};