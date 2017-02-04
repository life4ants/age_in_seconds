#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QMap>
#include "person.h"


class Data
{
public:
    Data();
    QString separtedigits(int number);
    QString changeseconds(int input);
    QString display(int mtime, int index, int goal_index);
    int getdata(int power, int index, bool next_goal);

    person willy;
    person andy;
    person peter;
    QMap<QString, int> name_sec_age;

private:

     QString place_name(int number);
     QString setGoal(int value, int goal, QString name);
    //QMap<QString, int> name_sec_age;

};

#endif // DATA_H
