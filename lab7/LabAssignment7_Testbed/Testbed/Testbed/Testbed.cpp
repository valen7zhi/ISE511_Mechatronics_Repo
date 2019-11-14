#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *infile;
FILE *outfile;

#define PI 3.14159265
#define h 9.75

void ConverCoordinatesToAngles(double x, double y, double &alpha, double &beta)
{
	//add your code here
	// double h = 9.75;
	int A = sqrt(h * h + y * y);
	alpha = (180 / PI) * atan(y / h);
	beta = (180 / PI) * atan(x / A);
}

void DrawLine(double x1, double y1, double x2, double y2)
{
	double alpha, beta;
	double x, y;
	int LASERStatus; //1:on, 0:off
	x = y = 0;
	LASERStatus = 1;

	//add you code here:
	double indexX = pow(x2 - x1, 2);
	double indexY = pow(y2 - y1, 2);

	int n = (int)sqrt(indexX + indexY) / 0.01; //res calc

	//for each point, convert the coordinates to angles and save the angles
	for (int i = x1; i < x2; i + n)
	{
		ConverCoordinatesToAngles(x, y, alpha, beta);
		fprintf(outfile, "%lf, %lf, %d\n", alpha, beta, LASERStatus);
	}
}

void DrawCircle(double xc, double yc, double radius)
{
	double alpha, beta;
	double x, y;
	int LASERStatus; //1:on, 0:off
	x = y = 0;
	LASERStatus = 1;

	//add you code here:

	//for each point, convert the coordinates to angles and save the angles
	ConverCoordinatesToAngles(x, y, alpha, beta);
	fprintf(outfile, "%lf, %lf, %d\n", alpha, beta, LASERStatus);
}

int _tmain(int argc, _TCHAR *argv[])
{
	int i;
	int shapenum;
	int shapetype;
	double x1, y1, x2, y2; //1 for line 2 for circle
	double xc, yc, radius;

	infile = fopen("data.txt", "r");
	outfile = fopen("ISE511L.txt", "w");

	if (infile == NULL)
	{
		printf("data file does not exist!\n");
		return 0;
	}
	else
		fscanf(infile, "%d,", &shapenum); // number of inputs
	for (i = 0; i < shapenum; i++)
	{
		fscanf(infile, "%d,", &shapetype);
		switch (shapetype)
		{
		case 0: //line
		{
			fscanf(infile, "%lf,%lf,%lf,%lf", &x1, &y1, &x2, &y2);
			DrawLine(x1, y1, x2, y2);
		}
		break;
		case 1: //circle
		{
			fscanf(infile, "%lf,%lf,%lf", &xc, &yc, &radius);
			DrawCircle(xc, yc, radius);
		}
		break;
		default:
		{
			printf("invalid file!\n");
			return 0;
		}
		break;
		}
	}

	fclose(infile);
	fclose(outfile);
	return 0;
}
