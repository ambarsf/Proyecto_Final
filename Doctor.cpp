#include "Doctor.h"
#include "Person.h"
#include "Patient.h"
#include <QObject>
#include <sstream>
#include <vector>
using std::stringstream;
using std::vector;

Doctor::Doctor(QString name, unsigned int age, QString gender, unsigned int id, QString specialty, unsigned int phone,QString schedule):Person(name,age,gender,id){
	this->specialty=specialty;
	this->phone=phone;
	this->salary=salary;
	this->schedule=schedule;
	vector<Patient*> patients;
}

Doctor::Doctor(const Doctor& other):Person(other){
	specialty=other.specialty;
	phone=other.phone;
	salary=other.salary;
	schedule=other.schedule;
}

QString Doctor::toString() const{
    stringstream ss;
    ss<<Person::toString().toStdString();
    return QString::fromStdString(ss.str());
}

QString Doctor::getSpecialty() const{
	return specialty;
}

int Doctor::getPhone() const{
	return phone;
}

double Doctor::getSalary(){
	return salary;
}

QString Doctor::getSchedule(){
	return schedule;
}

void Doctor::setPhone(unsigned int phone){
	this->phone=phone;
}

void Doctor::setSalary(double salary){
	this->salary=salary;
}

void Doctor::setSchedule(QString schedule){
	this->schedule=schedule;
}	

void Doctor::addPatient(Patient* patient){
	patients.push_back(patient);
}

Doctor::~Doctor(){
	if(!(patients.empty())){
		patients.clear();
	}
}

vector<Patient*> Doctor::getPatients(){
    return patients;
}

double Doctor::getnewSalary()const{
    return salary * (0.5*patients.size());
}
