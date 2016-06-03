/**
 * A simple driver for the MyPoly class
 */
#include <iostream>
#include "MyMatrix.h"
#define EPSILON 0.01

double myAbs(double d)
{
	if (d < 0)
	{
		return -d;
	}
	return d;
}

bool isEqualDouble(double d1, double d2)
{
	return (myAbs(d1-d2) < EPSILON);
}

int main()
{
	double constArr[4] = {1, 2., 0, 3.5};   
	double constArr2[4] = {1, 1.8, 0, 3.49999};   
	MyMatrix p1(constArr, 2, 2);
	MyMatrix p2(p1);
	if (!isEqualDouble(p1.trace(), p2.trace()))
	{
		std::cerr << "Fail test Copy Constructor" << std::endl;
		return 1;
	}
	if (!isEqualDouble(p1.trace(), 4.5))
	{
		std::cerr << "Fail test Trace" << std::endl;
		return 1;
	}
	if (!isEqualDouble(p2.frobeniusNorm(), 17.25))
	{
		std::cerr << "Fail test FrobNorm" << std::endl;
		return 1;
	}
	MyMatrix p3(constArr2, 2, 2);
	MyMatrix pminus = p1 - p3;
	if (!isEqualDouble(pminus.trace(), 0))
	{
		std::cerr << "Fail test minus" << std::endl;
		return 1;
	}
	
	std::cout << "Everything OK" << std::endl;
	return 0;
}
