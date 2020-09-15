#include <stdio.h>
#include <stdlib.h>
#include <file_manager.h>
#include <defines.h>

long int get_file_size(char *file_name)
{
	FILE *fpointer = fopen(file_name, "rb");
	if(!fpointer) return ERROR;

	fseek(fpointer, 0, SEEK_END);

	long int file_size = ftell(fpointer);
	fclose(fpointer);
	return file_size;
}

int *bin2array(char *file_name, long int *array_size)
{
	FILE *fpointer = fopen(file_name, "rb");
	if(!fpointer) 
	{
		printf("File not found ;-;\n");
		return NULL;
	}

	*array_size = get_file_size(file_name) / sizeof(int);
	int *array = (int *) malloc((*array_size) * sizeof(int));
	int aux = 0;

	while(!feof(fpointer)) fread(&(array[aux++]), 1, sizeof(int), fpointer);
	
	return array;
}