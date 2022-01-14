#include<iostream>
#include<cmath>
//test
double dot(double *u, int dim_u, double *v, int dim_v) {

	if (dim_u != dim_v || dim_u <= 0 || dim_v <= 0) {
    	throw std::string("undefined.");
	}

	double result = 0;

  	for(int i = 0;i < dim_u;i++){
        result += (u[i] * v[i]); 
  	}

  	return result;
} 
