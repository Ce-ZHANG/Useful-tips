#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <sys/time.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

typedef struct
{
	double *a;
	double *b;
	double *c;
	double *d;
}t1_t;

t1_t t1;

int lines(FILE *fp)
{
	int line_num = 0;
	char line;
	while (!feof(fp))
	{
		line = fgetc(fp);
		if (line == '\n') {
			line_num++;
		}
	}
	return line_num;
}

void initialization(FILE* fp, FILE* fp1, int line_num)
{

	t1.a = (double*)calloc(line_num, sizeof(double));
	t1.b = (double*)calloc(line_num, sizeof(double));
	t1.c = (double*)calloc(line_num, sizeof(double));
	t1.d = (double*)calloc(line_num, sizeof(double));
	double one, two, three, four;
	int i = 0;
	while (fscanf(fp, "%lf,%lf,%lf,%lf\n", &one, &two, &three, &four) == 4)// assuming that the file have 4 column 
	{
		t1.a[i] = one;
		t1.b[i] = two;
		t1.c[i] = three;
		t1.d[i] = four;
		i++;
	}

}


int main(int argc, char *argv[]) {

	char* file_name = argv[1];

	FILE* fp = fopen(file_name, "r");
	int line_num = lines(fp);// get the line number of the file
	rewind(fp);
	initialization(fp, fp1, line_num);// store all the values from the file into the struct
}