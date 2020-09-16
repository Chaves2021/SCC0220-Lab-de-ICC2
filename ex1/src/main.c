#include <stdio.h>
#include <stdlib.h>
#include <defines.h>
#include <file_manager.h>
#include <time.h>
#include <watch.h>

int display_menu()
{
	int option;

	printf("*****************************************\n");
	printf("1- Reverse Array\n");
	printf("2- Bubble Sort\n");
	printf("*****************************************\n");

	scanf("%d", &option);
	return option;
}

int main(int argc, char **argv)
{
	double averageTime;
	clock_t start_time, end_time;
	long int array_size;
	int *array = NULL;
	char *file_name;
	int i;
	PROGRAM program;
	if(argc != 2) 
	{
		printf("Usage: %s <file_name>\n", argv[0]);
		exit(1);
	}
	file_name = argv[1];
	array = bin2array(file_name, &array_size);
	if(!array) return ERROR;

	for(i = 0; i < 1000; i++)
	{
		start_time = clock();
		if(display_menu() == 1) 
		{
			program = REVERSE_ARRAY;
			reverse_array(array, array_size); 
		}
		else if(display_menu() == 2) 
		{
			program = BUBBLE_SORT;
			bubble_sort(array, array_size);
		}
		else
		{
			printf("Invalid Option :p\n");
			exit(1);
		}
		end_time = clock();
		#ifdef DEBUG
			printf("The final array is: \n");
			int j;
			for(j = 0; j < array_size; j++) printf("%d\n", array[i]);
		#else
			averageTime += getExecutionTime(start_time, end_time);
		#endif
	}

	#ifndef DEBUG
		averageTime = averageTime / (double) 1000.00;
		saveTimeToFile(array_size, averageTime, program);
	#endif
	
	free(array);

	return SUCCESS;
}
