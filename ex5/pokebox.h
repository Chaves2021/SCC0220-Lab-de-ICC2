#ifndef _POKEBOX_H
#define _POKEBOX_H

#include "Pokemon.h"
#include "Util.h"

#define BOXLINES 3
#define BOXCOLLS 3
#define BOXSIZE BOXLINES*BOXCOLLS

#define SUCCESS		 0;
#define INVALID_LIST 	-1;

typedef enum
{
    SUCCESS=0,
    NOONETHERE=1,
    OCCUPPIED=2
} boxError_t;


typedef pokemon_t* pokebox_t[BOXSIZE];

struct double_list_elem
{
	pokebox_t box;
	int pokemon_count;
	struct double_list *prev;
	struct double_list *next;
};
typedef struct double_list_elem DOUBLE_LIST_ELEM;

struct double_list_header
{
	DOUBLE_LIST_ELEM *first;
	DOUBLE_LIST_ELEM *last;
	int actual_box
	int box_count;
};
typedef struct double_list_header DOUBLE_LIST_HEADER;

DOUBLE_LIST_HEADER *box_create();
int movePkmn(DOUBLE_LIST HEADER *header, coord_t curPos, coord_t newPos);
int removePkmn(DOUBLE_LIST HEADER *header, coord_t pos);
int checkIfOccupied(DOUBLE_LIST HEADER *header, coord_t pos);
void printBox(pokebox_t box);

int box_move(DOUBLE_LIST_HEADER *header, int move);
int list_elem_create(DOUBLE_LIST_HEADER *header);
int list_elem_remove(DOUBLE_LIST_HEADER *header);

#endif //_POKEMON_H
