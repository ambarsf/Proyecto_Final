#ifndef NURSE_H
#define NURSE_H
#include "Person.h"
#include "Patient.h"
#include <QObject>
#include <vector>

using std::vector;

class Nurse: public Person{
    double salary=1000;
    QString schedule;
	vector<Patient*> patients;
public:
    Nurse(QString, unsigned int, QString, unsigned int, QString);
	Nurse(const Nurse& );
	~Nurse();
    virtual QString toString() const;
	double getSalary() const;
    QString getSchedule();
	void setSalary(double);
    void setSchedule(QString);
	void addPatient(Patient* patient);
    vector<Patient*> getPatients();
    virtual double getnewSalary()const;
};
#endif
