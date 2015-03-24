#include "Paciente.h"
#include "ui_Paciente.h"
#include "Patient.h"
#include <QMessageBox>
#include <vector>
using std:: vector;


Paciente::Paciente(QWidget *parent,vector<Patient*> *patients) :
    QDialog(parent),
    ui(new Ui::Paciente)
{
    ui->setupUi(this);
    this->Patients=patients;
    ui->PatientStatus->addItem("Leve");
    ui->PatientStatus->addItem("Media");
    ui->PatientStatus->addItem("Grave");
}

Paciente::~Paciente()
{
    delete ui;
}

void Paciente::on_pushButton_clicked()
{
    QString name=ui->PatientName->text();
    unsigned int age=ui->PatientAge->value();
    QString gender;
    if (ui->PatientFem->isChecked()){
        gender="Femenino";
    }else{
        gender="Masculino";
    };
    unsigned int id=ui->PatientID->text().toInt();
    QString status=ui->PatientStatus->currentText();
    Patients->push_back(new Patient(name,age,gender,id,status));
    QMessageBox::information(this,"Agregado","El Paciente ha sido agregado exitosamente.");
    this->close();
};

