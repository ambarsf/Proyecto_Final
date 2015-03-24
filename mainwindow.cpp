#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include "Doc.h"
#include "Enfermera.h"
#include "Paciente.h"
#include "Adddoc.h"
#include "Addnurse.h"
#include "Addpacient.h"
#include "Infdoc.h"
#include "Infonurse.h"
#include "Infopaciente.h"

#include <vector>
#include <QMessageBox>

using std::vector;


MainWindow::MainWindow(QWidget *parent,vector<Doctor*> *doc, vector<Nurse*> *nurse, vector<Patient*> *patient) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Doctors=doc;
    this->Nurses=nurse;
    this->Patients=patient;
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_AddDoc_clicked()
{
    Doc diag(0,Doctors);
    diag.setModal(true);
    diag.exec();
}

void MainWindow::on_AddNurse_clicked()
{
    Enfermera diag(0,Nurses);
    diag.setModal(true);
    diag.exec();
}

void MainWindow::on_AddPatient_clicked()
{
    Paciente diag(0,Patients);
    diag.setModal(true);
    diag.exec();
}

void MainWindow::on_InfoDoctor_clicked()
{
    if (Doctors->size()>0){
        Infdoc diag(0,Doctors);
        diag.setModal(true);
        diag.exec();
    }else{
        QMessageBox::information(this,"Error","No hay Doctores Registrados.");
    }
}

void MainWindow::on_InfoNurse_clicked()
{
    if (Nurses->size()>0){
        Infonurse diag(0,Nurses);
        diag.setModal(true);
        diag.exec();
    }else{
        QMessageBox::information(this,"Error","No hay Enfermeras Registradas.");
    }
}

void MainWindow::on_InfoPacient_clicked()
{
    if (Patients->size()>0){
        Infopaciente diag(0,Patients);
        diag.setModal(true);
        diag.exec();
    }else{
        QMessageBox::information(this,"Error","No hay Pacientes Registrados.");
    }
}

void MainWindow::on_ControlDoc_clicked()
{
    if (Doctors->size()>0){
        AddDoc diag(0,Doctors,Patients);
        diag.setModal(true);
        diag.exec();
    }else{
        QMessageBox::information(this,"Error","No hay Doctores Registrados.");
    }
}

void MainWindow::on_ControlNurse_clicked()
{
    if (Nurses->size()>0){
        AddNurse diag(0,Nurses,Patients);
        diag.setModal(true);
        diag.exec();
    }else{
        QMessageBox::information(this,"Error","No hay Enfermeras Registradas.");
    }
}


void MainWindow::on_ControlPac_clicked()
{
    if (Patients->size()>0){
        Addpacient diag(0,Patients);
        diag.setModal(true);
        diag.exec();
    }else{
        QMessageBox::information(this,"Error","No hay Pacientes Registrados.");
    }
}

void MainWindow::on_RefreshButton_clicked()
{
    int numDoc=Doctors->size();
    int numNurse=Nurses->size();
    int numPatient=Patients->size();
    int Total=numDoc+numNurse+numPatient;
    ui->NoDoc->display(numDoc);
    ui->NoNurse->display(numNurse);
    ui->NoPacients->display(numPatient);
    ui->Personas->setValue(Total);
}
