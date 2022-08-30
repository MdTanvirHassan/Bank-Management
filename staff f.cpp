#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int j=1,y;
    cout<<"Enter Number of Staff's :  "<<endl;
    cin>>y;
    while(j<=y)
    {
        char *data;
        data=new char[100];
        ofstream outfile;
        outfile.open("staff.txt");
        cout<<"Enter "<<j<<"th Staff ID : "<<endl;
        cin>>data;
        outfile<<data<<endl;
        cout<<"His/Her Blood Group : "<<endl;
        cin>>data;
        outfile<<data<<endl;
        cout<<"Sex : "<<endl;
        cin>>data;
        outfile<<data<<endl;
        cout<<"His/Her Age : "<<endl;
        cin>>data;
        outfile<<data<<endl;
        cout<<"Previous Work Experience :  "<<endl;
        cin>>data;
        outfile<<data<<endl;
        cout<<"His/Her Salary :  "<<endl;
        cin>>data;
        outfile<<data<<endl;
        outfile.close();
        cout<<endl<<endl;
        ifstream infile;
        infile.open("Staff.txt");
        infile>>data;
        cout<<"Staff's ID :  "<<data<<endl;
        cout<<"\nSerial number :  "<<j<<endl;
        infile>>data;
        cout<<"\nBlood Group :  "<<data<<endl;
        infile>>data;
        cout<<"\nSex :  "<<data<<endl;
        infile>>data;
        cout<<"\nHis/Her Age :  "<<data<<endl;
        infile>>data;
        cout<<"\nWork Experience :  "<<data<<endl;
        infile>>data;
        cout<<"\nHis/Her Salary :  "<<data<<endl;
        infile.close();
        j++;
        cout<<endl<<endl;
    }
return 0;
}

