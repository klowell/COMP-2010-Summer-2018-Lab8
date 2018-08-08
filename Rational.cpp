/*****************************************************************************************
Project Name: Lab 8
Name: Kristopher Lowell
Date Completed: 8/8/2018
Purpose: Using a class with overloaded operators, add, subtract, multiply, and divide
two rational numbers represented by two integers each.
*****************************************************************************************/
#include "Rational.h"

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int wholeNumber)
{
	numerator = wholeNumber;
	denominator = 1;
}

Rational::Rational(int numeratorVal, int denominatorVal)
{
	numerator = numeratorVal;

	if (denominatorVal == 0)
		denominator = 1;
	else
		denominator = denominatorVal;
}

Rational::Rational(Rational &number)
{
	numerator = number.numerator;
	denominator = number.denominator;
}

void Rational::normalize()
{
	if ((numerator * denominator) > 0)
	{
		numerator = abs(numerator);
		denominator = abs(denominator);
	}
	else if (numerator > 0)
	{
		numerator = 0 - numerator;
		denominator = abs(denominator);
	}

	for (int i = abs(numerator); i > 1; i--)
	{
		if (numerator % i == 0 && denominator % i == 0)
		{
			numerator /= i;
			denominator /= i;
		}
	}
}

bool operator == (Rational const &num1, Rational const &num2)
{
	return (num1.numerator * num2.denominator) == (num2.numerator * num1.denominator);
}

bool operator < (Rational const &num1, Rational const &num2)
{
	if (num1.denominator > 0 && num2.denominator > 0)
		return (num1.numerator * num2.denominator) < (num2.numerator * num1.denominator);
	else
		return (num1.numerator * num2.denominator) > (num2.numerator * num1.denominator);
}

bool operator > (Rational const &num1, Rational const &num2)
{
	if (num1.denominator > 0 && num2.denominator > 0)
		return (num1.numerator * num2.denominator) > (num2.numerator * num1.denominator);
	else
		return (num1.numerator * num2.denominator) < (num2.numerator * num1.denominator);
}

Rational operator + (Rational const &num1, Rational const &num2)
{
	Rational result;

	int tempNumerator1 = num1.numerator * num2.denominator;
	int tempNumerator2 = num2.numerator * num1.denominator;
	result.numerator = tempNumerator1 + tempNumerator2;
	result.denominator = num1.denominator * num2.denominator;

	result.normalize();
	return result;
}

Rational operator - (Rational const &num1, Rational const &num2)
{
	Rational result;

	int tempNumerator1 = num1.numerator * num2.denominator;
	int tempNumerator2 = num2.numerator * num1.denominator;
	result.numerator = tempNumerator1 - tempNumerator2;
	result.denominator = num1.denominator * num2.denominator;

	result.normalize();
	return result;
}

Rational operator * (Rational const &num1, Rational const &num2)
{
	Rational result;

	result.numerator = num1.numerator * num2.numerator;
	result.denominator = num1.denominator * num2.denominator;

	result.normalize();
	return result;
}

Rational operator / (Rational const &num1, Rational const &num2)
{
	Rational result;

	result.numerator = num1.numerator * num2.denominator;
	result.denominator = num1.denominator * num2.numerator;

	result.normalize();
	return result;
}

istream &operator >> (istream &is, Rational &num)
{
	int numeratorValue, denominatorValue;

	is >> numeratorValue >> denominatorValue;

	num.setNumerator(numeratorValue);
	num.setDenominator(denominatorValue);

	num.normalize();

	return is;
}

ostream &operator << (ostream &os, Rational &num)
{
	int numeratorValue = num.getNumerator();
	int denominatorValue = num.getDenominator();

	os << numeratorValue << "/" << denominatorValue;

	num.normalize();

	return os;
}