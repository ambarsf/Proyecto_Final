#ifndef ADDNURSE_H
#define ADDNURSE_H

#include <QDialog>
#include "Nurse.h"
#include "Patient.h"
#include <vector>
using std::vector;

namespace Ui {
class AddNurse;
}

class AddNurse : public QDialog
{
    Q_OBJECT

public:
    explicit AddNurse(QWidget *parent = 0,vector<Nurse*> *nurses=0,vector<Patient*> *patients=0);
    ~AddNurse();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddNurse *ui;
    vector<Nurse*> *Nurses;
    vector<Patient*> *Patients;
};

#endif // ADDNURSE_H
