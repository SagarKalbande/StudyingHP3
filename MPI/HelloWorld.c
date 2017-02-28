#include<mpi.h>
#include<iostream>

using namespace std;
void main(int argc, char *argv[]) 
{
	MPI_Init(&argc, &argv);
	cout << "Hello World!" << endl;
	MPI_Finalize();
}


//Executing on windows through CMD: mpiexec filename.exe (An exe file will be generated in Debug Folder of the project when you build the project in visual studio)
