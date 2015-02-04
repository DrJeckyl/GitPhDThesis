// PhDThesisProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MyVector.h"
#include "boost\multi_array.hpp"

int main()
{
	using namespace std;
	cout << "compiled, yay!" << endl;

	MyVector test_array(1,1,1);

	cout << "Array size is:" << sizeof(MyVector) << " in Bytes." << endl;
	cout << "1 float is size: " << sizeof(1.f) << " Bytes." << endl;
	cout << "So, Array is, " << static_cast<float>(sizeof(MyVector) / sizeof(1.)) << " floats " << endl;

	array_type output = test_array.GetX();
	index i = 0;
	cout << "Testing the array access functions:" << endl;
	cout << "GetX() produces: " << output[i][i][i];

	return 0;
}

