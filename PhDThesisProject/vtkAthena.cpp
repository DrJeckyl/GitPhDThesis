#pragma once
#include "stdafx.h"
#include "Header.h"
#include "vtkAthena.h"
#include "vtkStructuredPoints.h"
#include "vtkCellData.h"
#include "vtkDataArray.h"

//Create the constructor
vtkAthena::vtkAthena(char *chFileName) :
	m_chFname(chFileName)
{
	reader = vtkStructuredPointsReader::New();
	reader->SetFileName(chFileName);
	reader->ReadAllColorScalarsOn();
	reader->ReadAllVectorsOn();
	reader->Update();
	m_nX = reader->GetOutput()->GetDimensions()[0] - 1;
	m_nY = reader->GetOutput()->GetDimensions()[1] - 1;
	m_nZ = reader->GetOutput()->GetDimensions()[2] - 1;
}


vtkAthena::~vtkAthena()
{
}


// Get density data from the vtk file and put it in a array3d object
array1d vtkAthena::GetRho()
{
	//allocate the 3d array to hold the density
	array1d rho(m_nX, m_nY, m_nZ);

	//Index as 1D array, since that's how vtk stores the data
	for (int ii = 0; ii < (m_nX*m_nY*m_nZ); ii++)
	{
		rho[ii] = reader->GetOutput()->GetCellData()->GetArray("density")->GetComponent(0, ii);
	}

	return rho;
}


// Get the cell_centered_B from the vtk file and store in the MyVector object
MyVector vtkAthena::GetB()
{
	//allocate the 3d array to hold the density
	MyVector B(m_nX, m_nY, m_nZ);

	//Index as 1D array, since that's how vtk stores the data
	for (int ii = 0; ii < (m_nX*m_nY*m_nZ); ii++)
	{
		//GetComponent gets the ith tuple and the jth component
		//So, GetComponent(1, 2) is the z component at location ii=1
		B.x()[ii] = reader->GetOutput()->GetCellData()->GetArray("cell_centered_B")->GetComponent(ii, 0);
		B.y()[ii] = reader->GetOutput()->GetCellData()->GetArray("cell_centered_B")->GetComponent(ii, 1);
		B.z()[ii] = reader->GetOutput()->GetCellData()->GetArray("cell_centered_B")->GetComponent(ii, 2);
	}

	return B;
}


// Get the velocity data from the vtk file and store in the MyVector object
MyVector vtkAthena::GetU()
{
	//allocate the 3d array to hold the density
	MyVector U(m_nX, m_nY, m_nZ);

	//Index as 1D array, since that's how vtk stores the data
	for (int ii = 0; ii < (m_nX*m_nY*m_nZ); ii++)
	{
		//GetComponent gets the ith tuple and the jth component
		//So, GetComponent(1, 2) is the z component at location ii=1
		U.x()[ii] = reader->GetOutput()->GetCellData()->GetArray("cell_centered_B")->GetComponent(ii, 0);
		U.y()[ii] = reader->GetOutput()->GetCellData()->GetArray("cell_centered_B")->GetComponent(ii, 0);
		U.z()[ii] = reader->GetOutput()->GetCellData()->GetArray("cell_centered_B")->GetComponent(ii, 0);
	}

	return U;
}
