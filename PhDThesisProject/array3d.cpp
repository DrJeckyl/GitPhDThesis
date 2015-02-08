#include "stdafx.h"
#include "array3d.h"
#include <cassert>
#include <tuple>

array3d::array3d() : m_nX(0), m_nY(0), m_nZ(0), m_pfData(0)
{
}

array3d::array3d(int nX, int nY, int nZ)
{
	m_nX = nX;
	m_nY = nY;
	m_nZ = nZ;
	// Make a flattened 1D version of the array.
	// We'll overload the () operator to be a wrapper for the 3D version
	m_pfData = new float[nX*nY*nZ];
}

array3d::~array3d()
{
	delete[] m_pfData;
}

//Define a copy constuctor
array3d::array3d(const array3d &cSource)
{
	//Shallow copy the array dimensions
	m_nX = cSource.m_nX;
	m_nY = cSource.m_nY;
	m_nZ = cSource.m_nZ;
	if (cSource.m_pfData)
	{
		//allocate new memory
		m_pfData = new float[m_nX*m_nY*m_nZ];

		//Copy data into new array
		for (int ii = 0; ii < (m_nX*m_nY*m_nZ); ii++)
			m_pfData[ii] = cSource.m_pfData[ii];
	}
	else
		m_pfData = 0; //Set to null
}

//Assignment overloading
array3d& array3d::operator=(const array3d &cSource)
{
	// Avoid self assignment
	if (this == &cSource){ return *this; } 
	
	//Freeze the memory allocated
	delete[] m_pfData; 

	//Shallow copy the array dimensions
	m_nX = cSource.m_nX;
	m_nY = cSource.m_nY;
	m_nZ = cSource.m_nZ;

	if (cSource.m_pfData)
	{
		//allocate new memory
		m_pfData = new float[m_nX*m_nY*m_nZ];

		//Copy data into new array
		for (int ii = 0; ii < (m_nX*m_nY*m_nZ); ii++)
			m_pfData[ii] = cSource.m_pfData[ii];
	}
	
	return *this;
}

//Overloaded () operator to index the 3D array
float &array3d::operator()(const int ii, const int jj, const int kk)
{
	//Do some bounds checking
	assert(ii < m_nX && ii >= 0);
	assert(jj < m_nY && jj >= 0);
	assert(kk < m_nZ && kk >= 0);

	//Column order
	return m_pfData[kk*m_nX*m_nY + jj*m_nX + ii];

	//Row order
	//return m_pfData[m_nY*m_nZ*ii + m_nZ*jj + kk];
}


//Overloaded [] operator to be able to index as a 1D array
float &array3d::operator[](const int ii)
{
	//Check bounds
	assert(ii < (m_nX*m_nY*m_nZ) && ii >= 0);
	return m_pfData[ii];
}

//Operator overloading functions

//Does element wise +,-,*,/
array3d operator+(array3d &cLeft, array3d &cRight)
{
	//Make sure the arrays are the same shape
	assert(cLeft.Shape() == cRight.Shape());
	array3d result(cLeft.m_nX, cLeft.m_nY, cLeft.m_nZ);

	for (int ii = 0; ii < cLeft.m_nX*cLeft.m_nY*cLeft.m_nZ; ii++)
	{
		result[ii] = cLeft[ii] + cRight[ii];
	}
	return result;
}

array3d operator-(array3d &cLeft, array3d &cRight)
{
	//Make sure the arrays are the same shape
	assert(cLeft.Shape() == cRight.Shape());
	array3d result(cLeft.m_nX, cLeft.m_nY, cLeft.m_nZ);

	for (int ii = 0; ii < cLeft.m_nX*cLeft.m_nY*cLeft.m_nZ; ii++)
	{
		result[ii] = cLeft[ii] - cRight[ii];
	}
	return result;
}

array3d operator*(array3d &cLeft, array3d &cRight)
{
	//Make sure the arrays are the same shape
	assert(cLeft.Shape() == cRight.Shape());
	array3d result(cLeft.m_nX, cLeft.m_nY, cLeft.m_nZ);

	for (int ii = 0; ii < cLeft.m_nX*cLeft.m_nY*cLeft.m_nZ; ii++)
	{
		result[ii] = cLeft[ii] * cRight[ii];
	}
	return result;
}

array3d operator/(array3d &cLeft, array3d &cRight)
{
	//Make sure the arrays are the same shape
	assert(cLeft.Shape() == cRight.Shape());
	array3d result(cLeft.m_nX, cLeft.m_nY, cLeft.m_nZ);

	for (int ii = 0; ii < cLeft.m_nX*cLeft.m_nY*cLeft.m_nZ; ii++)
	{
		//Catch the divide by 0
		assert(cRight[ii] != 0.f);
		result[ii] = cLeft[ii] / cRight[ii];
	}
	return result;
}

//Overloading using constant values
// Want array3d + 3 to add 3 to each element
// Similarily for -,*, and /


/*********************************************/
//array on the right, float left:
array3d operator+(float left, array3d &cRight)
{
	array3d result(cRight.m_nX, cRight.m_nY, cRight.m_nZ);

	for (int ii = 0; ii < cRight.m_nX*cRight.m_nY*cRight.m_nZ; ii++)
	{
		result[ii] = left + cRight[ii];
	}
	return result;
}

array3d operator-(float left, array3d &cRight)
{
	return left + -1.*cRight;
}

array3d operator*(float left, array3d &cRight)
{
	array3d result(cRight.m_nX, cRight.m_nY, cRight.m_nZ);

	for (int ii = 0; ii < cRight.m_nX*cRight.m_nY*cRight.m_nZ; ii++)
	{
		result[ii] = left * cRight[ii];
	}
	return result;
}

array3d operator/(float left, array3d &cRight)
{
	array3d result(cRight.m_nX, cRight.m_nY, cRight.m_nZ);

	for (int ii = 0; ii < cRight.m_nX*cRight.m_nY*cRight.m_nZ; ii++)
	{
		//Catch the divide by zero
		assert(cRight[ii] != 0.f);
		result[ii] = left / cRight[ii];
	}
	return result;
}

/***********************************************/
//array on the left, float right:
array3d operator+(array3d &cLeft, float right)
{
	return right + cLeft;
}

array3d operator*(array3d &cLeft, float right)
{
	return right * cLeft;
}

array3d operator-(array3d &cLeft, float right)
{
	//Make sure the arrays are the same shape
	//assert(left.Shape() == cRight.Shape());
	array3d result(cLeft.m_nX, cLeft.m_nY, cLeft.m_nZ);

	for (int ii = 0; ii < cLeft.m_nX*cLeft.m_nY*cLeft.m_nZ; ii++)
	{
		result[ii] = cLeft[ii] - right;
	}
	return result;
}


array3d operator/(array3d &cLeft, float right)
{
	//Catch the divide by 0
	assert(right != 0);
	array3d result(cLeft.m_nX, cLeft.m_nY, cLeft.m_nZ);

	for (int ii = 0; ii < cLeft.m_nX*cLeft.m_nY*cLeft.m_nZ; ii++)
	{
		result[ii] = cLeft[ii] / right;
	}
	return result;
}