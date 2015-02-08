#pragma once
#include <tuple>

/*
This class is designed to make rank 3 allocatable arrays.
*/
class array3d
{
private:
	//Size of each dimension
	int m_nX;
	int m_nY;
	int m_nZ;

	//Pointer to the array allocation
	float *m_pfData;

public:
	//Default array constructor
	array3d();

	//Specific constructor
	array3d(int, int, int);

	//Copy constructor
	array3d(const array3d &cSource);

	//Deconstructor
	~array3d();

	//Create an erase function as well which zeros the array size, data and pointer.
	void Erase();

	//Access function
	int size(){ return m_nX*m_nY*m_nZ; }

	//Return the shape as a 3-tuple
	std::tuple<int,int,int> Shape()
	{
		std::tuple<int, int, int> shp (m_nX, m_nY, m_nZ);
		return shp;
	}

	//Overloaded () operator
	float &operator()(const int, const int, const int);

	//Overload the [] as well
	float &operator[](const int ii);

	//Overload the assignment operator
	array3d& operator=(const array3d &cSource);

	//Overload the arithmetic operators
	friend array3d operator+(array3d &cLeft, array3d &cRight);
	friend array3d operator-(array3d &cLeft, array3d &cRight);
	friend array3d operator*(array3d &cLeft, array3d &cRight);
	friend array3d operator/(array3d &cLeft, array3d &cRight);

	//Overload the operators to accept +,-,*,/ by constants
	//Should do elementwise arithmetic
	friend array3d operator+(float left, array3d &cRight);
	friend array3d operator-(float left, array3d &cRight);
	friend array3d operator*(float left, array3d &cRight);
	friend array3d operator/(float left, array3d &cRight);

	//Do the same for operating on the right
	friend array3d operator+(array3d &cLeft, float right);
	friend array3d operator-(array3d &cLeft, float right);
	friend array3d operator*(array3d &cLeft, float right);
	friend array3d operator/(array3d &cLeft, float right);

};

