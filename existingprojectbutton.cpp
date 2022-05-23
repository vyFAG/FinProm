#include "existingprojectbutton.h"

ExistingProjectButton::ExistingProjectButton(QString setText, int setIndex) {
    this->setText(setText);
    index = setIndex;
}

int ExistingProjectButton::getIndex() const {
    return index;
}

void ExistingProjectButton::buttonClicked() {
    emit returnId(index);
}
