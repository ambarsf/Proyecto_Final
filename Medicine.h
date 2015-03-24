#ifndef MEDICINE_H
#define MEDICINE_H
#include <QObject>

class Medicine{
    QString name;
    QString dose;
public:
    Medicine(QString,QString);
	Medicine(const Medicine&);
    QString toString()const;
    QString getName()const;
    QString getDose()const;
    void setName(QString);
    void setDose(QString);
};
#endif
