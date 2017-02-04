#include "data.h"
#include "person.h"
#include <ctime>
#include <cmath>
#include <QMessageBox>

Data::Data()
{
/*
    willy.name = "Willy";
    willy.value = 593381460;
    andy.name = "Andy";
    andy.value = 656039280;
    peter.name = "Peter";
    peter.value = 882994200;
    */
    name_sec_age.insert("willy", 593381460);
    name_sec_age.insert("andy", 656039280);
    name_sec_age.insert("peter", 882994200);


}


QString Data::separtedigits(int number) //function to turn an int into a string with a comma between each 3 place values
{
    int billion = number / 1000000000;
    int million = (number / 1000000) - (billion * 1000);
    int thousand = (number/1000) - ( (million * 1000) + (billion * 1000000));
    int hundred = number - ( (billion * 1000000000) + (million * 1000000) +  (thousand * 1000));
    QString output;

    if (billion != 0)
    {
    output = (QString::number(billion)) + "," + (place_name(million)) + ","
            + (place_name(thousand)) + "," + (place_name(hundred));
    }
 else
    {
        if (million != 0)
        {
            output = (QString::number(million)) + "," + (place_name(thousand)) + "," + (place_name(hundred));
        }
         else
         {
            if (thousand != 0)
            {
                output = (QString::number(thousand)) + "," + (place_name(hundred));
            }
            else
            {
                output = (QString::number(hundred));
            }
         }
      }
    return output;
}

QString Data::place_name(int number)    //helper function for separatedigits()
{
    QString output;

    if (number <10)
        output = "00"+ (QString::number(number));
    else if (number <100)
        output = "0"+ (QString::number(number));
    else
        output = (QString::number(number));

    return output;
}

QString Data::changeseconds(int input)     //function to change seconds in int form into week,day,hour,min, sec form
{
    int years = input/31622400; //or 31536000 (365 days)
    int months = (input - (years * 31622400)) / 2635200;
    int weeks = (input - ( (years * 31622400) + (months * 2635200))) / 604800;
    int days = (input - ( (years * 31622400) + (months * 2635200) + (weeks * 604800))) / 86400;
    int hours = (input - ( (years * 31622400) + (months * 2635200) + (weeks * 604800) + (days * 86400))) / 3600;
    int minutes = (input - ( (years * 31622400) + (months * 2635200) + (weeks * 604800) + (days * 86400) +
                             (hours * 3600))) / 60;
    int seconds = (input - ( (years * 31622400) + (months * 2635200) + (weeks * 604800) + (days * 86400) +
                             (hours * 3600) + (minutes * 60)));
    QString output;

    if (years != 0)
    {
        output = (QString::number(years)) + " years, " + (QString::number(months)) + " months, "
               + (QString::number(weeks)) + " weeks, " + (QString::number(days)) + " days, "
               + (QString::number(hours)) + " hours, " + (QString::number(minutes))
                + " minutes, " + (QString::number(seconds)) + " seconds";
    }

    else
    {
        if (months != 0)
        {
        output = (QString::number(months)) + " months, " + (QString::number(weeks)) + " weeks, "
                + (QString::number(days)) + " days, "
               + (QString::number(hours)) + " hours, " + (QString::number(minutes))
                + " minutes, " + (QString::number(seconds)) + " seconds";
        }

    else
        {
            if (weeks != 0)
            {
             output = (QString::number(weeks)) + " weeks, " + (QString::number(days)) + " days, "
           + (QString::number(hours)) + " hours, " + (QString::number(minutes))
            + " minutes, " + (QString::number(seconds)) + " seconds";
            }
            else
            {
                if (days != 0)     {
                    output = (QString::number(days)) + " days, " + (QString::number(hours)) + " hours, "
                            + (QString::number(minutes)) + " minutes, " + (QString::number(seconds)) + " seconds";    }
                 else
                 {
                    if (hours != 0)   {
                        output = (QString::number(hours)) + " hours, " + (QString::number(minutes))
                                + " minutes, " + (QString::number(seconds)) + " seconds";    }
                    else
                    {
                       if (minutes !=0)
                       {
                       output = (QString::number(minutes)) + " minutes, " + (QString::number(seconds)) + " seconds";
                       }
                       else
                       {
                       output = (QString::number(seconds)) + " seconds";
                       }
                    }
                 }
              }
        }

    }


    return output;
}

QString Data::display(int mtime, int index, int goal_index) //function to convert data into a string to display
{
    QString name;

    if (index == 1)
    {
        name = "willy";
    }
    else if (index == 2)
    {
        name = "andy";
    }
    else if (index == 3)
    {
        name = "peter";
    }
    else //(index == 0)
    {
    return "Select a person to start";
    }


       QString age = name + " is " + separtedigits(mtime - name_sec_age[name]) + " seconds old";
       QString togoal = setGoal(mtime - name_sec_age[name], goal_index, name);

       return age + "\n\n" + togoal;

}

int Data::getdata(int power, int index, bool next_goal)        //get the data on each person and set the goal
{
    int mtime = (time(NULL));
    int tempvalue;

    if (index == 1) {
        tempvalue = (mtime - name_sec_age["willy"]);}
    else if (index == 2) {
        tempvalue = (mtime - name_sec_age["andy"]);}
    else if (index == 3) {
        tempvalue = (mtime - name_sec_age["peter"]);}
    else //(index == 0)
    {
    tempvalue = 0;
    }

    int mpower = pow(10,power);
    int goal;

    if (next_goal){
    goal = (((tempvalue/mpower) + 1 ) * mpower);
    }
    else {
   goal = (((tempvalue/mpower)) * mpower);
    }
    return goal;
}

QString Data::setGoal(int value, int goal, QString name)    //helper function for display()
{

    int time_to_next_goal;
    QString togoal;

    if (goal >= value)
    {
        time_to_next_goal = goal - value;
        togoal = name + " will be " + separtedigits(goal) + " seconds old in\n" +
                changeseconds(time_to_next_goal);
    }
    else if (goal < value)
    {
        time_to_next_goal = value - goal;
        togoal = name + " was " + separtedigits(goal) + " seconds old\n" +
                changeseconds(time_to_next_goal) + " ago ";
    }

    return togoal;
}

