#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;

int main()
{
	int id = shmget(IPC_PRIVATE,4*sizeof(int),IPC_CREAT|0666);
	int *ptr = (int *)shmat(id,0,0);

	vector<int> A(200);
	for (int i=0;i<200;i++)
		A[i] = rand()%1000;                          
	
	for (int i=0;i<200;i++)
		cout << A[i] << " ";
	cout << "\n" << endl;                                 

	int max1 = -1;
	int min1 = 1000;
	int max2 = -1;
	int min2 = 1000;

	pid_t PID = fork();
	if (PID == 0)
	{
		int a=0;
		cout<<a<<endl;
		for (int i=0;i<100;i++)
		{
			if (A[i] > max1)
				max1 = A[i];
			if (A[i] < min1)
				min1 = A[i];
		}
		cout << "IN child 1: " << endl;
		cout << "maximum in first half = " << max1 << endl;
		cout << "minimum in first half = " << min1 << endl;

		*ptr = max1;	*(ptr+1) = min1;
	}
	else
	{
		pid_t PID1 = fork();

		if (PID1 == 0)
		{
			for (int i=100;i<200;i++)
			{
				if (A[i] > max2)
					max2 = A[i];
				if (A[i] < min2)
					min2 = A[i];
			}
			cout << "IN child 2: " << endl;
			cout << "maximum in second half = " << max2 << endl;
			cout << "minimum in second half = " << min2 << endl;
			
			*(ptr+2) = max2;	*(ptr+3) = min2;
		}
		
		else
		{
			wait(NULL);
			cout << "IN Parent: " << endl;
			cout << "Maximum number in the array is = " << max(*ptr,*(ptr+2)) << endl;
			cout << "Minimum number in the array is = " << min(*(ptr+1),*(ptr+3)) << endl;
		}		
	}

	//Terminate the shared memory
	shmctl(id, IPC_RMID, NULL); //To remove a shared memory segment
    		
	/*Run the program with and without shmctl and type $ipcs to see the difference*/

	
	return 0;
}
