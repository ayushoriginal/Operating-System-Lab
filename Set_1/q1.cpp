#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	
		uid_t uid,uide;
		gid_t gid,gide;
		pid_t return_of_fork,pid,ppid;
		int i,j;
		return_of_fork = fork();	//returns positive for parent and zero for child	 
	 	 uid = getuid();
		uide = geteuid();
		gid =  getgid();
		gide = getegid();
		pid = getpid(); 
		ppid = getppid();








	


















	
		if(return_of_fork < 0)
		{
		  printf("\nFailed to create the child process\n");
	          printf("\n\nUSER:: \n uid= %d \n uide = %d \n\n GROUP::\n gid = %d \n gide = %d \n\n PROCESS::\n pid = %d \n ppid = %d\n\n",uid,uide,gid,gide,pid,ppid);
		   exit(1);
		 }	
		
		if(return_of_fork == 0)
		{
	//	   wait();
		  printf("\n In Child process\n");
	         printf("\n\nUSER:: \n uid= %d \n uide = %d \n\n GROUP::\n gid = %d \n gide = %d \n\n PROCESS:: \n pid = %d \n ppid = %d\n\n",uid,uide,gid,gide,pid,ppid);	
		}

		if(return_of_fork > 0)
		{
		   wait();
		   printf("\nIn Parent Process\n");
	          printf("\n\nUSER:: \n uid= %d \n uide = %d \n\n GROUP::\n gid = %d \n gide = %d \n\n PROCESS::\n pid = %d \n ppid = %d\n\n",uid,uide,gid,gide,pid,ppid);	
		}



		

		
		return(0);
}

		


/*



		printf("\nA\n");
		
		 wait();
		fork();
		
		printf("\nB\n");
		printf("\nuid= %d uide = %d  gid = %d gide = %d pid = %d ppid = %d\n",uid,uide,gid,gide,pid,ppid);
















*/
