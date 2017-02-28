#include<mpi.h>
#include<iostream>

using namespace std;
void main(int argc, char *argv[]) 
{
	MPI_Init(&argc, &argv);
	cout << "Hello World!" << endl;
	MPI_Finalize();
}

//Configuring MPI on windows machine: 
//requires installation of HPcClient_x64.Msi https://www.microsoft.com/en-us/download/confirmation.aspx?id=36044
//Also mpi_x64.msi https://www.microsoft.com/en-in/download/confirmation.aspx?id=36045
//vcredist_x64.exe https://www.microsoft.com/en-in/download/confirmation.aspx?id=14632
//After installation, dependencies and library additions should be handled: https://www.youtube.com/watch?v=yYlJc9REY60

//Executing on windows through CMD: mpiexec filename.exe (An exe file will be generated in Debug Folder of the project when you build the project in visual studio)
