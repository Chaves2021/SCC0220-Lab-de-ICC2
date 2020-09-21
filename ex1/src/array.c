#include <stdio.h>
#include <stdlib.h>
#include <array.h>
#include <defines.h>

int print_array(int *array, int array_size)
{
	int i;
	for(i = 0; i < array_size; i++) printf("%d ", array[i]);
	printf("\n");
	return SUCCESS;
}

int *reverse_array(int *array, int array_size) 		//r
{
	int aux;
	int i;
	for(i = 0; i < array_size / 2; i++)		//1st time: a + c
	{						//2nd time and later: (n/2) * (2a+c)
		aux = array[i];				//(a + p) * n/2
		array[i] = array[array_size - i - 1];	//(2a + 2p) * n/2
		array[array_size - i - 1] = aux;	//(2a + p) * n/2
	}
	return array;					//r
}

// COMPLEXITY:
// r + a + c + n/2 * (2a + c) + (a+p) * n/2 + (2a + 2p) * n/2 + (2a + p) * n/2 + r
// r = a = p = c = C
// Simplifying...
// F(n) = 6n*C + 4C

int *bubble_sort(int *array, int array_size)		//r
{
	int i, j;
	int aux;
	for(i = array_size - 1; i > 0; i--)		//1st time: a + c
	{                                               //2nd time and later: n * (2a + c)

		for(j = 0; j < i; j++)			//1st time: n * (a + c)
							//2st time and later: n * (n - 1) * (2a + c)
		{
			if(array[j] > array[j + 1])	//n * (n - 1) * (2p + c + a)
			{
				aux = array[j];		//n * (n - 1) * (a + p)
				array[j] = array[j + 1];//n * (n - 1) * (2a + 2p)
				array[j + 1] = aux;     //n * (n - 1) * (2a + p) 
			}
		}
	}
	return array;					//r
}

// COMPLEXITY:
// r + a + c + n * (2a + c) + n * (a + c)  + [n * (n - 1)] * [(2a + c) + (2p + c + a) + (a + p) + (2a + 2p) + (2a + p)] + r
// r = a = p = c = C
// Simplifying...
// F(n) = 16n*C² - 11n*c + 4C

