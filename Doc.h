#ifndef DOC_H
#define DOC_H

#include <QDialog>
#include "Doctor.h";
#include <vector>

using std::vector;

namespace Ui {
class Doc;
}

class Doc : public QDialog
{
    Q_OBJECT

public:
    explicit Doc(QWidget *parent = 0, vector<Doctor*> *doc=0);
    ~Doc();
    int getNumber();


private slots:
    void on_AddDoctor_clicked();

private:
    Ui::Doc *ui;
    vector<Doctor*> *Doctors;
};

#endif // DOC_H
