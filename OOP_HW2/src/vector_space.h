#ifndef VECTOR_SPACE_H
#define VECTOR_SPACE_H
#include <string>

double *add(double mv1[],int dim1,double mv2[],int dim2){
    if(dim1 != dim2){
        throw std::string("undefined.");
    }
    if(dim1 <= 0 || dim2 <= 0){
        throw std::string("undefined.");
    }
    double *anmv = new double[dim1];
    for(int i = 0;i < dim1;i++){
        anmv[i] = mv1[i] + mv2[i];
    }
    return anmv;
}
double *scale(double mv1[],int dim1,double con){
    if(dim1 <= 0){
        throw std::string("undefined.");
    }
    double *anmv = new double[dim1];
    for(int i = 0;i < dim1;i++){
        anmv[i] = mv1[i] * con;
    }
    return anmv;
}

#endif