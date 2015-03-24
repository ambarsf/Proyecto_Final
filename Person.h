#ifndef PERSON_H
#define PERSON_H
#include <QObject>


class Person{
    QString name;
	unsigned int age;
    QString gender;
	unsigned int id;
public:
    Person(QString, unsigned int, QString, unsigned int);
	Person(const Person&);
    virtual QString toString() const;
    QString getName()const;
	unsigned int getAge()const;
    QString getGender()const;
	unsigned int getId() const;
	void setAge(unsigned int);
    virtual double getnewSalary()const=0;
};
#endif
