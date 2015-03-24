#include "Adddoc.h"
#include "ui_Adddoc.h"
#include "Doctor.h"
#include "Patient.h"
#include "QMessageBox"
#include <vector>
using std::vector;

AddDoc::AddDoc(QWidget *parent,vector<Doctor*> *doctors,vector<Patient*> *patients) :
    QDialog(parent),
    ui(new Ui::AddDoc)
{
    ui->setupUi(this);
    this->Doctors=doctors;
    this->Patients=patients;

    for(int i=0;i<Doctors->size();i++){
        Doctor *doc=Doctors->at(i);
        ui->ListDoctors->addItem(doc->toString());
    }


    for(int i=0;i<Patients->size();i++){
        Patient *patient=Patients->at(i);
        ui->ListPatients->addItem(patient->toString());
    }
}

AddDoc::~AddDoc()
{
    delete ui;
}

void AddDoc::on_pushButton_clicked()
{
   int doc=ui->ListDoctors->currentIndex();
   int pac=ui->ListPatients->currentIndex();
   Doctor* doctor = Doctors->at(doc);
   doctor->addPatient(Patients->at(pac));
   QMessageBox::information(this,"Agregado","Paciente agregado a doctor exitosamente.");
   this->close();
}
