//
//  Matrix.h
//  Matrix
//
//  Created by Kaan Şengün on 15.11.2023.
//
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Matrix{
private:
    int row,col;
    int **matrix;
public:
    Matrix(int r=5,int c=5);
    ~Matrix();
    Matrix(const Matrix &oth);
    int getRowNumber(){return row;}
    int getColumNumber(){return col;}
    void setValue(int r,int c,int value);
    void randomSet();
    void identifyMatrixSet();
    void display();
    void addMatrix(const Matrix &othMatrix);
};
Matrix::Matrix(int r,int c){
    if(r>0&&c>0){
        row=r;
        col=c;
    }
    else{
        row=5;
        col=5;
    }
    
    matrix=new int *[row];
    for(int i=0;i<row;i++){
        matrix[i]=new int [col];
    }
    cout<<"Matrix created."<<endl;
    cout<<"Row:"<<row<<" "<<"Colum: "<<col<<endl;
    cout<<"\n";
}
Matrix::~Matrix(){
    for(int i=0;i<row;i++){
        delete matrix[i];
    }
    delete []matrix;
    cout<<"Matrix destroyed."<<endl;
}
Matrix::Matrix(const Matrix &oth){
    row=oth.row;
    col=oth.col;
    
    matrix=new int *[row];
    for(int i=0;i<row;i++){
        matrix[i]=new int [col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            matrix[i][j]=oth.matrix[i][j];
        }
    }
    cout<<"Matrix copied to target."<<endl;
    
}
void Matrix::setValue(int r, int c, int value){
    matrix[r][c]=value;
    
}
void Matrix::display(){
    cout<<"Matrix:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void Matrix::randomSet(){
    srand( static_cast<unsigned int>(time(nullptr)));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            matrix[i][j]=rand()%10;
        }
    }
}
void Matrix::identifyMatrixSet(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==j)
                matrix[i][j]=1;
            else{
                matrix[i][j]=0;
            }
        }
    }
}
void Matrix::addMatrix(const Matrix &othMatrix){
    if((row!=othMatrix.row)||(col!=othMatrix.col)){
        cout<<"Row and column should be equal."<<endl;
    }
    Matrix result(row,col);
    for(int i=0;i<result.row;i++){
        for(int j=0;j<result.col;j++){
            result.matrix[i][j]=matrix[i][j]+othMatrix.matrix[i][j];
        }
    }
    result.display();
    
    
}
