#ifndef ADDPACIENT_H
#define ADDPACIENT_H
#include "Paciente.h"
#include "Medicine.h"
#include "Disease.h"

#include <QDialog>
#include <vector>

using std::vector;

namespace Ui {
class Addpacient;
}

class Addpacient : public QDialog
{
    Q_OBJECT

public:
    explicit Addpacient(QWidget *parent = 0,vector<Patient*> *patient=0);
    ~Addpacient();

private slots:
    void on_AddEnfermedad_clicked();

    void on_AddMedicine_clicked();

private:
    Ui::Addpacient *ui;
    vector<Patient*> *Patients;
};

#endif // ADDPACIENT_H
