#ifndef _FILE_MANAGER_
#define _FILE_MANAGER_

char **read_input(FILE *fp, int *array_size);
int saveTimeToFile(int array_size, double time, int option);

#endif
