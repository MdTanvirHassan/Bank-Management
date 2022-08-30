#include<iostream>
using namespace std;

class Matrix {
private:
    double **twoDArray;
    int row;
    int col;
public:
    Matrix(int row, int col) {
        this->row = row;
        this->col = col;
        twoDArray = new double*[this->row];
        for(int i=0;i<this->row;i++) {
            twoDArray[i] = new double[this->col];
        }
    }
    void setValue(int i, int j, double val) {
        twoDArray[i][j] = val;
    }
    double getValue(int i, int j) {
        return twoDArray[i][j];
    }
    Matrix operator+(const Matrix & m) {
        if(m.row != this->row || m.col != this->col) {
            throw "Two Matrices are not of similar dimension";
        }
        Matrix tempMatrix (this->row, this->col);
        for(int i=0;i<this->row;i++) {
            for(int j=0;j<this->col;j++) {
                tempMatrix.twoDArray[i][j] = this->twoDArray[i][j]+m.twoDArray[i][j];
            }
        }
        return tempMatrix;
    }
    Matrix operator-(const Matrix & m) {
        if(m.row != this->row || m.col != this->col) {
            throw "Two Matrices are not of similar dimension";
        }
        Matrix subtractMat (this->row, this->col);
        for(int i=0;i<this->row;i++) {
            for(int j=0;j<this->col;j++) {
                subtractMat.twoDArray[i][j] = this->twoDArray[i][j]-m.twoDArray[i][j];
            }
        }
        return subtractMat;
    }

    Matrix operator*(const Matrix & m) {
        if(m.row != this->row || m.col != this->col) {
            throw "Two Matrices are not of similar dimension";
        }
        Matrix multiplyMatrix (this->row, this->col);
        for(int i=0;i<this->row;i++) {
            for(int j=0;j<this->col;j++) {
                multiplyMatrix.twoDArray[i][j] = this->twoDArray[i][j]*m.twoDArray[i][j];
            }
        }
        return multiplyMatrix;
    }
};

int main() {
    int row,col;
    cout<<"Enter number of rows for first matrix: "<<endl;
    cin>>row;
    cout<<"Enter number of columns for first matrix: "<<endl;
    cin>>col;
    Matrix matrix1(row,col);
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<"Insert value at index("<<i<<","<<j<<")"<<endl;
            double val = 0.0;
            cin>>val;
            matrix1.setValue(i,j,val);
        }
    }
    cout<<"Your matrix is as follows: "<<endl;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<matrix1.getValue(i,j)<<"       ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"Enter number of rows for second matrix: "<<endl;
    cin>>row;
    cout<<"Enter number of columns for second matrix: "<<endl;
    cin>>col;
    Matrix matrix2(row,col);
    Matrix matrix3(row,col);
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<"Insert value at index("<<i<<","<<j<<")"<<endl;
            double val = 0.0;
            cin>>val;
            matrix2.setValue(i,j,val);
        }
    }
    cout<<"Your matrix is as follows: "<<endl;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<matrix2.getValue(i,j)<<"       ";
        }
        cout<<endl;
    }

    try {
        cout<<endl<<"Sum of two matrices.. "<<endl;
        matrix3 = matrix1 + matrix2;
        cout<<"Your result matrix is as follows: "<<endl;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
            cout<<matrix3.getValue(i,j)<<"       ";
            }
            cout<<endl;
        }
    }
    catch(const char *errMessage ) {
        cerr<<"Error message: "<<errMessage<<endl;
    }
    try {
        cout<<endl<<"Subtraction of two matrices.. "<<endl;
        matrix3 = matrix1 - matrix2;
        cout<<"Your result matrix is as follows: "<<endl;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
            cout<<matrix3.getValue(i,j)<<"       ";
            }
            cout<<endl;
        }
    }
    catch(const char *errMessage ) {
        cerr<<"Error message: "<<errMessage<<endl;
    }

    try {
        cout<<endl<<"Multiplication of two matrices.. "<<endl;
        matrix3 = matrix1 * matrix2;
        cout<<"Your result matrix is as follows: "<<endl;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
            cout<<matrix3.getValue(i,j)<<"       ";
            }
            cout<<endl;
        }
    }
    catch(const char *errMessage ) {
        cerr<<"Error message: "<<errMessage<<endl;
    }

    return 0;
}
