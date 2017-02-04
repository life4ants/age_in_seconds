#include <ctime>
#include <QTimer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"
#include "popup1.h"

QTimer* timer;
Data mdata;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);       //timer to run the code every second
    connect(timer, SIGNAL(timeout()), this, SLOT(count()));
    timer->start(1000);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::count()        //function ran by the timer
{
    int mtime = (time(NULL));       //get the time
    int index = name_index;         //get the index of the person

    QString display = mdata.display(mtime, index, goal_index);  //send the time and the person we're dealing with
    ui->textbox->setText(display);                              //to Data::display and display whatever it sends back
}


void MainWindow::on_Name_select_currentIndexChanged(int _index)
{
    name_index = _index;
    setGoalIndex((ui->spinBox->value()), name_index);

}

void MainWindow::on_pushButton_clicked()
{
    Popup1 *popup1 = new Popup1;
    popup1->show();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    setGoalIndex(arg1, name_index);
}

void MainWindow::setGoalIndex(int arg1, int name_index)
{
   goal_index = mdata.getdata(arg1, name_index, next_goal);

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->Name_select->addItem("Bob");
    ui->textbox->setText("Bob was added");
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "last goal")
    {
        next_goal = false;
    }
    else
    {
        next_goal = true;
    }

    setGoalIndex((ui->spinBox->value()), name_index);
}
