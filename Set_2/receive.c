#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

int main()
{ 
	char str[400];
	int qid = msgget((key_t)1234,IPC_CREAT|0666);
	while(1)
	{
		printf("The typed string is:\n");
		ssize_t abc = msgrcv(qid,str+1,500,0,0);
		int len = strlen(str+1);
		printf("%s\n",str+1);
		if(len==3 && str[1]=='E' && str[2]=='N' && str[3]=='D')
		break;
	}
  return 0;
}

