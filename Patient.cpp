#include "Person.h"
#include "Patient.h"
#include "Medicine.h"
#include "Disease.h"
#include <QObject>
#include <sstream>
#include <vector>

using std::stringstream;
using std::vector;

Patient::Patient(QString name, unsigned int age, QString gender, unsigned int id, QString condition):Person(name,age,gender,id){
	this->condition=condition;
	vector<Medicine*> medicines;
	vector<Disease*> diseases;
}

Patient::Patient(const Patient& other):Person(other){
	condition=other.condition;
}

QString Patient::toString() const{
	stringstream ss;
    ss<<Person::toString().toStdString();
    return QString::fromStdString(ss.str());
}

QString Patient::getCondition()const{
	return condition;
}

void Patient::setCondition(QString condition){
	this->condition=condition;
}

void Patient::addMedicine(Medicine* medicine){
	medicines.push_back(medicine);
}

void Patient::addDisease(Disease* disease){
	diseases.push_back(disease);
}

vector<Medicine*> Patient::getMedicines(){
    return medicines;
}

vector<Disease*> Patient::getDiseases(){
   return diseases;
}

void Patient::setMedicines(vector<Medicine*> medicines){
    this->medicines=medicines;
}

void Patient::setDiseases(vector<Disease*> diseases){
    this->diseases=diseases;
}

Patient::~Patient(){
	if (!(medicines.empty())){
		medicines.clear();
	}

	if (!(diseases.empty())){
		diseases.clear();
	}
}//end destructor

double Patient::getnewSalary()const{
    return 1;
}
