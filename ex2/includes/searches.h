#ifndef _SEARCHES_
#define _SEARCHES_

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

#endif
