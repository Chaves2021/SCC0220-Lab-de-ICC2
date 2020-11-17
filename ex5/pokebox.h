#ifndef _POKEBOX_H
#define _POKEBOX_H

#include "Pokemon.h"
#include "Util.h"

#define BOXLINES 3
#define BOXCOLLS 3
#define BOXSIZE BOXLINES*BOXCOLLS

typedef enum
{
    SUCCESS=0,
    NOONETHERE=1,
    OCCUPPIED=2
} boxError_t;


typedef pokemon_t* pokebox_t[BOXSIZE];

struct double_list
{
	pokebox_t box;
	struct double_list *prev;
	struct double_list *next;
};
typedef struct double_list DOUBLE_LIST;

struct double_list_header
{
	DOUBLE_LIST *first;
	DOUBLE_LIST *last;
	int count;
};
typedef struct double_list_header DOUBLE_LIST_HEADER;

int movePkmn(DOUBLE_LIST HEADER *header, coord_t curPos, coord_t newPos);
int addPkmn(DOUBLE_LIST HEADER *header, coord_t pos);
int removePkmn(DOUBLE_LIST HEADER *header, coord_t pos);
int checkIfOccupied(DOUBLE_LIST HEADER *header, coord_t pos);
void printBox(pokebox_t box);

#endif //_POKEMON_H
