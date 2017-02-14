/*   This shows area as 0 for all threads!! Why??*/

#include<stdio.h>
#include<omp.h>

int main() {
	const int no_of_steps = 10;
	float step_size = 1 / no_of_steps;
	float x = 0;
	float y_value = 0;
	float area[no_of_steps];
	int numofthreads;
	float sum = 0;

	omp_set_num_threads(no_of_steps) ;
	#pragma omp parallel shared(area)
	{
		numofthreads = omp_get_num_threads();
		int ID = omp_get_thread_num();
		area[ID] = step_size*(4 / (1 + step_size*ID*step_size*ID));
		printf("%d %f\n", ID, area);
	};


	return 0;
}
