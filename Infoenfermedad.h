#ifndef INFOENFERMEDAD_H
#define INFOENFERMEDAD_H

#include <QDialog>
#include "Disease.h"
#include "Patient.h"
#include <vector>

using std::vector;

namespace Ui {
class Infoenfermedad;
}

class Infoenfermedad : public QDialog
{
    Q_OBJECT

public:
    explicit Infoenfermedad(QWidget *parent = 0,vector<Patient*> *patient=0,int num=0);
    ~Infoenfermedad();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::Infoenfermedad *ui;
    vector<Patient*> *Patients;
    int numpaciente;
};

#endif // INFOENFERMEDAD_H
