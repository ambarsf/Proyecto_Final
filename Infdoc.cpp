#include "Infdoc.h"
#include "ui_Infdoc.h"
#include "Doctor.h"
#include "Patient.h"
#include <vector>

using std::vector;

Infdoc::Infdoc(QWidget *parent,vector<Doctor*> *doctors) :
    QDialog(parent),
    ui(new Ui::Infdoc)
{
    this->Doctors=doctors;
    ui->setupUi(this);
    for(int i=0;i<Doctors->size();i++){
        Doctor *doc=Doctors->at(i);
        ui->ListDoc->addItem(doc->toString());
    }

}

Infdoc::~Infdoc()
{
    delete ui;
}

void Infdoc::on_ListDoc_currentIndexChanged(int index)
{
    ui->listPatients->clear();
    QString str;
    Doctor* doc=Doctors->at(index);
    ui->DocName->setText(doc->getName());
    ui->DocAge->setText(str.setNum(doc->getAge()));
    ui->DocGender->setText(doc->getGender());
    ui->DocSpecialty->setText(doc->getSpecialty());
    ui->DocID->setText(str.setNum(doc->getId()));
    ui->DocPhone->setText(str.setNum(doc->getPhone()));
    ui->DocSchedule->setText(doc->getSchedule());
    ui->DocSalary->setText(str.setNum(doc->getSalary()));
    ui->gananciaDoc->setText(str.number(doc->getnewSalary()));
    vector<Patient*> patients=doc->getPatients();
    for(int i=0; i<patients.size(); i++){
        Patient* pat=patients.at(i);
        ui->listPatients->addItem(pat->toString());
    }

}

void Infdoc::on_OKDoc_clicked()
{
    ui->listPatients->clear();
    this->close();
}
