#ifndef INTERFACE_H
#define INTERFACE_H

	#include "CPolynomial.h"
	#include "CExponential.h"
	#include "CLogarithmic.h"
	#include "Cpower.h"
	

	#include <bits/stdc++.h>

	
	bool insertPoly(vector<Function *> &f);
	bool insertPow(vector<Function *> &f);
	bool insertExp(vector<Function *> &f);
	
	int menu();
	bool insertFunction(vector<Function *> &f);

	bool printFunctionList(vector<Function *> &f);
	bool eraseFunction(vector<Function *> &f);
	bool eraseAllFunctions(vector<Function *> &f);
	bool selectFuncion(vector<Function *> &f);

	int insertFunctionMenu();
	bool insertLog(vector<Function *> &f);



#endif