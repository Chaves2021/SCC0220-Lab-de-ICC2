#ifndef _SEARCHES_
#define _SEARCHES_

//Struct to store the element to find related with the search type
struct search_elem
{
	enum _option
	{
		SEQUENCIAL,
		BIN_ITERATIVE,
		BIN_RECURSIVE
	}option;
	int elem;
};

typedef struct search_elem SEARCH_ELEM;

SEARCH_ELEM **read_input(int array_size, int n_searches, int *array);
int sequencial_search(int *array, int array_size, int elem);
int bin_iterative_search(int *array, int left, int right, int elem);
int bin_recursive_search(int *array, int left, int right, int elem);
int search_elem_delete(SEARCH_ELEM ***search_elem, int n_searches);

#endif
