//============================================================================
// Name        : LineareReg.cpp
// Author      : Thomas Rometsch
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Spannungs als X-Werte
	double x[] = {0.5, 1,	1.5, 2,	2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6};
	// Strom als Y-Werte
	double y[] = {0.065, 0.206, 0.405, 0.492, 0.606, 0.782, 0.865, 1.018, 1.199, 1.327, 1.408, 1.627};
	double err[] = {0.01, 0.01, 0.02, 0.02, 0.02, 0.02, 0.02, 0.03, 0.03, 0.03, 0.03, 0.04};

	unsigned int L = 12; // Anzahl der Messwerte

	// Hilfsgrößen berechnen
	double S = 0;
	double Sx = 0;
	double Sy = 0;
	double Sxx = 0;
	double Sxy = 0;

	for (unsigned int i=0; i<L; i++) {
		double invvar = err[i]*err[i];
		S += invvar;
		Sx += x[i]*invvar;
		Sy += y[i]*invvar;
		Sxx += x[i]*x[i]*invvar;
		Sxy += x[i]*y[i]*invvar;
	}
	double Det = S*Sxx-Sx*Sx;

	double a = (Sxx*Sy - Sx*Sxy)/Det;
	double b = (S*Sxy-Sx*Sy)/Det;

	return 0;
}