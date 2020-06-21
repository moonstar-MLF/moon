#include "stdafx.h"
#include "win32.h"
#include<iostream>
using namespace std;

int factorial(int n) {
	int A=1;
	if (n < 0)return -1;
	if (n == 0 || n == 1)return A;
	else
		A = factorial(n - 1)*n;
	return A;
}

float FAC::convert(float edg)
{
	float result = 0;
	result = (edg / 57.3) * 1;
	return result;
}