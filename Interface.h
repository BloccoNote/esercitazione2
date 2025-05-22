/*! @file Interface.h
	@brief Declaration of Interface functions
	@authors Alessandro Maryni & Mauro gori

	@mainpage Interface
	This header contains the declaration of funtion needed to create \n
	a vector of pointer to Function Classes (in CFuntion.h) and handlingg \n
	En example is in main.cpp
*/ 

#ifndef INTERFACE_H
#define INTERFACE_H

	#include "CPolynomial.h"
	#include "CExponential.h"
	#include "CLogarithmic.h"
	#include "Cpower.h"
	

	#include <bits/stdc++.h>

	/// @name Menu functions
	/// @{ 
	int menu();
	int insertFunctionMenu();
	/// @}

	/// @name Inesrt functions
	/// @{
	bool insertFunction(vector<Function *> &f);
	bool insertLog(vector<Function *> &f);
	bool insertPoly(vector<Function *> &f);
	bool insertPow(vector<Function *> &f);
	bool insertExp(vector<Function *> &f);
	/// @}
	
	
	/// @name Utility functions
	/// @{
	bool printFunctionList(vector<Function *> &f);
	bool eraseFunction(vector<Function *> &f);
	bool eraseAllFunctions(vector<Function *> &f);
	bool selectFuncion(vector<Function *> &f);
	/// @}

	/// @name estetic functions
	/// @{
	void clrscr();
	/// @}

#endif