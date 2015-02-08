// PhDThesisProject.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Header.h"
#include <string>
#include <iostream>
#include "MyVector.h"
#include "array3d.h"
#include <tuple>

//#pragma comment(lib, "vtkCommonCore-6.1.lib")
//#pragma comment(lib, "vtkIOLegacy-6.1.lib")
//#pragma comment(lib, "vtkIOCore-6.1.lib")
//#pragma comment(lib, "vtkCommonExecutionModel-6.1.lib")

#include <vtkStructuredPointsReader.h>
#include <vtkStructuredPoints.h>
#include <vtkDataArray.h>
#include <vtkCellData.h>

#include "vtkAthena.h"

#include <iostream>
#include <fstream>
#include <stdio.h>

int main()
{
	using namespace std;

	//string fname = "D:\\Downloads\\strat128z4_HF\\Strat.1230.vtk";

	char *fname = "D:\\Downloads\\strat128z4_HF\\Strat.1230.vtk";
	char *f2 = "D:\\Downloads\\strat128z4_HF\\outfile.dat";

	array3d rho;
	MyVector B;
	MyVector U;

	vtkAthena ATH(fname);

	rho = ATH.GetRho();
	//B = ATH.GetB();
	//U = ATH.GetU();
	
	//double fnum[] = {1, 2, 3, 4, 5, 6};
	ofstream out(f2, ios::out | ios::binary);
	if (!out) {
		cout << "Cannot open file.";
		return 1;
	}
	for (int ii = 0; ii < (rho.size()); ii++)
	{
		out << rho[ii];
	}
	out.close();
	return 0;
}

