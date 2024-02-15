#include "Interface.h"

Interface::Interface(QObject *parent) : QObject(parent) {

}

void Interface::onClick() {
    //printf("I DID IT!");
    window->Greivous->append("General Kenobi?");
}