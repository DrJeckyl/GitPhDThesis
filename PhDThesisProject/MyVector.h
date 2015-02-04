#pragma once
#include "Header.h"
class MyVector
{
public:
	MyVector();
	MyVector(int,int,int);
	~MyVector();

	//Access functions
	array_type GetX(){ return m_fX; };
	array_type GetY(){ return m_fY; };
	array_type GetZ(){ return m_fZ; };

private:
	int m_nX;
	int m_nY;
	int m_nZ;

	array_type m_fX;
	array_type m_fY;
	array_type m_fZ;

};

