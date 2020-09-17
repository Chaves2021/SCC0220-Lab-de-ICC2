#include <stdio.h>
#include <stdlib.h>
#include <array.h>
#include <defines.h>

int print_array(int *array, int array_size)
{
	int i;
	for(i = 0; i < array_size; i++) printf("%d ", array[i]);
	printf("\n");
	return SUCCESS;
}

int *reverse_array(int *array, int array_size)
{
	int aux;
	int i;
	for(i = 0; i < array_size / 2; i++)
	{
		aux = array[i];
		array[i] = array[array_size - i - 1];
		array[array_size - i - 1] = aux;
	}
	return array;
}

int *bubble_sort(int *array, int array_size)
{
	int i, j;
	int aux;
	for(i = array_size - 1; i > 0; i--)
	{
		for(j = 0; j < i; j++)
		{
			if(array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
			}
		}
	}
	return array;
}

