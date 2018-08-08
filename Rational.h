/*****************************************************************************************
Project Name: Lab 8
Name: Kristopher Lowell
Date Completed: 8/8/2018
Purpose: Using a class with overloaded operators, add, subtract, multiply, and divide
two rational numbers represented by two integers each.
*****************************************************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cmath>

using namespace std;

class Rational
{
public:
	Rational();
	Rational(int wholeNumber);
	Rational(int numeratorVal, int denominatorVal);
	Rational(Rational &number);

	int getNumerator() { return numerator; }
	int getDenominator() { return denominator; }

	void setNumerator(int numeratorVal) { numerator = numeratorVal; }
	void setDenominator(int denominatorVal) { denominator = denominatorVal; }
	void setAsWholeNumber(int wholeNumber) { numerator = wholeNumber; denominator = 1; }
	void normalize();

	friend bool operator == (Rational const &num1, Rational const &num2);
	friend bool operator < (Rational const &num1, Rational const &num2);
	friend bool operator > (Rational const &num1, Rational const &num2);

	friend Rational operator + (Rational const &num1, Rational const &num2);
	friend Rational operator - (Rational const &num1, Rational const &num2);
	friend Rational operator * (Rational const &num1, Rational const &num2);
	friend Rational operator / (Rational const &num1, Rational const &num2);

	friend istream &operator >> (istream &is, Rational &num);
	friend ostream &operator << (ostream &os, Rational &num);

private:
	int numerator;
	int denominator;
};

#endif