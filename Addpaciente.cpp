#include "Addpaciente.h"
#include "ui_Addpaciente.h"
#include "Patient.h"
#include "Addmedicine.h"
#include "Adddisease.h"
#include <vector>

using std::vector;

AddPaciente::AddPaciente(QWidget *parent,vector<Patient*> *patient) :
    QDialog(parent),
    ui(new Ui::AddPaciente)
{
    ui->setupUi(this);
    this->Patients=patient;
    for(int i=0;i<Patients->size();i++){
        Patient *patient=Patients->at(i);
        ui->ListPatient->addItem(patient->toString());
    }
}

AddPaciente::~AddPaciente()
{
    delete ui;
}


