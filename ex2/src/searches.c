#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <defines.h>
#include <searches.h>

SEARCH_ELEM **read_input(int array_size, int n_searches, int *array)
{
	int i;
	int option;
	SEARCH_ELEM **search_elem;
	search_elem = (SEARCH_ELEM **) malloc(n_searches * sizeof(SEARCH_ELEM *));

	for(i = 0; i < array_size; i++) scanf("%d", &(array[i]));

	for(i = 0; i < n_searches; i++)
	{
		search_elem[i] = (SEARCH_ELEM *) malloc(sizeof(SEARCH_ELEM));
		scanf("%d %d", &option, &(search_elem[i]->elem));
		search_elem[i]->option = option - 1;
	}

	return search_elem;
}

int sequencial_search(int *array, int array_size, int elem)
{
	int i;
	for(i = 0; i < array_size; i++)
	{
		if(array[i] == elem) return i + 1;
	}
	return NOT_FOUND;
}

int bin_iterative_search(int *array, int left, int right, int elem)
{
	int middle;
	while(left <= right)
	{
		//always round up if middle is not an integer
		middle = (int) ceil((double) (left + right) / 2);

		if(array[middle] == elem) return middle + 1;
		else if(array[middle] > elem) right = middle - 1;
		else left = middle + 1;
	}
	return NOT_FOUND;
}

int bin_recursive_search(int *array, int left, int right, int elem)
{
	if(left > right) return NOT_FOUND;
	
	//always round up if middle is not an integer
	int middle = (int) ceil((double) (left + right) / 2);

	if(array[middle] == elem) return middle + 1;
	else if(array[middle] > elem) return bin_recursive_search(array, left, middle - 1, elem);
	else return bin_recursive_search(array, middle + 1, right, elem);
	
}

int search_elem_delete(SEARCH_ELEM ***search_elem, int n_searches)
{
	int i;
	for(i = 0; i < n_searches; i++) free((*search_elem)[i]);
	free(*search_elem);
	return SUCCESS;
}
