//
//  main.cpp
//  Matrix
//
//  Created by Kaan Şengün on 15.11.2023.
//

#include <iostream>
#include "Matrix.h"
using namespace std;



int main(int argc, const char * argv[]) {
    
    Matrix mainMatrix(-2,-2);
    /*for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            mainMatrix.setValue(i, j, i*j);
        }
    }*/
    mainMatrix.randomSet();
    mainMatrix.display();
    Matrix mainMatrix2;
    mainMatrix2.identifyMatrixSet();
    mainMatrix2.display();
    
    Matrix mainMatrix3=mainMatrix2;
    mainMatrix3.display();
    mainMatrix.addMatrix(mainMatrix2);
    
    return 0;
}
