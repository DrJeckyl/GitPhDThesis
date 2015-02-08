#pragma once
class array1d
{
public:
	//Default Constructor
	array1d();
	//Constructor
	array1d(int);
	//Copy constuctor
	array1d(const array1d &cSource);
	//Destructor
	~array1d();

	//Overload the assignment operator
	array1d& operator=(const array1d &cSource);

	//Access Functions
	//Size
	int size(){ return nLength; }
	//Overload the []
	float &operator[](const int ii);

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

protected:
	int nLength;
	float *m_pfData;
};

