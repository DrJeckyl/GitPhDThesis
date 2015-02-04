#pragma once
#include "Header.h"
#include "boost/multi_array.hpp"


class MyVector
{
private:
	//Shape of the arrays
	int m_nX;
	int m_nY;
	int m_nZ;

	//This is a list initialization...apparently
	/*MyVector(int nX, int nY, int nZ) :
		m_X(boost::extents[nX][nY][nZ]),
		m_Y(boost::extents[nX][nY][nZ]),
		m_Z(boost::extents[nX][nY][nZ])
	{
	}*/
public:
	MyVector(int, int, int);
	array_type m_X;
	array_type m_Y;
	array_type m_Z;

	//MyVector(){} // Default Constructor

	
	//Access functions
	array_type GetX(){ return m_X; }
	array_type GetY(){ return m_Y; }
	array_type GetZ(){ return m_Z; }

	void SetX(int, int, int, float);

};

