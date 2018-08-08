/*****************************************************************************************
Project Name: Lab 8
Name: Kristopher Lowell
Date Completed: 8/8/2018
Purpose: Using a class with overloaded operators, add, subtract, multiply, and divide
two rational numbers represented by two integers each.
*****************************************************************************************/

#include "Rational.h"

using namespace std;

int main(int argc, char *argv[])
{
	Rational X, Y, Z;
	int entry;

	cout << "Enter the numerator and denominator of the first rational number (X): ";
	cin >> X;
	
	cout << "Enter the numerator and denominator of the second rational number (Y): ";
	cin >> Y;

	cout << "-X = " << X << endl;
	cout << "-Y = " << Y << endl;

	Z = X + Y;
	cout << "X + Y = " << X << " + " << Y << " = " << Z << endl;

	Z = X - Y;
	cout << "X - Y = " << X << " - " << Y << " = " << Z << endl;

	Z = X * Y;
	cout << "X * Y = " << X << " * " << Y << " = " << Z << endl;

	Z = X / Y;
	cout << "X / Y = " << X << " / " << Y << " = " << Z << endl;

	cout << "Is X < Y or Y < X? ";
	if (X < Y)
		cout << X << " < " << Y << endl;
	else
		cout << Y << " < " << X << endl;

	cout << "Is Y > X or X > Y? ";
	if (Y > X)
		cout << Y << " > " << X << endl;
	else
		cout << X << " > " << Y << endl;

	cin >> entry;

	return 0;
}