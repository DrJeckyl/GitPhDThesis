#pragma once
#include <tuple>
class array1d
{
public:
	//Default Constructor
	array1d();
	//Constructor
	//1D
	array1d(int);
	//Interpret as 3D
	array1d(int nx, int ny, int nz);
	//Copy constuctor
	array1d(const array1d &cSource);
	//Destructor
	~array1d();

	//Overload the assignment operator
	array1d& operator=(const array1d &cSource);

	//Access Functions
	//Size
	int size(){ return nLength; }

	//Return the shape as a 3-tuple
	std::tuple<int, int, int> Shape()
	{
		std::tuple<int, int, int> shp(m_nX, m_nY, m_nZ);
		return shp;
	}

	//Overload the [] 
	float &operator[](const int ii);

	//Overload () for 1D arrays to view only
	float operator()(const int);

	//Overloaded () operator for 3D arrays
	float &operator()(const int, const int, const int);

	//Overload the arithmetic operators
	friend array1d operator+(array1d &cLeft, array1d &cRight);
	friend array1d operator-(array1d &cLeft, array1d &cRight);
	friend array1d operator*(array1d &cLeft, array1d &cRight);
	friend array1d operator/(array1d &cLeft, array1d &cRight);

	//Overload the operators to accept +,-,*,/ by constants
	//Should do elementwise arithmetic
	friend array1d operator+(float left, array1d &cRight);
	friend array1d operator-(float left, array1d &cRight);
	friend array1d operator*(float left, array1d &cRight);
	friend array1d operator/(float left, array1d &cRight);

	//Do the same for operating on the right
	friend array1d operator+(array1d &cLeft, float right);
	friend array1d operator-(array1d &cLeft, float right);
	friend array1d operator*(array1d &cLeft, float right);
	friend array1d operator/(array1d &cLeft, float right);

	friend array1d avg(array1d &cSource);
protected:
	int nLength;
	int m_nX;
	int m_nY;
	int m_nZ;
	float *m_pfData;
};

