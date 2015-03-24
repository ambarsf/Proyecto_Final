#include "Infomedicina.h"
#include "ui_Infomedicina.h"
#include "Patient.h"
#include "Medicine.h"
#include <vector>

using std::vector;

Infomedicina::Infomedicina(QWidget *parent,vector<Patient*> *patients,int num) :
    QDialog(parent),
    ui(new Ui::Infomedicina)
{
    ui->setupUi(this);
    this->Patients=patients;
    this->numpaciente=num;
    Patient *patient=Patients->at(numpaciente);
    vector <Medicine*> medicines=patient->getMedicines();
    for(int i=0;i<medicines.size();i++){
        Medicine *medicine=medicines.at(i);
       ui->listMedicine->addItem(medicine->toString());
}
}

Infomedicina::~Infomedicina()
{
    delete ui;
}

void Infomedicina::on_listMedicine_currentIndexChanged(int index)
{
    Patient *patient=Patients->at(numpaciente);
    vector <Medicine*> medicines=patient->getMedicines();
    Medicine *medicine=medicines.at(index);
    ui->nameMed->setText(medicine->getName());
    ui->dosisMed->setText(medicine->getDose());
}

void Infomedicina::on_OkPaciente_clicked()
{
    this->close();
}
