// PhDThesisProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Header.h"
#include "MyVector.h"
//#include "boost\multi_array.hpp"




int main()
{
	using namespace std;

	MyVector test(10, 10, 10);

	test.SetX(1, 1, 1, 10.0);

	cout << "Value at [1][1][1] = " << (test.GetX())[1][1][1] << endl;

	return 0;
}

