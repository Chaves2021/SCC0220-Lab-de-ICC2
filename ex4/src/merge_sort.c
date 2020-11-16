#include <stdio.h>
#include <stdlib.h>
#include <defines.h>
#include <string.h>
#include <merge_sort.h>

void merge(char **array, int left, int middle, int right)
{
	int i, j, k;
	int size0 = middle - left + 1;
	int size1 = right - middle;
	
	char **array_left = (char **) malloc(size0 * sizeof(char *));
	char **array_right = (char **) malloc(size1 * sizeof(char *));

	for(i = 0; i < size0; i++) 
	{
		array_left[i] = (char *) calloc(100, sizeof(char));
		strcpy(array_left[i], array[left + i]);
	}
	for(i = 0; i < size1; i++) 
	{
		array_right[i] = (char *) calloc(100, sizeof(char));
		strcpy(array_right[i], array[middle + i + 1]);
	}

	i = j = 0;
	k = left;

	while(i < size0 && j < size1)
	{
		if(strcasecmp(array_left[i], array_right[j]) > 0)
		{
			strcpy(array[k], array_left[i]);
			i++;
		}
		else
		{
			strcpy(array[k], array_right[j]);
			j++;
		}
		k++;
	}

	while(j < size1)
	{
		strcpy(array[k], array_right[j]);
		j++;
		k++;
	}
	while(i < size0)
	{
		strcpy(array[k], array_left[i]);
		i++;
		k++;
	}
}

void merge_sort(char **array, int left, int right)
{
	if(left < right)
	{
		int middle = left + ((right - left) / 2);

		merge_sort(array, left, middle); 
		merge_sort(array, middle + 1, right); 
		merge(array, left, middle, right);
	}
}
