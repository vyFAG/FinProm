#include "existingprojectbutton.h"

ExistingProjectButton::ExistingProjectButton(QString setText, int setIndex) {
    this->setText(setText);
    index = setIndex;
    this->setMinimumWidth(200);
    this->setMinimumHeight(60);
    qDebug() << this->height();
}

int ExistingProjectButton::getIndex() const {
    return index;
}

void ExistingProjectButton::buttonClicked() {
    emit returnId(index);
}
