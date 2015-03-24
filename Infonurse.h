#ifndef INFONURSE_H
#define INFONURSE_H

#include <QDialog>
#include "Nurse.h"
#include <vector>

using std::vector;

namespace Ui {
class Infonurse;
}

class Infonurse : public QDialog
{
    Q_OBJECT

public:
    explicit Infonurse(QWidget *parent = 0,vector<Nurse*> *Nurses=0);
    ~Infonurse();

private slots:
    void on_ListNurse_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::Infonurse *ui;
    vector<Nurse*> *Nurses;
};

#endif // INFONURSE_H
