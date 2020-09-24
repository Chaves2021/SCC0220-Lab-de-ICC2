#include <stdio.h>
#include <stdlib.h>
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
