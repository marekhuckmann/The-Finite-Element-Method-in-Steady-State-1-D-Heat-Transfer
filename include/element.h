#pragma once
#include <iostream>
#include "node.h"

using namespace std;

class element
{
public:
	element(node left, node right, double S, double k, double alfa, double aTemp, double q);

	double L;
	double alfa;
	double S;
	double k;
	double HL[2][2];
	double PL[2];
	double C;
	double aTemp;
	double q;

	node left;
	node right;
};