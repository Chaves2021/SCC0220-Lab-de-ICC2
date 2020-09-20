#ifndef _FILE_MANAGER_
#define _FILE_MANAGER_

int *bin2array(char *file_name, int array_size);
int saveTimeToFile(int array_size, double time, PROGRAM program);
int get_array_size(char *file_name);

#endif
