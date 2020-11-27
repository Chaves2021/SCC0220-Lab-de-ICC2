#include "PokeBox.h"

int list_elem_create(DOUBLE_LIST_HEADER *header)
{
	if(!header) return INVALID_LIST;
	int counter = 0;
	DOUBLE_LIST_ELEM **e;
	e = &(header->first);

	DOUBLE_LIST_ELEM *new = (DOUBLE_LIST_ELEM *) calloc(1, sizeof(DOUBLE_LIST_ELEM));
	for(i = 0; i < BOXSIZE; i++) new->box[i] = NULL;

	while(counter++ < header->box_count && (e = &(*e)->next));
	*e = new;
	new->prev = header->last;
	header->last = new;
	header->box_count++;

	return SUCCESS;
}

DOUBLE_LIST_HEADER *box_create()
{
	DOUBLE_LIST_HEADER *header = (DOUBLE_LIST_HEADER *) calloc(1, sizeof(DOUBLE_LIST_HEADER));
	_list_elem_create(header);
	_list_elem_create(header);
	_list_elem_create(header);
	
	return header;
	
}

int remove(DOUBLE_LIST_HEADER *header)
{
	if(!header) return INVALID_LIST;
	int counter = 0;
	DOUBLE_LIST_ELEM *e = header->first;

	while(counter++ < header->actual_box) e = e->next;

	if(e->prev)
		e->prev->next = e->next;
	else
		header->first = e->next;
	if(e->next)
		e->next->prev = e->prev;
	else
		header->last = e->prev;
	free(e);
	header->box_count--;

	return SUCCESS;
}

int move_box(DOUBLE_LIST_HEADER *header, int move)
{
	if(move == -1) 
	{
		if(header->actual_box - 1 < 0)
			header->actual_box = header->box_count - 1;
		else
			header->actual_box--;
	}
	else 
	{
		if(header->actual_box + 1 >= header->box_count)
			header->actual_box = 0;
		else
			header->actual_box++;
	}
	return SUCCESS;
}

int pokemon_add(DOUBLE_LIST_HEADER *header, int pos)
{
}

int movePkmn(DOUBLE_LIST_HEADER *header, coord_t curPos, coord_t newPos)
{
    return NOONETHERE;
}
int removePkmn(DOUBLE_LIST_HEADER *header, coord_t pos)
{
    return NOONETHERE;
}
int checkIfOccupied(DOUBLE_LIST_HEADER *header, coord_t pos)
{
    return NOONETHERE;
}

void printBox(pokebox_t box)
{
    pokemon_t **boxLinePokemon;
    boxLinePokemon = (pokemon_t**) malloc(sizeof(pokemon_t*)*BOXCOLLS);

    for (int i = 0; i < BOXLINES; i++)
    {
        for(int j = 0; j < BOXCOLLS; ++j)
            boxLinePokemon[j] = box[BOXCOLLS*i+j];
        printBoxLine(boxLinePokemon, BOXCOLLS);
        printf("\n");
    }
    free(boxLinePokemon);
}

