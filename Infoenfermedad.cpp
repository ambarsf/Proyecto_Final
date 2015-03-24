#include "Infoenfermedad.h"
#include "ui_Infoenfermedad.h"
#include "Patient.h"
#include "Medicine.h"
#include <vector>

using std::vector;

Infoenfermedad::Infoenfermedad(QWidget *parent,vector<Patient*> *patients,int num) :
    QDialog(parent),
    ui(new Ui::Infoenfermedad)
{
    ui->setupUi(this);
    this->Patients=patients;
    this->numpaciente=num;
    Patient *patient=Patients->at(numpaciente);
    vector <Disease*> diseases=patient->getDiseases();
    for(int i=0;i<diseases.size();i++){
        Disease *disease=diseases.at(i);
        ui->comboBox->addItem(disease->toString());
    }
}

Infoenfermedad::~Infoenfermedad()
{
    delete ui;
}

void Infoenfermedad::on_comboBox_currentIndexChanged(int index)
{
    ui->listSintomas->clear();
    Patient *patient=Patients->at(numpaciente);
    vector <Disease*> diseases=patient->getDiseases();
    Disease *disease=diseases.at(index);
    ui->NameDisease->setText(disease->getName());
    ui->TypeDisease->setText(disease->getType());
    ui->DuracionDisease->setText(disease->getDuration());
    ui->GravedadDisease->setText(disease->getSeverity());
    vector<QString> sintomas=disease->getSymtoms();
    for(int i=0;i<sintomas.size();i++){
        ui->listSintomas->addItem(sintomas.at(i));
    }
}

void Infoenfermedad::on_pushButton_clicked()
{
    ui->listSintomas->clear();
    this->close();
}
