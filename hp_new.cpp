#include<iostream>
//#include<conio.h>
#include<stdlib.h>
//#include<fstream>
using namespace std;

class date
{
    int day,month,year;
public:
    date(int da,int mon,int yr)
    {
        day=da;
        month=mon;
        year=yr;
    }

    void enter_date();
    void show_date();
};

void date:: enter_date()
{

    cout<< "First of all you have  to give the current date:"<< "\n\n\n";
    cout<< "Year:";
    cin>> year;

    /*if(year<=0||year >=2019)
         {do
             {cin>> year;
             cout<< "Wrong input"<< endl<< "please again enter the year "<< endl;}
             while(year<=0||year >=2019);
         }*/


    if(year<=0)
    {
        cout<< "Wrong input"<< endl<< "please again enter the year "<< endl;
    }

    cout<< "Month:";
    cin>> month;
    if(month<=0 ||month>12)
    {
        cout<< "Wrong input"<< endl<< "please again enter the month "<< endl;
    }

    cout<< "Date:";
    cin>> day;
    if(day<=0 || day >= 31)
    {
        cout<< "Wrong input!!!!"<< endl<< "please again enter the date"<< endl;
    }

}

void date::show_date()
{


    system("CLS");
    cout<< "it is ";
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

    }/// end of date funtion(work)..


    switch(month)/// start month  work
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
    date d(1,2,3);
    d.enter_date();
    d.show_date();
    return 0;
}

