#ifndef PACIENTE_H
#define PACIENTE_H
#include "Patient.h"
#include <vector>
#include <QDialog>
using std::vector;

namespace Ui {
class Paciente;
}

class Paciente : public QDialog
{
    Q_OBJECT

public:
    explicit Paciente(QWidget *parent = 0,vector<Patient*> *patients=0);
    ~Paciente();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Paciente *ui;
    vector<Patient*> *Patients;
};

#endif // PACIENTE_H
