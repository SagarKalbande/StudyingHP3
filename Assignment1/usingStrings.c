#include<stdio.h>
#include<string>

using namespace std;

int w = 4;

int W_blocks(string A){
	char A1[100][100];
	for (int i = 0; i < A.length() - w + 1; i++)
	{
		int a = 0;
		for (int j = i; j < i + w; j++)
		{
			A1[i][j] = A[j];
			printf("%c", A1[i][j]);
			a++;
		}
		printf("\n");
	}
	return 0;
}

int main(){

	string Sq = "AKLMAATCD";
	string Si = "ALPQRKLMMAKLPPRTLQ";
			
	W_blocks(Sq);
	printf("\n");
	W_blocks(Si);
	
}



