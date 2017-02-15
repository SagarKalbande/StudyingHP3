#include<stdio.h>
#include<omp.h>
int main(){
	
	int a[3] = { 0 };
	int x[3] = { 0 };
	int product = 0;
	printf("Give the 1st vector\n");
	scanf_s("%d %d %d", &a[0],&a[1],&a[2]);
	printf("Give the 2nd vector\n");
	scanf_s("%d %d %d", &x[0], &x[1], &x[2]);

	printf("Vector 1 is %di+%dj+%dk\n", a[0], a[1], a[2]);
	printf("Vector 2 is %di+%dj+%dk\n\n", x[0], x[1], x[2]);

#pragma omp parallel
	{
#pragma omp for
		for (int i = 0; i < 3; i++)
		{	
			int ID = omp_get_thread_num();
			product = product + a[i] * x[i];
			printf("%d thread calculated %d product\n", ID, product);
		}
	}
	printf("Dot Product is %d\n", product);

	return 0;
	
}
