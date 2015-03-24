#include "Disease.h"
#include <sstream>
#include <QObject>
#include <vector>

using std::stringstream;
using std::vector;

Disease::Disease(QString type,QString name,QString duration,QString severity){
	this->type=type;
	this->name=name;
	this->duration=duration;
	this->severity=severity;
    vector<QString> symptoms;
}

Disease::Disease(const Disease& other){
	type=other.type;
	name=other.name;
	duration=other.duration;
	severity=other.severity;
	symptoms=other.symptoms;
}

QString Disease::toString()const{
	stringstream ss;
    ss<<name.toStdString();
    return QString::fromStdString(ss.str());
}

QString Disease::getType()const{
	return type;
}

QString Disease::getName()const{
	return name;
}

QString Disease::getDuration()const{
	return duration;
}

QString Disease::getSeverity()const{
	return severity;
}

void Disease::setType(QString type){
	this->type=type;
}

void Disease::setName(QString name){
	this->name=name;
}

void Disease::setDuration(QString duration){
	this->duration=duration;
}

void Disease::setSeverity(QString severity){
	this->severity=severity;
}

void Disease::setSymptoms(vector<QString> sintomas){
    this->symptoms=sintomas;
}

vector<QString> Disease::getSymtoms(){
    return symptoms;
}
