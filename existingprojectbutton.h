#ifndef EXISTINGPROJECTBUTTON_H
#define EXISTINGPROJECTBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>

class ExistingProjectButton : public QPushButton
{
    Q_OBJECT
public:
    ExistingProjectButton(QString setText, int setIndex);
    int getIndex() const;

private:
    int index;

signals:
    void returnId(int);

public slots:
    void buttonClicked();

};

#endif // EXISTINGPROJECTBUTTON_H
