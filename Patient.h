#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"
#include "Medicine.h"
#include "Disease.h"
#include <QObject>
#include <vector>

using std:: vector;

class Patient:public Person{
    QString condition;
	vector<Medicine*> medicines;
	vector<Disease*> diseases;
public:
    Patient(QString, unsigned int, QString, unsigned int, QString);
	Patient(const Patient&);
	~Patient();
    virtual QString toString() const;
    QString getCondition()const;
    vector<Medicine*> getMedicines();
    vector<Disease*> getDiseases();
    void setCondition(QString);
    void setMedicines(vector<Medicine*>);
    void setDiseases(vector<Disease*>);
    void addMedicine(Medicine*);
	void addDisease(Disease*);
    virtual double getnewSalary()const;
};
#endif
