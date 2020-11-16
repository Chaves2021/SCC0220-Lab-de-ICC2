#include <stdio.h>
#include <stdlib.h>
#include <defines.h>
#include <file_manager.h>
char **read_input(FILE *fp, int *array_size)
{
	char **array = NULL; 
	array = (char **) realloc(array, ((*array_size) + 1) * sizeof(char *));
	array[(*array_size)] = (char *) calloc(100, sizeof(char));
	while(fscanf(fp, " %s", array[(*array_size)++]) != EOF)
	{
		array = (char **) realloc(array, ((*array_size) + 1) * sizeof(char *));
		array[(*array_size)] = (char *) calloc(100, sizeof(char));
	}

	return array;
}

int saveTimeToFile(int array_size, double time, int option)
{
	FILE *fp;
	if(option == BUBBLE_SORT)
		fp = fopen("bubbletime.dat", "a+b");
	else if(option == INSERTION_SORT)
		fp = fopen("insertiontime.dat", "a+b");
	else
		fp = fopen("mergetime.dat", "a+b");

	fprintf(fp, "%d %lf\n", array_size, time);
	fclose(fp);
	return SUCCESS;
}
