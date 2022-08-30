#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

class date
{
private:
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

    if(year<2018 || year >=2019)
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

class account
{
	int acno;
	double date;
	char name[50];
	int deposit;
	char type;
public:
	void create_account();
	void show_account() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
};

void account::create_account()
{
    cout<<"\nEnter Date : "<< endl;
	cin>>date;
	cout<<"\nEnter The account No. : "<< endl;
	cin>>acno;
	cout<<"\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	cout<<"\n\n\nAccount Created.. :)";
}

void account::show_account() const
{
    cout<<"\nDate : "<<endl;
    cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : "<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance Amount : "<<deposit;
}


void account::modify()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}


int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}



void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void intro();



int main()
{
    char ch;
	int num;
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\tAccount Information:";
		cout<<"\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) : ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			modify_account(num);
			break;
		 case '8':
			cout<<"\n\n\tThanks for using bank managemnt system :)";
			break;
		 default :
		     cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
	return 0;
}



void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}



void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}




void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account.."<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found!";
}



void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}



void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}



void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT: ";
				cout<<"\n\nEnter The amount to be deposited:";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT: ";
				cout<<"\n\nEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance..";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated. :)";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ! ";
}



void intro()
{
    cout<< "\n\t Welcome To";
	cout<<"\n\n\n\t *** BANK MANAGEMENT SYSTEM ***";

	cin.get();


    date d(1,2,3);
    d.enter_date();
    d.show_date();
   // return 0;

}

