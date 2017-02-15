#include<stdio.h>
#include<omp.h>

int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	int sum = 0;
	float mean = 0;
#pragma omp parallel
	{
	#pragma omp for
		for (int i = 0; i < 10; i++)
		{
			sum = sum + a[i];
			printf("Thread number %d calculates %d sum\n", omp_get_thread_num(),sum);
		}
	}
	mean = (float)sum / 10;

	printf("%f is the mean", mean);

}
