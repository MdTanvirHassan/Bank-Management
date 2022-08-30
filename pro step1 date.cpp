
#include<iostream>
//#include<conio.h>
#include<stdlib.h>
//#include<fstream>
using namespace std;

class date
{
    int day,month,year;
public:
    date(int day,int month,int year)
    {
       this-> day=day;
       this-> month=month;
       this-> year=year;
    }

    void enter_date();
    void show_date();
};

void date:: enter_date()
{

    cout<< "Please enter your current date: "<< endl << endl;;
    cout<< "Year:";
    cin>> year;

    if(year!=2018)
    {
        cout<< "Wrong input!"<< endl<< "please enter the valid year "<< endl;
    }

    cout<< "Month:";
    cin>> month;
    if(month<=0 ||month>12)
    {
        cout<< "Wrong input!"<< endl<< "Please enter the valid month "<< endl;
    }

    cout<< "Date:";
    cin>> day;
    if(day<=0 || day > 31)
    {
        cout<< "Wrong input!"<< endl<< "Please enter the valid date"<< endl;
    }
}

void date::show_date()
{
    system("CLS");
    cout<< "Your date is ";
    cout<< day;

    switch(day)
    {
    case 1:
        cout<< "st";
        break;
    case 2:
        cout<< "nd";
        break;
    case 3:
        cout<< "rd";
        break;
    default:
        cout<< "th";
        break;
    }

    switch(month)
    {
    case 1:
        cout<< ",January";
        break;
    case 2:
        cout<< ",February";
        break;
    case 3:
        cout<< ",March";
        break;
    case 4:
        cout<< ",April";
        break;
    case 5:
        cout<< ",May";
        break;
    case 6:
        cout<< ",June";
        break;
    case 7:
        cout<< ",july";
        break;
    case 8:
        cout<< ",August";
        break;
    case 9:
        cout<< ",September";
        break;
    case 10:
        cout<< ",October";
        break;
    case 11:
        cout<< ",November";
        break;
    case 12:
        cout<< ",December";
        break;
    default:
        cout<< "invalid month.";
    }
    cout<< "," <<  year << endl;
}

int main()
{
    date d(2,2,3);
    d.enter_date();
    d.show_date();
    return 0;
}

