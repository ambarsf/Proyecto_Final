#include "Addpacient.h"
#include "ui_Addpacient.h"
#include "Paciente.h"
#include "Disease.h"
#include "Medicine.h"
#include "Adddisease.h"
#include "Addmedicine.h"
#include <vector>
using std::vector;

Addpacient::Addpacient(QWidget *parent,vector<Patient*> *patient) :
    QDialog(parent),
    ui(new Ui::Addpacient)
{
    ui->setupUi(this);
    this->Patients=patient;
    for(int i=0;i<Patients->size();i++){
        Patient *patient=Patients->at(i);
        ui->ListPatient->addItem(patient->toString());
    }
}

Addpacient::~Addpacient()
{
    delete ui;
}

void Addpacient::on_AddEnfermedad_clicked()
{
    int numPaciente=ui->ListPatient->currentIndex();
    AddDisease diag(0,Patients,numPaciente);
    diag.setModal(true);
    diag.exec();
}

void Addpacient::on_AddMedicine_clicked()
{
    int numPaciente=ui->ListPatient->currentIndex();
    Addmedicine diag(0,Patients,numPaciente);
    diag.setModal(true);
    diag.exec();
}
