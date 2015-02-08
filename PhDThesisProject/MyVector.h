#pragma once
#include "stdafx.h"
#include "Header.h"
#include <tuple>

//This class will be a container for the 3D arrays created by array3d
class MyVector
{
private:
	//Array dimensions
	int m_nX;
	int m_nY;
	int m_nZ;

	//Forward declare the arrays?
	array1d m_fX;
	array1d m_fY;
	array1d m_fZ;
public:
	//Default Constuctor
	MyVector();
	//Forward declare the constuctor
	MyVector(int, int, int);

	//Declare the copy constructor
	//MyVector(const MyVector &cSource);

	//assignment operator overload
	//MyVector &operator=(const MyVector &cSource);

	//Access function
	//Return single point
	float &x(const int, const int, const int);
	float &y(const int, const int, const int);
	float &z(const int, const int, const int);
	//Return an array3d object
	array1d &x(){ return m_fX; };
	array1d &y(){ return m_fY; };
	array1d &z(){ return m_fZ; };

	//Return the shape as a 3-tuple
	std::tuple<int, int, int> Shape()
	{
		std::tuple<int, int, int> shp(m_nX, m_nY, m_nZ);
		return shp;
	}

	//Overload ALL THE OPERATORS

	//First define how to +,-,*,/ Vectors (elementwise)
	friend MyVector operator+(MyVector &cLeft, MyVector &cRight);
	friend MyVector operator-(MyVector &cLeft, MyVector &cRight);
	friend MyVector operator*(MyVector &cLeft, MyVector &cRight);
	friend MyVector operator/(MyVector &cLeft, MyVector &cRight);

	//Next, define +,-,*,/ to array3d objects to MyVector
	friend MyVector operator+(MyVector &cLeft, array1d &cRight);
	friend MyVector operator-(MyVector &cLeft, array1d &cRight);
	friend MyVector operator*(MyVector &cLeft, array1d &cRight);
	friend MyVector operator/(MyVector &cLeft, array1d &cRight);

	friend MyVector operator+(array1d &cLeft, MyVector &cRight);
	friend MyVector operator-(array1d &cLeft, MyVector &cRight);
	friend MyVector operator*(array1d &cLeft, MyVector &cRight);
	friend MyVector operator/(array1d &cLeft, MyVector &cRight);

	//Now define +,-,*,/ for floats and MyVector
	friend MyVector operator+(MyVector &cLeft, float fRight);
	friend MyVector operator-(MyVector &cLeft, float fRight);
	friend MyVector operator*(MyVector &cLeft, float fRight);
	friend MyVector operator/(MyVector &cLeft, float fRight);

	friend MyVector operator+(float fLeft, MyVector &cRight);
	friend MyVector operator-(float fLeft, MyVector &cRight);
	friend MyVector operator*(float fLeft, MyVector &cRight);
	friend MyVector operator/(float fLeft, MyVector &cRight);

	//Define the dot and cross products as friends here
	
	//Dot product
	//Takes 2 MyVectors and returns an array3d
	friend array1d dot(MyVector &cLeft, MyVector &cRight);

	//Cross product
	//Takes 2 MyVectors and returns a MyVector
	friend MyVector cross(MyVector &cLeft, MyVector &cRight);
};

