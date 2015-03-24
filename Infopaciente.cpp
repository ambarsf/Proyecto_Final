#include "Infopaciente.h"
#include "ui_Infopaciente.h"
#include "Patient.h"
#include "Disease.h"
#include "Medicine.h"
#include "Infoenfermedad.h"
#include "Infomedicina.h"
#include <vector>
using std::vector;

Infopaciente::Infopaciente(QWidget *parent,vector<Patient*> *patient) :
    QDialog(parent),
    ui(new Ui::Infopaciente)
{
    ui->setupUi(this);
    this->Patients=patient;
    for(int i=0;i<Patients->size();i++){
        Patient *patient=Patients->at(i);
        ui->ListPacientes->addItem(patient->toString());
    }
}

Infopaciente::~Infopaciente()
{
    delete ui;
}

void Infopaciente::on_ListPacientes_currentIndexChanged(int index)
{
    QString str;
    Patient* patient=Patients->at(index);
    ui->namePaciente->setText(patient->getName());
    ui->AgePaciente->setText(str.setNum(patient->getAge()));
    ui->GeneroPaciente->setText(patient->getGender());
    ui->IDPaciente->setText(str.setNum(patient->getId()));
    ui->EstadoPaciente->setText(patient->getCondition());
    vector<Disease*> diseases=patient->getDiseases();
    vector<Medicine*> medicines=patient->getMedicines();
    if(!(diseases.empty())){
        ui->Enfermedades->setEnabled(false);
    }else{
        ui->Enfermedades->setEnabled(true);
    }

    if (!(medicines.empty())){
        ui->Medicamentos->setEnabled(false);
    }else{
        ui->Medicamentos->setEnabled(true);
    }
}

void Infopaciente::on_Enfermedades_clicked()
{
    int numPaciente=ui->ListPacientes->currentIndex();
    Infoenfermedad diag(0,Patients,numPaciente);
    diag.setModal(true);
    diag.exec();
}

void Infopaciente::on_Medicamentos_clicked()
{
    int numPaciente=ui->ListPacientes->currentIndex();
    Infomedicina diag(0,Patients,numPaciente);
    diag.setModal(true);
    diag.exec();
}
