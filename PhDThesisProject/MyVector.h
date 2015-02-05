#pragma once
#include "array3d.h"

//This class will be a container for the 3D arrays created by array3d
class MyVector
{
private:
	//Forward declare the arrays?
	array3d m_fX;
	array3d m_fY;
	array3d m_fZ;
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
	array3d &x(){ return m_fX; };
	array3d &y(){ return m_fY; };
	array3d &z(){ return m_fZ; };

	//Overload ALL THE OPERATORS

	//First define how to +,-,*,/ Vectors (elementwise)
	friend MyVector operator+(MyVector &cLeft, MyVector &cRight);
	friend MyVector operator-(MyVector &cLeft, MyVector &cRight);
	friend MyVector operator*(MyVector &cLeft, MyVector &cRight);
	friend MyVector operator/(MyVector &cLeft, MyVector &cRight);

	//Next, define +,-,*,/ to array3d objects to MyVector
	friend MyVector operator+(MyVector &cLeft, array3d &cRight);
	friend MyVector operator-(MyVector &cLeft, array3d &cRight);
	friend MyVector operator*(MyVector &cLeft, array3d &cRight);
	friend MyVector operator/(MyVector &cLeft, array3d &cRight);

	friend MyVector operator+(array3d &cLeft, MyVector &cRight);
	friend MyVector operator-(array3d &cLeft, MyVector &cRight);
	friend MyVector operator*(array3d &cLeft, MyVector &cRight);
	friend MyVector operator/(array3d &cLeft, MyVector &cRight);

	//Now define +,-,*,/ for floats and MyVector
	friend MyVector operator+(MyVector &cLeft, float fRight);
	friend MyVector operator-(MyVector &cLeft, float fRight);
	friend MyVector operator*(MyVector &cLeft, float fRight);
	friend MyVector operator/(MyVector &cLeft, float fRight);

	friend MyVector operator+(float fLeft, MyVector &cRight);
	friend MyVector operator-(float fLeft, MyVector &cRight);
	friend MyVector operator*(float fLeft, MyVector &cRight);
	friend MyVector operator/(float fLeft, MyVector &cRight);
};

