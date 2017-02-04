#include "popup1.h"
#include "ui_popup1.h"
#include "data.h"

Data pdata;

Popup1::Popup1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Popup1)
{
    ui->setupUi(this);

}

Popup1::~Popup1()
{
    delete ui;
}

void Popup1::on_pushButton_clicked()
{
    Popup1::~Popup1();
}

void Popup1::on_spinBox_valueChanged(int arg1)
{

    changeseconds(arg1);
    setvalues();
    ui->lineEdit->setText(pdata.separtedigits(arg1) + " seconds");
}

void Popup1::changeseconds(int input)     //function to change seconds in int form into week,day,hour,min, sec form
{
    years = input/31622400; //or 31536000 (365 days)
    months = (input - (years * 31622400)) / 2635200;
    weeks = (input - ( (years * 31622400) + (months * 2635200))) / 604800;
    days = (input - ( (years * 31622400) + (months * 2635200) + (weeks * 604800))) / 86400;
    hours = (input - ( (years * 31622400) + (months * 2635200) + (weeks * 604800) + (days * 86400))) / 3600;
    minutes = (input - ( (years * 31622400) + (months * 2635200) + (weeks * 604800) + (days * 86400) +
                             (hours * 3600))) / 60;
    seconds = (input - ( (years * 31622400) + (months * 2635200) + (weeks * 604800) + (days * 86400) +
                             (hours * 3600) + (minutes * 60)));


}

void Popup1::setseconds()
{
    int _seconds = (years * 31622400) + (months * 2635200) + (weeks * 604800) + (days * 86400) +
                                       (hours * 3600) + (minutes * 60) + seconds;
    ui->spinBox->setValue(_seconds);
    ui->lineEdit->setText(pdata.separtedigits(_seconds) + " seconds");
}

void Popup1::setvalues()
{
    ui->spinBox_years->setValue(years);
    ui->spinBox_months->setValue(months);
    ui->spinBox_weeks->setValue(weeks);
    ui->spinBox_days->setValue(days);
    ui->spinBox_hours->setValue(hours);
    ui->spinBox_minutes->setValue(minutes);
    ui->spinBox_seconds->setValue(seconds);
}

void Popup1::on_spinBox_years_valueChanged(int arg1)
{
    years = arg1;
    setseconds();
}

void Popup1::on_spinBox_months_valueChanged(int arg1)
{
    months = arg1;
    setseconds();
}

void Popup1::on_spinBox_weeks_valueChanged(int arg1)
{
    weeks = arg1;
    setseconds();
}

void Popup1::on_spinBox_days_valueChanged(int arg1)
{
    days = arg1;
    setseconds();
}

void Popup1::on_spinBox_hours_valueChanged(int arg1)
{
    hours = arg1;
    setseconds();
}

void Popup1::on_spinBox_minutes_valueChanged(int arg1)
{
    minutes = arg1;
    setseconds();
}

void Popup1::on_spinBox_seconds_valueChanged(int arg1)
{
    seconds = arg1;
    setseconds();
}
