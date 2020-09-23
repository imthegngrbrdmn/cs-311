/*
File:		dp3.cpp
Author:		Millard A. Arnold V
Started:	2020-09-21
Updated:	2020-09-21
Project:	CS-311 Project 3

Source file for Project 3 Functions

Using skeleton file
provided by Glenn G. Chappell
written on 2020-09-17
*/

#include "dp3.h"       // For Project 3 prototypes & templates

using std::function;


void didItThrow(const function<void()> & ff,
                bool & threw)
{
	try
	{
		ff();
	}
	catch (...)
	{
		threw = true;
		throw;
	}
	threw = false;
}


int gcd(int a,
        int b)
{
	if (a == 0)
	{
		return b;
	}
	if (a > b)
	{
		return gcd(b, a);
	}
	return gcd(b % a, a);
}

