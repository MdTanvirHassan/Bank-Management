#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<ctime>

using namespace std;

class Staff
{
private:
    int ID,age,phone;
    char name[20],gender[10];
    double salary;
public:
    void setValue()
    {
        cout<<"\n\n\t\t## Adding Staff Info ##";
        cout<<endl<<"Input Name: ";
        fflush(stdin);
        cin.getline(name,19);
        cout<<endl<<"Input Gender: ";
        fflush(stdin);
        cin.getline(gender,9);
        cout<<endl<<"Input Age: ";
        cin>>age;
        cout<<endl<<"Input ID: ";
        cin>>ID;
        cout<<endl<<"Input Phone: ";
        cin>>phone;
        cout<<endl<<"Input Salary: ";
        cin>>salary;
    }
    int storeStaffData()
    {
        ofstream fout;
        fout.open("Staff Information.txt",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
    }

    void deleteStaffData(int id)
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("Staff Information.txt",ios::in|ios::binary);
        if(!fin)
        {
            cout<<"\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("temp.txt",ios::out|ios::binary);
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(id!=ID)
                {
                    fout.write((char*)this,sizeof(*this));
                }
                else
                {
                    c++;
                }
                fin.read((char*)this,sizeof(*this));
            }
            if(c==0)
            {
                cout<<"ID Not Found"<<endl;
            }
            else
            {
                cout<<"\n\tDeleted Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Staff Information.txt");
            rename("temp.txt","Staff Information.txt");
        }
    }

    void editStaffData(int id)
    {
        int c=0;
        fstream file;
        file.open("Staff Information.txt",ios::in|ios::out|ios::ate|ios::binary);
        file.seekg(0);
        file.read((char*)this,sizeof(*this));
        while(!file.eof())
        {
            if(id==ID)
            {
                c++;
                setValue();
                file.seekg(file.tellg()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
            }
            file.read((char*)this,sizeof(*this));
        }
        if(c==0)
        {
            cout<<"ID Not Found"<<endl;
        }
        else
        {
            cout<<"\n\tEdited Successfully!!!\n\n";
        }
    }

    void searchStaffData(int id)
    {
        int c=0;
        ifstream fin;
        fin.open("Staff Information.txt",ios::in|ios::binary);
        if(!fin)
        {
            cout<<"NO File Found";
        }
        else
        {
            cout<<"\n\nName\t\tGender\t\tAge\t\tID\t\tPhone\t\tSalary"<<endl;
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                if(id==ID)
                {
                    c++;
                    showStaffData();
                }
                fin.read((char*)this,sizeof(*this));
            }
            if(c==0)
            {
                cout<<"ID Not Found"<<endl;
            }
            fin.close();
        }
    }

    void viewAllStaffData()
    {
        ifstream fin;
        fin.open("Staff Information.txt",ios::in|ios::binary);
        if(!fin)
        {
            cout<<"No File Found";
        }
        else
        {
            cout<<"\n\nName\t\tGender\t\tAge\t\tID\t\tPhone\t\tSalary"<<endl;
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof())
            {
                showStaffData();
                fin.read((char*)this,sizeof(*this));
            }
        }
        fin.close();
    }

    void showStaffData()
    {
        cout<<name<<"\t\t"<<gender<<"\t\t"<<age<<"\t\t"<<ID<<"\t\t"<<phone<<"\t\t"<<salary<<endl;
    }


};


int Menu()
{
    cout<<"\t\t\t\tWelcome to Staff Management System"<<endl<<endl<<endl;
    cout<<endl<<endl<<"\t\t\t#####\tMain Menu\t#####"<<endl<<endl;
    cout<<"\t\t[1] Add Staff Info"<<endl;
    cout<<"\t\t[2] Remove Staff Info"<<endl;
    cout<<"\t\t[3] Edit Staff Info"<<endl;
    cout<<"\t\t[4] Search Staff Info"<<endl;
    cout<<"\t\t[5] Display All Staff List"<<endl;
    cout<<"\t\t[6] Quit"<<endl<<endl;
    cout<<"\tPlease Enter Your Choice: ";
    int Choice;
    cin>>Choice;
    return Choice;
}

void Time()
{
    time_t now;
    struct tm nowlocal;
    now=time(NULL);
    nowlocal=*localtime(&now);
    cout<<"\t\tToday's Date is: ";
    cout<<nowlocal.tm_mday<<"/"<<nowlocal.tm_mon<<"/"<<nowlocal.tm_year+1900<<endl;
    cout<<"\t\tCurrent Time is: ";
    cout<<nowlocal.tm_hour<<":"<<nowlocal.tm_min<<endl<<endl<<endl;
}

int main()
{
    Staff s;
    char e;
    int id;
    Time();
    cout<<"\tPlease Press Any Key to Start!!!";
    getch();
    while(1)
    {
        system("cls");
        Time();
        switch(Menu())
        {
            case 1:
                do
                {
                    system("cls");
                    Time();
                    s.setValue();
                    s.storeStaffData();
                    cout<<"\n\tAdded Successfully!!!\n\n";
                    cout<<"\n\nAdd More!! (Y/N): ";
                    fflush(stdin);
                    cin>>e;
                }while(e=='y'||e=='Y');
                break;
            case 2:
                do
                {
                    system("cls");
                    Time();
                    cout<<"\n\n\t\t## Deleting Staff Info ##\n\n";
                    cout<<"\n\n\tInput ID: ";
                    cin>>id;
                    s.deleteStaffData(id);
                    cout<<"\n\nDelete More!! (Y/N): ";
                    fflush(stdin);
                    cin>>e;
                }while(e=='y'||e=='Y');
                break;
            case 3:
                do
                {
                    system("cls");
                    Time();
                    cout<<"\n\n\t\t## Editing Staff Info ##\n\n";
                    cout<<"\n\n\tInput ID: ";
                    cin>>id;
                    s.editStaffData(id);
                    cout<<"\n\nEdit More!! (Y/N): ";
                    fflush(stdin);
                    cin>>e;
                }while(e=='y'||e=='Y');
                break;
            case 4:
                do
                {
                    system("cls");
                    Time();
                    cout<<"\n\n\t\t## Searching Staff Info ##\n\n";
                    cout<<"\n\n\tInput ID: ";
                    cin>>id;
                    s.searchStaffData(id);
                    cout<<"\n\n";
                    cout<<"\n\nSearch More!! (Y/N): ";
                    fflush(stdin);
                    cin>>e;
                }while(e=='y'||e=='Y');
                break;
            case 5:
                system("cls");
                Time();
                s.viewAllStaffData();
                cout<<"\n\n\n";
                cout<<"\tPress Any Key for Main Menu!!!  ";
                getch();
                break;
            case 6:
                system("cls");
                Time();
                cout<<"\tPress Any Key to Close The Program!!!\n\n";
                getch();
                cout<<"\n\t\tThe Program Has Made By EWU CSE107 Section-9";
                cout<<"\n\n\t\tAll Credit Goes To >===>\n\n";
                cout<<std::left<<setw(30)<<"\t\t1. Riffat Ara Khan Tayna"<<"\t\tID:2018-1-60-183\n";
                cout<<std::left<<setw(30)<<"\t\t2. Robayed Ashraf"<<"\t\tID:2018-1-60-238\n";
                cout<<std::left<<setw(30)<<"\t\t3. Md. Tanvir Hossain Joarddar"<<"\t\tID:2018-1-60-242\n";
                cout<<std::left<<setw(30)<<"\t\t4. Nawfat Tahsin Azad"<<"\t\tID:2018-1-60-247\n";
                exit(0);
            default:
                system("cls");
                Time();
                cout<<"\tInvalid Choice!!!!!"<<endl;
                cout<<"\tPress Any Key to Try Again......"<<endl<<endl;
                getch();
        }
    }
}
