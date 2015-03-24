#include "Addnurse.h"
#include "ui_Addnurse.h"
#include "Patient.h"
#include "Nurse.h"
#include <QMessageBox>
#include <vector>

using std::vector;

AddNurse::AddNurse(QWidget *parent,vector<Nurse*> *nurses, vector<Patient*> *patient) :
    QDialog(parent),
    ui(new Ui::AddNurse)
{
    ui->setupUi(this);
    this->Nurses=nurses;
    this->Patients=patient;

    for(int i=0;i<Nurses->size();i++){
        Nurse *nurse=Nurses->at(i);
        ui->ListNurse->addItem(nurse->toString());
    }

    for(int i=0;i<Patients->size();i++){
        Patient *patient=Patients->at(i);
        ui->ListPatient->addItem(patient->toString());
    }
}

AddNurse::~AddNurse()
{
    delete ui;
}

void AddNurse::on_pushButton_clicked()
{
    int nur=ui->ListNurse->currentIndex();
    int pac=ui->ListPatient->currentIndex();
    Nurse* nurse = Nurses->at(nur);
    nurse->addPatient(Patients->at(pac));
    QMessageBox::information(this,"Agregado","Paciente agregado a enfermera exitosamente.");
    this->close();
}
