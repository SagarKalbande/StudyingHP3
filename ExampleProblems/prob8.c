#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define N 6                 
#define M 5                 
#define P 7                 

int main (int argc, char *argv[]) 
{
	int	tid, nthreads,i,j,k,chunk;
	double	a[N][M], b[M][P],c[N][P];           

	chunk=10;                   

	#pragma omp parallel shared(a,b,c,nthreads,chunk) private(tid,i,j,k)
	{
  		tid=omp_get_thread_num();
  		if(tid==0) {
    			nthreads = omp_get_num_threads();
			printf("Starting matrix multiple example with %d threads\n",nthreads);
			printf("Initializing matrices...\n");
    		}
  
		#pragma omp for schedule (static, chunk) 
  			for(i=0;i<N;i++)
    				for(j=0;j<M;j++)
      					a[i][j]= i+j;
  		#pragma omp for schedule (static, chunk)
  			for(i=0;i<M;i++)
    				for(j=0;j<P;j++)
      					b[i][j]= i*j;
  		#pragma omp for schedule (static, chunk)
  			for(i=0;i<N;i++)
    				for(j=0;j<P;j++)
      					c[i][j]= 0;

  		printf("Thread %d starting matrix multiply...\n",tid);
  		#pragma omp for schedule (static, chunk)
  			for(i=0;i<N;i++) {
				printf("Thread=%d did row=%d\n",tid,i);
    				for(j=0;j<P;j++)       
      					for(k=0;k<M;k++)
        					c[i][j] += a[i][k] * b[k][j];
    			}
	}   
	printf("\nResult Matrix:\n");
	for(i=0; i<N; i++) {
  		for(j=0; j<P; j++) 
    			printf("%6.2f   ", c[i][j]);
  		printf("\n"); 
  	}
	printf ("\nDone.\n");
	return 0;
}

