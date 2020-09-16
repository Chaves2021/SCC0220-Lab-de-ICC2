#include <time.h>
#include <watch.h>
#include <stdio.h>
#include <stdlib.h>

double getExecutionTime(clock_t start_time, clock_t end_time)
{
	double time_taken = (end_time - start_time) / (double) CLOCKS_PER_SEC;
	#ifdef DEBUG
		printf("time taken: %.4lf\n", time_taken);
	#endif
	return time_taken;
}
