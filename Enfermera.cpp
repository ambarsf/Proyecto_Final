#include "Enfermera.h"
#include "ui_Enfermera.h"
#include "Nurse.h"
#include <vector>
#include <QMessageBox>
using std::vector;

Enfermera::Enfermera(QWidget *parent,vector<Nurse*> *nurses) :
    QDialog(parent),
    ui(new Ui::Enfermera)
{
    ui->setupUi(this);
    ui->EnfHorario->addItem("Diurno");
    ui->EnfHorario->addItem("Nocturno");
    this->Nurses=nurses;
}

Enfermera::~Enfermera()
{
    delete ui;
}

void Enfermera::on_pushButton_clicked()
{
    QString name=ui->Enfname->text();
    unsigned int age=ui->Enfage->value();
    QString gender;
    if (ui->EnfFem->isChecked()){
        gender="Femenino";
    }else{
        gender="Masculino";
    };
    unsigned int id=ui->EnfID->text().toInt();
    double salary=ui->EnfSal->text().toDouble();
    QString schedule=ui->EnfHorario->currentText();
    Nurses->push_back(new Nurse(name,age,gender,id,salary,schedule));
    QMessageBox::information(this,"Agregado","La Enfermera ha sido agregado exitosamente.");
    this->close();
}
