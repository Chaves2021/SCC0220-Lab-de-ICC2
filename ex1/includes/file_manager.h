#ifndef _FILE_MANAGER_
#define _FILE_MANAGER_

int *bin2array(char *file_name, long int *array_size);
int saveTimeToFile(int array_size, double time, PROGRAM program);
int get_executions(char *file_name);

#endif
