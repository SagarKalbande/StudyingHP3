#include<stdio.h>

int main() {
	float no_of_steps = 1000000;
	float step_size = 1 / no_of_steps;
	float x = 0;
	float y_value=0;
	float area=0;

	for (int i = 0; i < no_of_steps; i++)
	{	
		x = x + step_size;
		y_value = 1 / (1 + x*x);
		area = area + (y_value)*step_size;
		printf("%f", area);
	}

	printf("%f", 4*area);

	getchar();
	return 0;
	
}
