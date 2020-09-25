#include <stdio.h>
#include <stdlib.h>
#include <defines.h>
#include <searches.h>

int main(void)
{
	int array_size, n_searches;
	SEARCH_ELEM **search_elem;
	int *array;
	int i;

	scanf("%d %d", &array_size, &n_searches);
	array = (int *) malloc(array_size * sizeof(int));
	search_elem = read_input(array_size, n_searches, array);

	for(i = 0; i < n_searches; i++)
	{
		switch(search_elem[i]->option)
		{
			case SEQUENCIAL:
				printf("%d\n", sequencial_search(array, array_size, search_elem[i]->elem));
				break;
			case BIN_ITERATIVE:
				printf("%d\n", bin_iterative_search(array, 0, array_size - 1, search_elem[i]->elem));
				break;
			case BIN_RECURSIVE:
				printf("%d\n", bin_recursive_search(array, 0, array_size - 1, search_elem[i]->elem));
				break;
			default:
				printf("I don't know how you reached here :p\n");
		}
	}

	free(array);
	search_elem_delete(&search_elem, n_searches);
	return SUCCESS;
}
