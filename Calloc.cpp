#include <stdio.h>
#include <stdlib.h>

double **x;
int k = 100

x = (double**)calloc(k, sizeof(double*));// calloc the first dimension
for (int i = 0; i < k; i++)
{
	x[i] = (double*)calloc(k, sizeof(double)); // calloc second dimension for each first dimension
}



