#include<sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

typedef struct msgbuf 
{
         long mtype;
         char mtext[128];
         } msg_buf ;
main()
{
	msg_buf m;
	int r;
	int msgflg = IPC_CREAT|0666;
	key_t key = 30;
	int msgid =  msgget(key, msgflg); 	
do{
	r=msgrcv(msgid, &m, sizeof(m.mtext), 0, 0); 
	if(r<0)
	{
		printf("Message not received\n");
	}
	else
	{
		
		printf("Message received is: \n");
		puts(m.mtext);
		
	}}while(strcmp(m.mtext,"END")!=0);
}
