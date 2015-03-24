#include "Doc.h"
#include "ui_Doc.h"
#include "Doctor.h"
#include <vector>
#include <QMessageBox>
using std::vector;

Doc::Doc(QWidget *parent,vector<Doctor*> *doctors) :
    QDialog(parent),
    ui(new Ui::Doc)
{
    ui->setupUi(this);
    this->Doctors=doctors;
    ui->DHorario->addItem("Diurno");
    ui->DHorario->addItem("Nocturno");
}

Doc::~Doc()
{
    delete ui;
}

void Doc::on_AddDoctor_clicked()
{
    QString name=ui->DocName->text();
    unsigned int age=ui->DocAge->value();
    unsigned int id=ui->DocID->text().toInt();
    QString gender;
    if (ui->RBFem->isChecked()){
        gender="Femenino";
    }else{
        gender="Masculino";
    };
    QString specialty=ui->DocEspecialidad->text();
    double salary=ui->DocSalario->text().toDouble();
    QString schedule=ui->DHorario->currentText();
    unsigned int phone=ui->DocPhone->text().toInt();
    Doctors->push_back(new Doctor(name,age,gender,id,specialty,phone,salary,schedule));
    QMessageBox::information(this,"Agregado","El Doctor ha sido agregado exitosamente.");
    this->close();
};

