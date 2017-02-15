#include<stdio.h>
#include<omp.h>



int main() {
	float no_of_steps = 1000;
	float step_size = 1 / no_of_steps;
	float x = 0;
	float y_value = 0;
	float area = 0;

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
	printf("%f", 4 * area);

	getchar();
	return 0;

}
