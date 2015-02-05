// PhDThesisProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MyVector.h"
#include "array3d.h"




int main()
{
	using namespace std;

	MyVector test(5, 5, 5);

	test.x(1, 1, 1) = 10.;

	cout << "Value at [1][1][1] = " << test.x(1,1,1) << endl;

	cout << "Test 2 using array3d:" << endl;
	
	array3d test1(5, 5, 5);
	array3d test2(5, 5, 5);
	test1(1, 1, 1) = 10.;
	test2(1, 1, 1) = 5.0;

	cout << "test2(1,1,1) should equal " << 5.0 << endl;
	cout << "It actually equals: " << test2(1, 1, 1) << endl;

	cout << "Now testing the overloading functions:" << endl;

	array3d temp = test1 + test2;
	
	cout << test1(1,1,1) << " + " << test2(1,1,1) << " should equal 15 at (1,1,1): " << (test1 + test2)(1,1,1) << endl;
	cout << "test1 - test2 should equal 5 at (1,1,1): " << (test1 - test2)(1, 1, 1) << endl;
	cout << test1(1, 1, 1) << " * " << test2(1, 1, 1) << " should equal 50: " << (test1*test2)(1, 1, 1) << endl;
	cout << test1(1, 1, 1) << " / " << test2(1, 1, 1) << " should equql 2: " << (test1 / test2)(1, 1, 1) << endl;
	
	cout << "Testing the floating point arithmetic:" << endl;
	cout << test1(1,1,1) << " + 5 should equal 15: " << (test1 + 5)(1, 1, 1) << endl;
	cout << test1(1, 1, 1) << " - 5 should equal 5: " << (test1 - 5)(1, 1, 1) << endl;
	cout << test1(1, 1, 1) << " * 5 should equal 50: " << (test1 * 5)(1, 1, 1) << endl;
	cout << test1(1, 1, 1) << " / 5 should equal 2: " << (test1 / 5)(1, 1, 1) << endl;

	cout << "100 + " << test1(1, 1, 1) << " should equal 110: " << (100 + test1)(1, 1, 1) << endl;
	cout << "100 - " << test1(1, 1, 1) << " should equal 90: " << (100 - test1)(1, 1, 1) << endl;
	cout << "100 * " << test1(1, 1, 1) << " should equal 1000: " << (100 * test1)(1, 1, 1) << endl;
	cout << "100 / " << test1(1, 1, 1) << " should equal 10: " << (100 / test1)(1, 1, 1) << endl;

	cout << "Testing the copy functionality of MyVector:" << endl;

	MyVector test3;
	test3 = test;

	cout << "test.x(1,1,1) should be = 10: " << test.x(1, 1, 1) << endl;

	cout << "Testing MyVector overloads:" << endl;
	cout << test.x(1, 1, 1) << " + " << test.x(1, 1, 1) << " = " << (test + test).x(1, 1, 1) << endl;
	cout << test.x(1, 1, 1) << " - " << test.x(1, 1, 1) << " = " << (test - test).x(1, 1, 1) << endl;
	cout << test.x(1, 1, 1) << " * " << test.x(1, 1, 1) << " = " << (test * test).x(1, 1, 1) << endl;
	cout << test.x(1, 1, 1) << " / " << test.x(1, 1, 1) << " = " << (test / test).x(1, 1, 1) << endl;

	cout << endl;

	cout << test.x(1, 1, 1) << " + " << test1(1, 1, 1) << " = " << (test + test1).x(1, 1, 1) << endl;
	cout << test.x(1, 1, 1) << " - " << test1(1, 1, 1) << " = " << (test - test1).x(1, 1, 1) << endl;
	cout << test.x(1, 1, 1) << " * " << test1(1, 1, 1) << " = " << (test * test1).x(1, 1, 1) << endl;
	cout << test.x(1, 1, 1) << " / " << test1(1, 1, 1) << " = " << (test / test1).x(1, 1, 1) << endl;

	cout << endl;

	cout << test.x(1, 1, 1) << " + " << 10 << " = " << (test + 10).x(1, 1, 1) << endl;
	cout << test.x(1, 1, 1) << " - " << 10 << " = " << (test - 10).x(1, 1, 1) << endl;
	cout << test.x(1, 1, 1) << " * " << 10 << " = " << (test * 10).x(1, 1, 1) << endl;
	cout << test.x(1, 1, 1) << " / " << 10 << " = " << (test / 10).x(1, 1, 1) << endl;

	return 0;
}

