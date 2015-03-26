#include "Person.h"
#include "Nurse.h"
#include "Patient.h"
#include <sstream>
#include <QObject>
#include <vector>

using std::stringstream;
using std::vector;

Nurse::Nurse(QString name, unsigned int age, QString gender, unsigned int id,QString schedule):Person(name,age,gender,id){
	this->salary=salary;
	this->schedule=schedule;
	vector<Patient*> patients;
}

Nurse::Nurse(const Nurse& other):Person(other){
	salary=(other.salary);
	schedule=(other.schedule);
}

QString Nurse::toString() const{
	stringstream ss;
    ss<<Person::toString().toStdString();
    return QString::fromStdString(ss.str());
}

double Nurse::getSalary() const{
	return salary;
}

QString Nurse::getSchedule(){
	return schedule;
}

void Nurse::setSalary(double salary){
	this->salary=salary;
}

void Nurse::setSchedule(QString schedule){
	this->schedule=schedule;
}

void Nurse::addPatient(Patient* patient){
	patients.push_back(patient);
}

Nurse::~Nurse(){
	if(!(patients.empty())){
		patients.clear();
	}
}

vector<Patient*> Nurse::getPatients(){
    return patients;
}

double Nurse::getnewSalary()const{
    return salary * (0.4*patients.size());
}
