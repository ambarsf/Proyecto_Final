#include "Person.h"
#include <QObject>
#include <sstream>

using std::stringstream;

Person::Person(QString name, unsigned int age, QString gender, unsigned int id){
	this->name=name;
	this->age=age;
	this->gender=gender;
	this->id=id;
}

Person::Person(const Person& person){
	name=(person.name);
	age=(person.age);
	gender=(person.gender);
	id=(person.age);
}

QString Person::toString() const{
	stringstream ss;
    ss<<name.toStdString();;
    return QString::fromStdString(ss.str());
}

QString Person::getName()const{
	return name;
}

unsigned int Person::getAge()const{
	return age;
}

QString Person::getGender()const{
	return gender;
}

unsigned int Person::getId() const{
	return id;
}

void Person::setAge(unsigned int age){
	this->age=age;
}
