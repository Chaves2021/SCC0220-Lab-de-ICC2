#include <stdio.h>
#include <stdlib.h>
#include <defines.h>
#include <string.h>
#include <bubble_sort.h>

int bubble_sort(char **array, int array_size)
{
	int i, j;
	char *aux;
	aux = (char *) calloc(100, sizeof(char));
	for(i = array_size - 1; i >= 1; i--)
	{
		for(j = 0; j < i; j++)
		{
			//Please don't overflow me ;-;
			if(strcasecmp(array[i], array[j]) > 0)
			{
				strcpy(aux, array[i]);
				strcpy(array[i], array[j]);
				strcpy(array[j], aux);
			}
		}
	}
	return SUCCESS;
}
