#pragma once
#include "stdafx.h"
#include "Header.h"
#include "MyVector.h"

MyVector::MyVector()
{
	m_nX = 0;
	m_nX = 0;
	m_nZ = 0;
}

MyVector::MyVector(int nX, int nY, int nZ)
{
	//Define the shape of the array, [nx, ny, nz]
	m_nX = nX;
	m_nX = nY;
	m_nZ = nZ;

	//Allocate the array according to the boost multi_array
	array_type m_fX(boost::extents[nX][nY][nZ]);
	array_type m_fY(boost::extents[nX][nY][nZ]);
	array_type m_fZ(boost::extents[nX][nY][nZ]);

	//initialize to zero
	for (index ii = 0; ii != nX; ++ii)
		for (index jj = 0; jj != nY; ++jj)
			for (index kk = 0; kk != nZ; ++kk)
			{
				m_fX[ii][jj][kk] = 0.f;
				m_fY[ii][jj][kk] = 0.f;
				m_fZ[ii][jj][kk] = 0.f;
			}
}


MyVector::~MyVector()
{
}