#include "pokebox.h"

int list_elem_create(DOUBLE_LIST_HEADER *header)
{
	if(!header) return INVALID_LIST;
	int i;
	int counter = 0;
	DOUBLE_LIST_ELEM **e;
	e = &(header->first);

	DOUBLE_LIST_ELEM *new = (DOUBLE_LIST_ELEM *) calloc(1, sizeof(DOUBLE_LIST_ELEM));
	for(i = 0; i < BOXSIZE; i++) new->box[i] = NULL;

	while(counter++ < header->box_count && (e = &(*e)->next));
	*e = new;
	new->prev = header->last;
	header->last = new;

	header->last->next = header->first;
	header->first->prev = header->last;
	header->box_count++;

	return SUCCESS;
}

DOUBLE_LIST_HEADER *header_create()
{
	DOUBLE_LIST_HEADER *header = (DOUBLE_LIST_HEADER *) calloc(1, sizeof(DOUBLE_LIST_HEADER));
	list_elem_create(header);
	list_elem_create(header);
	list_elem_create(header);
	header->box_count = 3;
	
	return header;
	
}

int list_elem_remove(DOUBLE_LIST_HEADER *header)
{
	if(!header) return INVALID_LIST;
	int counter = 0;
	DOUBLE_LIST_ELEM *box_cur = header->first;

	//Find the actual box
	while(counter++ < header->actual_box) box_cur = box_cur->next;

	//If I'm removing the first box
	if(box_cur == header->first)
		header->first = box_cur->next;
	//Else if I'm removing the last box
	else if(box_cur == header->last)
	{
		header->last = box_cur->prev;
		move_box(header, -1);
	}
	//The previous box (based on cur_box) next pointer points to the 2nd box in front of it
	box_cur->prev->next = box_cur->next;
	//The next box (based on cur_box) previous pointer points to the 2nd box behind it
	box_cur->next->prev = box_cur->prev;


	free(box_cur);
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

int pokemon_add(DOUBLE_LIST_HEADER *header, pokemon_t **pkdex, int dex, int pos)
{
	int i;
	int counter = 0;
	int isInserted = FALSE;
	DOUBLE_LIST_ELEM *box_cur = header->first;
	//Find the actual box
	while(counter < header->actual_box) 
	{
		box_cur = box_cur->next;
		counter++;
	}
	//While still remain boxes and the pokemon is not inserted
	while(counter++ < header->box_count && !isInserted)
	{
		//Go through all box positions
		for(i = pos; i < BOXSIZE && !isInserted; i++)
		{
			//If this box position is empty, insert pokemon there
			if(box_cur->box[i] == NULL) 
			{
				box_cur->box[i] = pkdex[dex];
				isInserted = TRUE;
				box_cur->box_index = i;
				box_cur->pokemon_count++;
			}
		}
		//If not inserted, go to the next box and start checking from the beginning
		if(!isInserted)
		{
			box_cur = box_cur->next;
			move_box(header, 1);
			pos = 0;
		}
	}
	//If all boxes are occupied, create a new one at the end
	if(!isInserted)
	{
		list_elem_create(header);
		header->last->box[0] = pkdex[dex];
		header->actual_box = header->box_count - 1;
		header->last->pokemon_count++;
	}
	return SUCCESS;
}

int pokemon_remove(DOUBLE_LIST_HEADER *header, int pos)
{
	int counter = 0;
	DOUBLE_LIST_ELEM *box_cur = header->first;
	//Find the actual box
	while(counter++ < header->actual_box) box_cur = box_cur->next;

	box_cur->box[pos] = NULL;
	box_cur->pokemon_count++;

	return SUCCESS;
}

void _printBox(pokebox_t box)
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

void printBox(DOUBLE_LIST_HEADER *header)
{
	int counter = 0;
	DOUBLE_LIST_ELEM *box_cur = header->first;
	//Find the actual box
	while(counter++ < header->actual_box) box_cur = box_cur->next;

	_printBox(box_cur->box);
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


