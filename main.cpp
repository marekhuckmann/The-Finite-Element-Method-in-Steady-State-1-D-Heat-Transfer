#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include "node.h"
#include "element.h"
#include "mesh.h"

using namespace std;

int main() {
	fstream data;
	data.open( "data.txt", std::ios::in | std::ios::out );;
	if(data.good() == true)
		cout << "Data accessed." << endl;
	else
		cout << "No data file found." << endl;

	double L;
	int nodeCounter;
	int elementCounter;
	int ID[100];            // ID
	double x[100];          // length
	int BC[100];            // Boundary Condition

	data >> nodeCounter;
	for (int i = 0; i<nodeCounter; i++) {
		data >> ID[i] >> x[i] >> BC[i];
	}

	// Creating nodes:
	node n1(ID[0], x[0], BC[0]);
	node n2(ID[1], x[1], BC[1]);
	node n3(ID[2], x[2], BC[2]);

	double S, k, alfa, aTemp, q;  //  surface, thermal conductivity, convection coefficient, ambient temperature, heat flux density
	data >> S >> k >> alfa >> aTemp >> q;
    
	// Creating elements:
	element e1(n1, n2, S, k, alfa, aTemp, q);
	element e2(n2, n3, S, k, alfa, aTemp, q);

	// Creating mesh:
	element e[] = {e1, e2};
	mesh m1(nodeCounter-1,nodeCounter,e);

	m1.showME();
	m1.gaussJordan();
	m1.showResults();

    system("PAUSE")
    return 0;
}
