#ifndef ADDMEDICINE_H
#define ADDMEDICINE_H

#include <QDialog>
#include "Medicine.h"
#include <vector>
#include "Patient.h"

using std::vector;

namespace Ui {
class Addmedicine;
}

class Addmedicine : public QDialog
{
    Q_OBJECT

public:
    explicit Addmedicine(QWidget *parent = 0,vector<Patient*> *patient=0,int num=0);
    ~Addmedicine();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Addmedicine *ui;
    vector<Patient*> *Patients;
    int numpaciente;
};

#endif // ADDMEDICINE_H
