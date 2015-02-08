#pragma once
#include "stdafx.h"
#include "Header.h"
#include <tuple>

//Default Constuctor
MyVector::MyVector(){};

//Use an initialization list to set the 3D arrays
MyVector::MyVector(int nx, int ny, int nz) :
m_nX(nx), m_nY(ny), m_nZ(nz),
m_fX(nx, ny, nz),
m_fY(nx, ny, nz),
m_fZ(nx, ny, nz)
{};

//Copy Constructor
/*MyVector::MyVector(const MyVector &cSource)
{

}*/

float &MyVector::x(const int ii, const int jj, const int kk)
{
	return m_fX(ii, jj, kk);
}

float &MyVector::y(const int ii, const int jj, const int kk)
{
	return m_fY(ii, jj, kk);
}

float &MyVector::z(const int ii, const int jj, const int kk)
{
	return m_fZ(ii, jj, kk);
}

/**********************************************************************************/
/*                  OPERATOR OVERLOADING                                          */

//MyVector with MyVector
//Note, the divide by zero will be caught by the / operator for array3d
//Bound checking will be done by array3d as well
MyVector operator+(MyVector &cLeft, MyVector &cRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() + cRight.x();
	result.y() = cLeft.y() + cRight.y();
	result.z() = cLeft.z() + cRight.z();
	return result;
}

MyVector operator-(MyVector &cLeft, MyVector &cRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() - cRight.x();
	result.y() = cLeft.y() - cRight.y();
	result.z() = cLeft.z() - cRight.z();
	return result;
}

MyVector operator*(MyVector &cLeft, MyVector &cRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() * cRight.x();
	result.y() = cLeft.y() * cRight.y();
	result.z() = cLeft.z() * cRight.z();
	return result;
}

MyVector operator/(MyVector &cLeft, MyVector &cRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() / cRight.x();
	result.y() = cLeft.y() / cRight.y();
	result.z() = cLeft.z() / cRight.z();
	return result;
}

//MyVector Left with array3d Right
MyVector operator+(MyVector &cLeft, array1d &cRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() + cRight;
	result.y() = cLeft.y() + cRight;
	result.z() = cLeft.z() + cRight;
	return result;
}

MyVector operator-(MyVector &cLeft, array1d &cRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() - cRight;
	result.y() = cLeft.y() - cRight;
	result.z() = cLeft.z() - cRight;
	return result;
}

MyVector operator*(MyVector &cLeft, array1d &cRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() * cRight;
	result.y() = cLeft.y() * cRight;
	result.z() = cLeft.z() * cRight;
	return result;
}

MyVector operator/(MyVector &cLeft, array1d &cRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() / cRight;
	result.y() = cLeft.y() / cRight;
	result.z() = cLeft.z() / cRight;
	return result;
}

//array3d Left with MyVector Right
MyVector operator+(array1d &cLeft, MyVector &cRight)
{
	MyVector result = cRight;
	result.x() = cLeft + cRight.x();
	result.y() = cLeft + cRight.y();
	result.z() = cLeft + cRight.z();
	return result;
}
MyVector operator-(array1d &cLeft, MyVector &cRight)
{
	MyVector result = cRight;
	result.x() = cLeft - cRight.x();
	result.y() = cLeft - cRight.y();
	result.z() = cLeft - cRight.z();
	return result;
}
MyVector operator*(array1d &cLeft, MyVector &cRight)
{
	MyVector result = cRight;
	result.x() = cLeft * cRight.x();
	result.y() = cLeft * cRight.y();
	result.z() = cLeft * cRight.z();
	return result;
}
MyVector operator/(array1d &cLeft, MyVector &cRight)
{
	MyVector result = cRight;
	result.x() = cLeft / cRight.x();
	result.y() = cLeft / cRight.y();
	result.z() = cLeft / cRight.z();
	return result;
}

//Myvector Left with float Right

MyVector operator+(MyVector &cLeft, float fRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() + fRight;
	result.y() = cLeft.y() + fRight;
	result.z() = cLeft.z() + fRight;
	return result;
}

MyVector operator-(MyVector &cLeft, float fRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() - fRight;
	result.y() = cLeft.y() - fRight;
	result.z() = cLeft.z() - fRight;
	return result;
}

MyVector operator*(MyVector &cLeft, float fRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() * fRight;
	result.y() = cLeft.y() * fRight;
	result.z() = cLeft.z() * fRight;
	return result;
}

MyVector operator/(MyVector &cLeft, float fRight)
{
	MyVector result = cLeft;
	result.x() = cLeft.x() / fRight;
	result.y() = cLeft.y() / fRight;
	result.z() = cLeft.z() / fRight;
	return result;
}

//float Left with MyVector Right

MyVector operator+(float fLeft, MyVector &cRight)
{
	MyVector result = cRight;
	result.x() = fLeft + cRight.x();
	result.y() = fLeft + cRight.y();
	result.z() = fLeft + cRight.z();
	return result;
}

MyVector operator-(float fLeft, MyVector &cRight)
{
	MyVector result = cRight;
	result.x() = fLeft - cRight.x();
	result.y() = fLeft - cRight.y();
	result.z() = fLeft - cRight.z();
	return result;
}

MyVector operator*(float fLeft, MyVector &cRight)
{
	MyVector result = cRight;
	result.x() = fLeft * cRight.x();
	result.y() = fLeft * cRight.y();
	result.z() = fLeft * cRight.z();
	return result;
}

MyVector operator/(float fLeft, MyVector &cRight)
{
	MyVector result = cRight;
	result.x() = fLeft / cRight.x();
	result.y() = fLeft / cRight.y();
	result.z() = fLeft / cRight.z();
	return result;
}



//Dot and Cross Products

//Dot Product takes 2 MyVectors as input
//Returns the dot product as an array3d

array1d dot(MyVector &cLeft, MyVector &cRight)
{
	//First check the array dimensions are compatible
	assert(cLeft.Shape() == cRight.Shape());
	
	return cLeft.x()*cRight.x() + cLeft.y()*cRight.y() + cLeft.z()*cRight.z();
}


//Cross Product takes 2 MyVectors as input
//Returns a MyVector

//MyVector cross(MyVector &cLeft, MyVector &cRight)
//{
//	//First check the array dimensions are compatible
//	assert(cLeft.Shape() == cRight.Shape());
//
//}