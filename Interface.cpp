/*! @file Interface.cpp
	@brief implementation of interface functions 
	@author Alessandro Maryni & Mauro Gori
	@note formerly Gori_func.cpp
*/ 


#include "Interface.h"
#include "safeInsert.h"

///@brief polynomial function creation wizard
///@param f reference of pointers to class Function
///@returns true if succesful
///@note inserts in the array of pointers the created function
bool insertPoly(vector<Function *> &f){
	double* c;	//pointer to int array
    int d;		//degree
	Polynomial* p;
	printf("\e[1;1H\e[2J");
	cout<<"### Polynomial Function creation wizard###"<<endl;
	cout<<"insert function degree"<<endl;
	safeInsert(d, 0, GE);
	c = new double[d + 1];
	for(int i = 0; i < d +1; i++){
		cout<<"insert coefficent of degree: "<<i<<endl;
		safeInsert(c[i]);
	}
	
	p = new Polynomial(c, d + 1);
	f.push_back(p);
	return true;
}
//k * x ^ e
///@brief Power Function creation wizard
///@param f reference of pointers to class Function
///@returns true if successful
///@note inserts in the array of pointers the created function
bool insertPow(vector<Function *> &f){
	double k;
	double e;
	Power* p;
	printf("\e[1;1H\e[2J");
	cout<<"### Power Function creation wizard ###"<<endl;
	cout<<"insert k coefficent"<<endl;
	safeInsert(k);
	cout<<"insert e coefficent"<<endl;
	safeInsert(e);
	p = new Power(k, e);
	f.push_back(p);
	return true;
}
///@brief Exponential Function creation wizard
///@param f reference of pointers to class Function
///@returns true if successful
///@note inserts in the array of pointers the created function
bool insertExp(vector<Function *> &f){
	double k;
	double b;
	double c;
	Exponential* e;
	printf("\e[1;1H\e[2J");
	cout<<"### Exponential Function creation wizard ###"<<endl;
	cout<<"insert k coefficent"<<endl;
	safeInsert(k);
	cout<<"insert c coefficent"<<endl;
	safeInsert(c);
	cout<<"insert b coefficent"<<endl;
	safeInsert(b, 0, GT);
	e = new Exponential(k, b ,c);
	f.push_back(e);
	return true;
	
}

/// @brief prints main menu and make the user choose the mode
/// @return returns the  mode, integer from 0 to 5
int menu(){
	int mode = 0;
	int try_num = 0;
	printf("\e[1;1H\e[2J");
	cout << "### main menu ###" << endl;
	cout << "insert selection and press enter" << endl;
	cout << "0 - Exit menu  and program" << endl;
	cout << "1 - visualize function vector" << endl;
	cout << "2 - Insert a function" << endl;
	cout << "3 - Erase a function" << endl;
	cout << "4 - Erase all function" << endl;
	cout << "5 - Select a function" << endl;
	if(!safeInsert(mode, 0 , 5)) return -1;

	return mode;
}


/*

function indexes
0 exit
1 log
2 poly
3 pow
4 exp

*/

///@brief allow to insert function to funciton pointer array f
///@param f reference of pointers to class Functionion 
///@returns true if successful or false if fails.
bool insertFunction(vector<Function *> &f){
	int mode = 0;
	double coeff = 0;
	if((mode = insertFunctionMenu()) == -1) return false;
	switch (mode)
	{
	case 0:
		return true;
		break;
	case 1:
		insertLog(f);
		break;

	case 2:
		insertPoly(f);
		break;

	case 3:
		insertPow(f);
		break;
	
	case 4:
		insertExp(f);
		break;
	
	default:
		break;
	}
	return true;	
}


///@brief prints list of existing function objects
///@param f reference of pointers to class Function
///@returns true if printed successfully or false if array is empty
bool printFunctionList(vector<Function *> &f){
	int size = f.size();
	printf("\e[1;1H\e[2J");
	cout << "### Function vector ###" << endl;
	if(f.empty()){
		cout << endl << "[ INFO ] vector is empty " << endl << endl;
		return false;
	}
	else{
		for(int i = 0; i < size; i++){
			cout << i << ":   ";
			f[i]->Dump();
		}
	}
	return true;
}
///@brief deletes a specific function from the array
///@param f reference of pointers to class Function
///@returns true if deleted successfully or false if failed. 
bool eraseFunction(vector<Function *> &f){
	int erase_index = 0;
	int max_index = f.size();
	if(!printFunctionList(f)){
		return false;
	}
	cout << "insert the index of function to delete" << endl;
	if(!safeInsert(erase_index, 0, max_index-1)) return false;
	delete f[erase_index];
	f[erase_index] = NULL;
	f.erase(f.begin() + erase_index);
	
	return true;
}

///@brief deletes all objects from the array
///@param f reference of pointers to class Function
///@returns true if deleted successfully or false if failed. 
bool eraseAllFunctions(vector<Function *> &f){
	cout << "[ INFO ] Erasing all functions in list" << endl;
	if(!f.empty()){
		while(!f.empty()){
			delete f[f.size()-1];
			f.erase(f.end());
		}
	}
	///TODO: metti messaggi più belli
	cout << "[ INFO ] success" << endl;
	return true;
}

///@brief logarithmic function creator
///@param f reference of pointers to class Function
///@returns true if successful
bool insertLog(vector<Function *> &f){
	double b;
	double k;
	Logarithmic* l;
	l = new Logarithmic;
	printf("\e[1;1H\e[2J");
	cout<<"### logarithmic function creation wizard ###"<<endl;
	while(1){
		cout<<"insert base coefficent \nbase coefficent must be > 0 and not 1"<<endl;
		safeInsert(b, 0 ,GT);
		if(b != 1){
			break;
		}else{
			cout<<"[ ERROR ] b coefficent should be not equal to 1"<< endl;
		}
	}
	cout<<"insert k coefficent"<<endl;
	safeInsert(k);
	l->SetLogarithmic(b, k);
	Function* func = l;
	f.push_back(func);
	return true;
}

///@brief prints menu to select function to create
///@returns selection 
int insertFunctionMenu(){
	int select;
	printf("\e[1;1H\e[2J");
	cout<<"### function creation wizard ###"<< endl;
	cout<<"0 - return to main menu"<<endl;
	cout<<"1 - create logarithmic function"<<endl;
	cout<<"2 - create polynomial function"<<endl;
	cout<<"3 - create power function"<<endl;
	cout<<"4 - create exponential function"<<endl;
	if(!safeInsert(select, 0, 4)) return -1;
	return select;
}

///@brief allows the user to pick a specific function from the object array
///@param f reference of pointers to class Function
///@returns true if successful or false if fails
bool selectFuncion(vector<Function *> &f){
	int select_index = 0;
	int mode = 0;
	double x;
	int max_index = f.size();
	if(!printFunctionList(f)){
		return false;
	}
	cout << "--- Select a function ---" << endl;
	cout << "value should be between 0 and " << max_index - 1 << endl;
	if(!safeInsert(select_index, 0, max_index-1)) return false;
	while(1){
		printf("\e[1;1H\e[2J");
		cout << "### function selected ###" << endl;
		f[select_index]->Dump();
		cout << "0 - exit evaluation" << endl;
		cout << "1 - evaluate funciton" << endl;
		if(!safeInsert(mode, 0 , 1)) return false;
		cout << "###   ###" << endl;
		switch(mode)
		{
		case 0:
			return true;

		case 1:
			cout << "insert evaluation point (x = )" << endl;
			safeInsert(x);
			cout << "f("<< x << ") = " << f[select_index]->GetValue(x) << endl;
			cout << "(press enter to continue)" << endl;
			getchar();
			break;
		}
	}
	return true;
}