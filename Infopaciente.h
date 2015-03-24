#ifndef INFOPACIENTE_H
#define INFOPACIENTE_H

#include <QDialog>
#include "Patient.h"
#include <vector>

using std::vector;

namespace Ui {
class Infopaciente;
}

class Infopaciente : public QDialog
{
    Q_OBJECT

public:
    explicit Infopaciente(QWidget *parent = 0,vector<Patient*> *patient=0);
    ~Infopaciente();

private slots:
    void on_ListPacientes_currentIndexChanged(int index);

    void on_Enfermedades_clicked();

    void on_Medicamentos_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Infopaciente *ui;
    vector<Patient*> *Patients;
};

#endif // INFOPACIENTE_H
