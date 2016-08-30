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
		scanf("%s",str+1);
		int len = strlen(str+1);
		int result = msgsnd(qid,str+1,sizeof(str+1),0);
		if(result==-1)
		break;
		printf("%s\n",str);
		if(len==3 && str[1]=='E' && str[2]=='N' && str[3]=='D')
		break;
	}
  return 0;
}
	
