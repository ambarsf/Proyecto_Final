#ifndef INFDOC_H
#define INFDOC_H

#include <QDialog>
#include "Doctor.h"
#include <vector>

using std::vector;

namespace Ui {
class Infdoc;
}

class Infdoc : public QDialog
{
    Q_OBJECT

public:
    explicit Infdoc(QWidget *parent = 0,vector<Doctor*> *doc=0);
    ~Infdoc();

private slots:
    void on_ListDoc_currentIndexChanged(int index);

    void on_OKDoc_clicked();

private:
    Ui::Infdoc *ui;
    vector<Doctor*> *Doctors;
};

#endif // INFDOC_H
