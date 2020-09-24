#include <stdio.h>
#include <stdlib.h>
#include <defines.h>
#include <searches.h>

int main(void)
{
	int array_size, n_searches;
	SEARCH_ELEM **search_elem;
	int *array;

	scanf("%d %d", &array_size, &n_searches);
	array = (int *) malloc(array_size * sizeof(int));
	search_elem = read_input(array_size, n_searches, array);


	free(array);
	return SUCCESS;
}
