#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    char *data;
    data = new char[100];
    ofstream outfile;
    outfile.open("input.txt");
    cout << "\t\t*Details info file about Manager.*"  << endl;

     cout << " Enter Manager's name >id>sex>serial  no: ";

    while(outfile){
    cin.getline(data,100);
    outfile << data << endl;
    cin >> data;
    outfile << data << endl;

    }


    cin.ignore();
    outfile<< data << endl;
    outfile.close();

    ifstream infile;
    infile.open("input.txt");
    cout<< "Reading from the file"<< endl;
    while(infile){
    infile >> data;
    cout << data <<endl;

    infile >> data;
    cout << data << endl;}

    //infile >> data;
    //cout << data << endl;

    infile.close();
    return 0;
}

