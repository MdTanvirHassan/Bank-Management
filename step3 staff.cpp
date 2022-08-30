
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char *data;
    data = new char[100];
    ofstream outfile;
    outfile.open("input.txt");
    cout << "\t\t*Details info file about Staffs.*"  << endl;

    cout << " Enter Staff's name : ";
    cin.getline(data,100);
    outfile << data << endl;

    cout<< " Enter Staff's id : ";
    cin >> data << endl;

    cin.ignore();
    outfile<< data << endl;
    outfile.close();

    ifstream infile;
    infile.open("input.txt");
    cout<< "Reading from the file"<< endl;

    infile >> data;
    cout << data <<endl;

    infile >> data;
    cout << data << endl;

    infile.close();
    return 0;
}

