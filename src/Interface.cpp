#include "Interface.h"

Interface::Interface(QObject *parent) : QObject(parent) {

}

void Interface::onClick() {
    //sprintf("I DID IT!");
    window->Greivous->append("General Kenobi?");
}