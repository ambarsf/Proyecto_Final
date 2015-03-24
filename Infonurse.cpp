#include "Infonurse.h"
#include "ui_Infonurse.h"
#include "Nurse.h"
#include "Patient.h"
#include <vector>
using std::vector;

Infonurse::Infonurse(QWidget *parent,vector<Nurse*> *nurses) :
    QDialog(parent),
    ui(new Ui::Infonurse)
{
    ui->setupUi(this);
    this->Nurses=nurses;
    for(int i=0;i<Nurses->size();i++){
        Nurse *nurse=Nurses->at(i);
        ui->ListNurse->addItem(nurse->toString());
    }
}

Infonurse::~Infonurse()
{
    delete ui;
}

void Infonurse::on_ListNurse_currentIndexChanged(int index)
{
    ui->listpatients->clear();
    QString str;
    Nurse* nurse=Nurses->at(index);
    ui->nursename->setText(nurse->getName());
    ui->nurseage->setText(str.setNum(nurse->getAge()));
    ui->nursegender->setText(nurse->getGender());
    ui->nurseid->setText(str.setNum(nurse->getId()));
    ui->nurseschedule->setText(nurse->getSchedule());
    ui->nursesalary->setText(str.setNum(nurse->getSalary()));
    ui->ganancianurse->setText(str.setNum(nurse->getnewSalary()));
    vector<Patient*> patients=nurse->getPatients();
    for(int i=0; i<patients.size(); i++){
        Patient* pat=patients.at(i);
        ui->listpatients->addItem(pat->toString());
    }

}

void Infonurse::on_pushButton_clicked()
{
    ui->listpatients->clear();
    this->close();
}
