#pragma once
#include "vtkStructuredPointsReader.h"
#include "Header.h"

class vtkAthena
{
private:
	vtkAthena(); //Make private so vtkAthena can't be created without a filename
public:
	vtkAthena(char * chFileName);
	~vtkAthena();
protected:
	int m_nX;
	int m_nY;
	int m_nZ;
	char *m_chFname;
	vtkStructuredPointsReader *reader;

public:
	// Get density data from the vtk file and put it in a array3d object
	array1d GetRho();
	// Get the cell_centered_B from the vtk file and store in the MyVector object
	MyVector GetB();
	// Get the velocity data from the vtk file and store in the MyVector object
	MyVector GetU();
};

