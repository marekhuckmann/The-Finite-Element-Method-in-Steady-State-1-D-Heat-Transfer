#include "element.h"

element::element(node left, node right, double S, double k, double alfa, double aTemp, double q) {
	this->left = left;
	this->right = right;

	L = right.x - left.x;
	C = S*k/L;

	// left
	if (left.BC == 0) {
		HL[0][0] =  C;
		HL[0][1] = -C;
		PL[0] =     0;
	}

	else if (left.BC == 1) {
		HL[0][0] =  C;
		HL[0][1] = -C;
		PL[0] =     q*S;
	}

	else if (left.BC == 2) {
		HL[0][0] =   C + (alfa*S);
		HL[0][1] =  -C;
		PL[0] =     -aTemp*alfa*S;
	}

	// right
	if (right.BC == 0) {
		HL[1][0] = -C;
		HL[1][1] =  C;
		PL[1] =	    0;
	}

	else if (right.BC == 1) {
		HL[1][0] = -C;
		HL[1][1] =  C;
		PL[1] =     q*S;
	}

	else if (right.BC == 2){
		HL[1][1] =   C + alfa*S;
		HL[1][0] =  -C;
		PL[1] =     -aTemp*alfa*S;
	}
}
