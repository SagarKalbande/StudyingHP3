#include<stdio.h>
int reportprime(int a, int b) {
	int flag[100] = { 0 };
	for (int i = a; i < b; i++)
	{
		for (int j = 2; j < i/2; j++)
		{
			if (i%j == 0){
				flag[i]++;
				}
		}
		
		if (flag[i] == 0) {
			printf("%d is prime\n", i);
		}
		
		
	}
	return 0;
}

int main() {
	int a, b;

	printf("Give the 2 numbers\n");

	scanf_s("%d %d", &a, &b);

	reportprime(a, b);

	return 0;

}
