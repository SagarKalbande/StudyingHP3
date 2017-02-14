#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N 6                 
#define M 5                 
#define P 7              

int main (int argc, char *argv[]) 
{
	int nthreads,i,j,k,chunk;
	double	a[N][M],b[M][P],c[N][P];   

	for(i=0;i<N;i++)
    		for(j=0;j<M;j++)
      			a[i][j]= i+j;
  	
	for(i=0;i<M;i++)
    		for(j=0;j<P;j++)
      			b[i][j]= i*j;
  
	for(i=0;i<N;i++)
    		for(j=0;j<P;j++)
      			c[i][j]=0;

  	#pragma omp parallel shared(a,b,c) 
  	{
		#pragma omp for collapse(3)
  			for(i=0;i<N;i++)    
    				for(j=0;j<P;j++)       
      					for(k=0;k<M;k++)
        					c[i][j] += a[i][k] * b[k][j];
  	}

	printf("\nResult Matrix:\n");
	for(i=0;i<N;i++) {
  		for(j=0;j<P;j++) 
    			printf("%6.2f   ", c[i][j]);
  		printf("\n"); 
  	}
	printf ("\nDone.\n");
	return 0;
}

