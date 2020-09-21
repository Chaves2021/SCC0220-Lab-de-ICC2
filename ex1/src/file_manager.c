#include <defines.h>
#include <stdio.h>
#include <stdlib.h>
#include <file_manager.h>

long int get_file_size(char *file_name)
{
	FILE *fpointer = fopen(file_name, "rb");
	if(!fpointer) return ERROR;

	fseek(fpointer, 0, SEEK_END);

	long int file_size = ftell(fpointer);
	fclose(fpointer);
	return file_size;
}

//Function to return an array from a .dat file
int *bin2array(char *file_name, int array_size)
{
	FILE *fpointer = fopen(file_name, "rb");
	if(!fpointer) 
	{
		printf("File not found ;-;\n");
		return NULL;
	}

	int *array = (int *) malloc(array_size * sizeof(int));
	int aux = 0;

	while(!feof(fpointer)) fread(&(array[aux++]), 1, sizeof(int), fpointer);
	
	fclose(fpointer);
	return array;
}

int saveTimeToFile(int array_size, double time, PROGRAM program)
{
	FILE *fpointer;

	if(program == REVERSE_ARRAY)
		fpointer = fopen("reversetime.dat", "a+b");
	else
		fpointer = fopen("bubbletime.dat", "a+b");

	if(!fpointer) return ERROR;

	fprintf(fpointer, "%d %lf\n", array_size, time);
	fclose(fpointer);

	return SUCCESS;
}

//All files have the same beginning (./casos/data/numberlist...)
//So, after the 23rd char, the file say how many numbers there is in.
//So, I read it until a . that indicates the end of the number
int get_array_size(char *file_name)
{
	int n_executions;
	int counter = 0;
	char *aux = (char *) calloc(7, sizeof(char));
	aux[0] = file_name[23];
	//while(aux[counter] != '.' && aux[counter] != '\0' && counter++) aux[counter] = file_name[counter + 23];
	while(aux[counter] != '.' && ++counter) aux[counter] = file_name[counter + 23];
	n_executions = atoi(aux);
	return n_executions;
}
