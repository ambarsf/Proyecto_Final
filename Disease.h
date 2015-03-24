#ifndef DISEASE_H
#define DISEASE_H
#include <QObject>
#include <vector>

using std::vector;

class Disease{
    QString type;
    QString name;
    QString duration;
    QString severity;
    vector<QString> symptoms;
public:
    Disease(QString ,QString ,QString ,QString);
	Disease(const Disease&);
    QString  toString()const;
    QString  getType()const;
    QString  getName()const;
    QString  getDuration()const;
    QString  getSeverity()const;
    void setType(QString );
    void setName(QString );
    void setDuration(QString );
    void setSeverity(QString );
    void setSymptoms(vector<QString>);
    vector<QString> getSymtoms();
};
#endif
