#pragma once
//#include "stdafx.h"
#include "Header.h"
#include "MyVector.h"
//#include "boost/multi_array.hpp"

//This is a list initialization...apparently
MyVector::MyVector(int nX, int nY, int nZ) :
m_X(boost::extents[nX][nY][nZ]),
m_Y(boost::extents[nX][nY][nZ]),
m_Z(boost::extents[nX][nY][nZ])
{
}

void MyVector::SetX(int ii, int jj, int kk, float value)
{
	m_X[ii][jj][kk] = value;
}

/*MyVector::MyVector(int nX, int nY, int nZ)
{
	m_nX = nX;
	m_nY = nY;
	m_nZ = nZ;

	//initialize to zero
	for (index ii = 0; ii != nX; ++ii)
		for (index jj = 0; jj != nY; ++jj)
			for (index kk = 0; kk != nZ; ++kk)
			{
				m_X[ii][jj][kk] = 0;
				m_Y[ii][jj][kk] = 0;
				m_Z[ii][jj][kk] = 0;
			}
}*/
