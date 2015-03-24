#include "mainwindow.h"
#include <QApplication>
#include <vector>
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"

using std::vector;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vector<Doctor*> *Doctors= new vector<Doctor*>;
    vector<Nurse*> *Nurses= new vector<Nurse*>;
    vector<Patient*> *Patients= new vector<Patient*>;
    MainWindow w(0,Doctors,Nurses,Patients);
    w.show();

    return a.exec();
}
