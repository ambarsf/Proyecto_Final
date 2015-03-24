#include "Medicine.h"
#include <QObject>
#include <sstream>

using std::stringstream;

Medicine::Medicine(QString name,QString dose){
	this->name=name;
	this->dose=dose;
}

Medicine::Medicine(const Medicine& other){
	name=other.name;
	dose=other.dose;
}

QString Medicine::toString()const{
	stringstream ss;
    ss<<name.toStdString();
    return QString::fromStdString(ss.str());
}

QString Medicine::getName()const{
	return name;
}

QString Medicine::getDose()const{
	return dose;
}

void Medicine::setName(QString name){
	this->name=name;
}

void Medicine::setDose(QString dose){
	this->dose=dose;
}
