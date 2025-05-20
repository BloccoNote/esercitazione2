///TODO: add Interface.cpp and Interface.h
///TODO: add doxygen comments to files
///TODO: add doxygen comments to safeInsert.cpp
///TODO: add try_count to safeInsert(range) and (cond) for both int and double
///TODO: polish code and program

//standard headers
#include <bits/stdc++.h>
#include "stdio.h"

//classes headers
#include "CPolynomial.h"
#include "CExponential.h"
#include "CLogarithmic.h"
#include "Cpower.h"

//program headers
#include "safeInsert.h"
#include "Interface.h"

using namespace std;







/*
0 – Esci dal menù 

1 – Visualizza la vectora delle funzioni  

2 – Inserisci una funzione  

3 – Elimina una funzione  

4 – Elimina tutte le funzioni  

5 – Seleziona una funzione  
*/

/// @brief entry point of program
/// @return 0 or non zero value if errors 
int main(){
	//initializing dinamic array
	vector<Function *> F;

	int mode = 0;

	while(1){
		if((mode = menu()) == -1) return 1;
		switch (mode)
		{
		case 0:
			return 0;
			break;
		
		case 1:
			printFunctionList(F);
			cout << "(press enter to continue)" << endl;
			getchar();
			break;

		case 2:
			insertFunction(F);
			break;

		case 3:
			eraseFunction(F);
			break;

		case 4:
			eraseAllFunctions(F);
			break;

		case 5:
			selectFuncion(F);
			break;
		default:
			cout << "[ ERROR ] invalid mode value: " << mode << endl;
			break;
		}
	}
	cout << "[ ERRRO ] OUT OF BOUDNS " << endl;
	return 1;
}

