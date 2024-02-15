#include "uic_mainWindow.h"

class Ui_Window : public Ui_Form, QObject {
    //inherits all auto generated code from ui file
    //Q_OBJECT

    public:
        Ui_Window(QWidget *Form) {
            setupUi(Form);
        }  
};