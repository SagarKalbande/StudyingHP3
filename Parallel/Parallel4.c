#include<stdio.h>
#include<omp.h>

int main() {

	double startTime = 0, runTime = 0;
	startTime = omp_get_wtime();
	float no_of_steps = 1000;
	float step_size = 1 / no_of_steps;
	float x = 0;
	float y_value = 0;
	float area = 0;
//Try changing number of threads and experimenting with the runtime
	omp_set_num_threads(64);
#pragma omp parallel
	{
		
#pragma omp for
		for (int i = 0; i < (int)no_of_steps; i++)
		{
			x = x + step_size;
			y_value = 1 / (1 + x*x);
			area = area + (y_value)*step_size;
			printf("Thread number %d calculated area as :%f\n", omp_get_thread_num() ,area);
		}
	}

	runTime = omp_get_wtime() - startTime;
	printf("%f %lf", 4 * area, runTime);
	getchar();
	return 0;
}
