#include "Adddisease.h"
#include "ui_Adddisease.h"
#include "Patient.h";
#include "Disease.h"
#include <vector>
#include <QMessageBox>
using std::vector;

AddDisease::AddDisease(QWidget *parent,vector<Patient*> *patients,int num) :
    QDialog(parent),
    ui(new Ui::AddDisease)
{
    ui->setupUi(this);
    ui->EnfTipo->addItem("Bacteriana");
    ui->EnfTipo->addItem("Viral");
    ui->EnfTipo->addItem("Parasitaria");
    ui->EnfTipo->addItem("Aguda");
    ui->EnfTipo->addItem("Cronica");
    ui->EnfTipo->addItem("Contagiosa");
    ui->EnfTipo->addItem("No Contagiosa");
    ui->EnfTipo->addItem("Endemica");
    ui->EnfTipo->addItem("Esporadica");
    ui->EnfTipo->addItem("Epidemica");
    ui->EnfTipo->addItem("Hereditaria");
    ui->EnfTipo->addItem("Congenita");
    ui->EnfTipo->addItem("Infecciosa");
    ui->EnfTipo->addItem("Metabolica");
    ui->EnfTipo->addItem("Neurodegenerativas");

    ui->EnfGravedad->addItem("Leve");
    ui->EnfGravedad->addItem("Media");
    ui->EnfGravedad->addItem("Grave");

    this->Patients=patients;
    this->numpaciente=num;
}

AddDisease::~AddDisease()
{
    delete ui;
}

void AddDisease::on_pushButton_clicked()
{
    sintomas.clear();
    sintomas.push_back(ui->EnfSintomas->text());
    QMessageBox::information(this,"Agregado","Sintoma agregado exitosamente");
    ui->EnfSintomas->setText("");

}

void AddDisease::on_AddEnf_clicked()
{
    QString type=ui->EnfTipo->currentText();
    QString name=ui->EnfNombre->text();
    QString gravedad=ui->EnfGravedad->currentText();
    QString duracion;
    if (ui->RBHoras->isChecked()){
        duracion="1-12 Horas.";
    }else if (ui->RBDia->isChecked()){
        duracion="1 Dia.";
    }else if (ui->RBDias->isChecked()){
        duracion="1-3 Dias.";
    }else if(ui->RBSemana->isChecked()){
        duracion="Una semana.";
    }else{
        duracion="Mas de una semana.";
    }
    Patient *patient=Patients->at(numpaciente);
    Disease *disease= new Disease(type,name,duracion,gravedad);
    disease->setSymptoms(sintomas);
    patient->addDisease(disease);
    QMessageBox::information(this,"Agregado","Enfermedad agregada exitosamente");
    this->close();
}
