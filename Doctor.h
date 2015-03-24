#ifndef DOCTOR_H
#define DOCTOR_H
#include "Person.h"
#include "Patient.h"
#include <QObject>
#include <vector>

using std::vector;

class Doctor: public Person {
    QString specialty;
	unsigned int phone;
	double salary;
    QString schedule;
	vector<Patient*> patients;
public:
    Doctor(QString, unsigned int, QString, unsigned int, QString, unsigned int, double, QString);
	Doctor(const Doctor&);
	~Doctor();
    virtual QString toString() const;
    QString getSpecialty() const;
	int getPhone() const;
	double getSalary();
    QString getSchedule();
	void setPhone(unsigned int);
	void setSalary(double);
    void setSchedule(QString);
	void addPatient(Patient* patient);
    vector<Patient*> getPatients();
    virtual double getnewSalary()const;
};
#endif
