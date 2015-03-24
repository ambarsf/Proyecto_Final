#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include <vector>

using std::vector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0,vector<Doctor*> *doc=0,vector<Nurse*> *nurse=0,vector<Patient*> *patient=0);

    ~MainWindow();

private slots:

    void on_AddDoc_clicked();

    void on_AddNurse_clicked();

    void on_AddPatient_clicked();

    void on_InfoDoctor_clicked();

    void on_InfoNurse_clicked();

    void on_InfoPacient_clicked();

    void on_ControlDoc_clicked();

    void on_ControlNurse_clicked();

    void on_ControlPac_clicked();

    void on_RefreshButton_clicked();

private:
    Ui::MainWindow *ui;
    vector<Doctor*> *Doctors;
    vector<Nurse*> *Nurses;
    vector<Patient*> *Patients;
};

#endif // MAINWINDOW_H
