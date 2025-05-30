/*! @file CPolynomial.h
	@brief A class for polynomial functions 
	@author Alessandro Maryni
*/ 


#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "CFunction.h"
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Polynomial : public Function{
private:
    double* coeff;
    int degree;

public:
    
	/// @name CONSTRUCTORs and DESTRUCTOR 
	/// @{
    Polynomial();
	Polynomial(const double* coefficients, int size);
    Polynomial(const Polynomial& p);
    ~Polynomial();
	/// @}

	/// @name OPERATORS 
	/// @{
    Polynomial& operator=(const Polynomial& p);
	Polynomial operator+(const Polynomial& p);
	bool operator==(const Polynomial& p);
	/// @}


	void SetPolynomial(const double* coefficients, int size);
    double GetValue(double in);
	
	void Reset();

	/// @name DEBUG
	/// @{
	void Dump();
	/// @}
    
};

#endif