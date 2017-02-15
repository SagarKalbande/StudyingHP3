#include<stdio.h>
#include<omp.h>


int main() {
	int a, b;

	printf("Give the 2 numbers\n");

	scanf_s("%d %d", &a, &b);
#pragma omp parallel
	{
		
	int flag[100] = { 0 };
#pragma omp for
	for (int i = a; i < b; i++)
	{
		for (int j = 2; j < i / 2; j++)
		{
			if (i%j == 0){
				flag[i]++;
			}
		}

		if (flag[i] == 0) {
			printf("%d is prime and run by thread %d\n", i,omp_get_thread_num());
		}
	}


	}

	return 0;

}
