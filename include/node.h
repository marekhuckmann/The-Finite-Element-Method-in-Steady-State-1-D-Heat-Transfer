#pragma once
#include <iostream>
using namespace std;

class node{
public:
	node(int ID, double x, int BC);
	node();

	int ID;
	double x;
	int BC;
};