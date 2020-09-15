#include <stdio.h>
#include <stdlib.h>
#include <defines.h>
#include <file_manager.h>

int main(int argc, char **argv)
{
	long int array_size;
	int *array = NULL;
	char *file_name;
	if(argc != 2) 
	{
		printf("Usage: %s <file_name>\n", argv[0]);
		return 1;
	}
	file_name = argv[1];
	array = bin2array(file_name, &array_size);
	if(!array) return ERROR;

	return SUCCESS;
}
