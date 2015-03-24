#ifndef ADDDISEASE_H
#define ADDDISEASE_H

#include <QDialog>
#include "Disease.h"
#include "Patient.h"
#include <vector>

using std::vector;

namespace Ui {
class AddDisease;
}

class AddDisease : public QDialog
{
    Q_OBJECT

public:
    explicit AddDisease(QWidget *parent = 0,vector<Patient*> *patient=0,int num=0);
    ~AddDisease();

private slots:
    void on_pushButton_clicked();

    void on_AddEnf_clicked();

private:
    Ui::AddDisease *ui;
    vector<Patient*> *Patients;
    int numpaciente;
    vector<QString> sintomas;
};

#endif // ADDDISEASE_H
