#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:

    void count();

private slots:

    void on_Name_select_currentIndexChanged(int _index);

    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:

    int name_index = 0;
    int goal_index;
    bool next_goal = true;

    Ui::MainWindow *ui;
    void setGoalIndex(int arg1, int name_index);
};

#endif // MAINWINDOW_H
