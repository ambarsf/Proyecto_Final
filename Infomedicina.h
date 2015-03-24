#ifndef INFOMEDICINA_H
#define INFOMEDICINA_H

#include <QDialog>
#include "Medicine.h"
#include "Patient.h"
#include <vector>

using std:: vector;

namespace Ui {
class Infomedicina;
}

class Infomedicina : public QDialog
{
    Q_OBJECT

public:
    explicit Infomedicina(QWidget *parent = 0,vector<Patient*> *patient=0,int num=0);
    ~Infomedicina();

private slots:
    void on_listMedicine_currentIndexChanged(int index);

    void on_OkPaciente_clicked();

private:
    Ui::Infomedicina *ui;
    vector<Patient*> *Patients;
    int numpaciente;
};

#endif // INFOMEDICINA_H
