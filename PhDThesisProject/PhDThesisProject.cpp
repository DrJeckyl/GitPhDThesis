// PhDThesisProject.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Header.h"
#include <string>
#include <iostream>
#include <tuple>
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

	//MyVector B;
	//MyVector U;

	//vtkAthena ATH(fname);

	//rho = ATH.GetRho();
	//B = ATH.GetB();
	//U = ATH.GetU();

	//array1d test_avg = rho.avg();

	array1d rho(5, 5, 5);
	rho(1, 1, 1) = 10.;
	cout << rho(1,1,1) << endl;

	cout << (rho + 10)(1,1,1) << endl;

	cout << (rho - 10)(1, 1, 1) << endl;

	cout << (rho * 10)(1, 1, 1) << endl;

	cout << (rho / 10)(1, 1, 1) << endl;

	//double fnum[] = {1, 2, 3, 4, 5, 6};
	//ofstream out(f2, ios::out | ios::binary);
	//if (!out) {
	//	cout << "Cannot open file.";
	//	return 1;
	//}
	//for (int ii = 0; ii < (rho.size()); ii++)
	//{
	//	out << rho[ii];
	//}
	//out.close();
	return 0;
}

