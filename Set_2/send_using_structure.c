#include<sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

typedef struct msgbuffer
{
	long mtype;
	char mtext[128];
}msg_buf;

 main()
{
	msg_buf m;
	int msgid; 
	int r;
	key_t key = 30;
	int msgflg = IPC_CREAT|0666;
	msgid = msgget(key, msgflg);
	if(msgid < 0)
	{
		printf("Message queue not created\n");
	}
	else 
	{
		do{
		m.mtype = 1;
		printf("Enter a string\n");
		scanf("%s",m.mtext);
		r = msgsnd(msgid, &m, sizeof(m.mtext), 0);
		if(r<0)
		{
			printf("Message not sent\n");
		}
		else
		{
			printf("Message sent\n");
		}
		}while(strcmp(m.mtext, "END")!=0);
	}
}
	
