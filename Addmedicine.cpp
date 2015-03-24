#include "Addmedicine.h"
#include "ui_Addmedicine.h"
#include "Patient.h"
#include "Medicine.h"
#include <QMessageBox>
#include <vector>

using std::vector;

Addmedicine::Addmedicine(QWidget *parent,vector<Patient*> *patients,int num) :
    QDialog(parent),
    ui(new Ui::Addmedicine)
{
    ui->setupUi(this);
    this->Patients=patients;
    this->numpaciente=num;
}

Addmedicine::~Addmedicine()
{
    delete ui;
}

void Addmedicine::on_pushButton_clicked()
{
    QString name=ui->Medname->text();
    QString dose=ui->MedDose->text();
    Patient *patient=Patients->at(numpaciente);
    Medicine *med=new Medicine(name,dose);
    patient->addMedicine(med);
    QMessageBox::information(this,"Agregado","Medicamento agregado exitosamente");
    this->close();
}
