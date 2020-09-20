#include <stdio.h>
#include <stdlib.h>
#include <defines.h>
#include <file_manager.h>
#include <time.h>
#include <watch.h>
#include <array.h>

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
	int n_executions = get_executions(file_name);
	printf("%d\n", n_executions);
	if(!array) return ERROR;
	
	int option = display_menu();

	for(i = 0; i < 1000; i++)
	{
		start_time = clock();
		if(option == 1) 
		{
			program = REVERSE_ARRAY;
			reverse_array(array, array_size); 
		}
		else if(option == 2) 
		{
			program = BUBBLE_SORT;
			bubble_sort(array, array_size);
			array = bin2array(file_name, &array_size);
		}
		else
		{
			printf("Invalid Option :p\n");
			exit(1);
		}
		end_time = clock();
		#ifndef DEBUG
			averageTime += getExecutionTime(start_time, end_time);
		#else
			averageTime += getExecutionTime(start_time, end_time);
		#endif
	}

	#ifndef DEBUG
		averageTime = averageTime / (double) n_executions;
		saveTimeToFile(array_size, averageTime, program);
	#else
			array = bin2array(file_name, &array_size);
			printf("The initial array is: \n");
			print_array(array, array_size);
			printf("The final array is: \n");
			if(option == 1) array = reverse_array(array, array_size); 
			else array = bubble_sort(array, array_size);
			print_array(array, array_size);
			printf("average time: %lf\n", averageTime);
	#endif
	
	
	free(array);

	return SUCCESS;
}
