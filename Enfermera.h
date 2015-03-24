#ifndef ENFERMERA_H
#define ENFERMERA_H

#include <QDialog>
#include <vector>
#include "Nurse.h"
using std::vector;

namespace Ui {
class Enfermera;
}

class Enfermera : public QDialog
{
    Q_OBJECT

public:
    explicit Enfermera(QWidget *parent = 0, vector<Nurse*> *Nurses=0);
    ~Enfermera();

private slots:
    void on_pushButton_clicked();


private:
    Ui::Enfermera *ui;
    vector<Nurse*> *Nurses;
};

#endif // ENFERMERA_H
