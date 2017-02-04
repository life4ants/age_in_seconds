#ifndef POPUP1_H
#define POPUP1_H

#include <QDialog>

namespace Ui {
class Popup1;
}

class Popup1 : public QDialog
{
    Q_OBJECT

public:
    explicit Popup1(QWidget *parent = 0);
    ~Popup1();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_years_valueChanged(int arg1);

    void on_spinBox_months_valueChanged(int arg1);

    void on_spinBox_weeks_valueChanged(int arg1);

    void on_spinBox_days_valueChanged(int arg1);

    void on_spinBox_hours_valueChanged(int arg1);

    void on_spinBox_minutes_valueChanged(int arg1);

    void on_spinBox_seconds_valueChanged(int arg1);

private:
    Ui::Popup1 *ui;
    void changeseconds(int input);
    void setseconds();
    void setvalues();
    int years;
    int months;
    int weeks;
    int days;
    int hours;
    int minutes;
    int seconds;
};

#endif // POPUP1_H
