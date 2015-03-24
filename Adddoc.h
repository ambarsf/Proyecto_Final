#ifndef ADDDOC_H
#define ADDDOC_H

#include <QDialog>
#include <vector>
#include "Doctor.h"
#include "Patient.h"

using std::vector;

namespace Ui {
class AddDoc;
}

class AddDoc : public QDialog
{
    Q_OBJECT

public:
    explicit AddDoc(QWidget *parent = 0,vector<Doctor*> *doc=0,vector<Patient*> *patients=0);
    ~AddDoc();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddDoc *ui;
    vector<Doctor*> *Doctors;
    vector<Patient*> *Patients;
};

#endif // ADDDOC_H
