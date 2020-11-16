#include <stdio.h>
#include <stdlib.h>
#include <merge_sort.h>
#include <insertion_sort.h>
#include <bubble_sort.h>
#include <defines.h>
#include <ctype.h>
#include <time.h>
#include <watch.h>
#include <file_manager.h>

int print_output(char **array, int array_size)
{
	int i;
	for(i = 0; i < array_size; i++) printf("%s\n", array[i]);
	return SUCCESS;
}

int main(void)
{

	#ifdef DEBUG
		clock_t start_time, end_time;
		double averageTime = 0.0;
	#endif

	int i;
	FILE *file_pointer;
	char *file_name = (char *) calloc(30, sizeof(char));
	int option;
	int array_size = 0;
	scanf(" %s %d", file_name, &option);
	file_pointer = fopen(file_name, "r");
	if(!file_pointer) 
	{
		printf("Nao deu pra abrir o arquivo amigao ;-;\n");
		return ERROR;
	}

	char **array = read_input(file_pointer, &array_size);
	array_size--;
	#ifndef DEBUG
		int j;
		switch(option)
		{
			case 1:
				bubble_sort(array, array_size);
				break;
			case 2:
				insertion_sort(array, array_size);
				break;
			case 3:
				merge_sort(array, 0, array_size - 1);
				break;
			default:
				printf("Invalid option\n");
		}
		for(i = 0; i < array_size; i++)
		{
			j = 0;
			while(array[i][j])
			{
				array[i][j] = tolower(array[i][j]);
				j++;
			}
		}
		print_output(array, array_size);
	#endif
	#ifdef DEBUG
		for(i = 0; i < 10; i++)
		{
			start_time = clock();
			array_size = 0;
			fseek(file_pointer, 0, SEEK_SET);
			array = read_input(file_pointer, &array_size);
			if(option == BUBBLE_SORT)
				bubble_sort(array, array_size);
			else if(option == INSERTION_SORT)
				insertion_sort(array, array_size);
			else if(option == MERGE_SORT)
				merge_sort(array, 0, array_size - 1);
			end_time = clock();
			averageTime += getExecutionTime(start_time, end_time);
		}

		averageTime = averageTime / 10.00; 
		saveTimeToFile(array_size, averageTime, option);
	#endif
	fclose(file_pointer);
	return SUCCESS;
}
