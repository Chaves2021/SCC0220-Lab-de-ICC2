#include <stdio.h>
#include <stdlib.h>
#include <defines.h>
#include <string.h>
#include <insertion_sort.h>

int insertion_sort(char **array, int array_size)
{
	int i, j;
	char *key = (char *) calloc(100, sizeof(char));
	for(i = 1; i < array_size; i++)
	{
		strcpy(key, array[i]);
		j = i - 1;
		//Please don't overflow me ;-;
		while(j >= 0 && strcasecmp(array[j], key) < 0)
		{
			strcpy(array[j + 1], array[j]);
			j--;
		}
		strcpy(array[j + 1], key);
	}
	return SUCCESS;
}
