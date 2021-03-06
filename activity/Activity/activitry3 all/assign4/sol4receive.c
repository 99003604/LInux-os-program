#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int ret,mbytes;
	struct mq_attr attr1;
	attr1.mq_msgsize=256;
	attr1.mq_maxmsg=20;
	mqd_t mqid;
	mqid=mq_open("/mque",O_RDONLY|O_CREAT,0555,&attr1);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buffer[8192];
	int maxlen=256,prio;
	mbytes=mq_receive(mqid,buffer,maxlen,&prio);
	if(mbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buffer[mbytes]='\0';
	// receiver to sender from message
	printf("receive msg from sender:%s,nbytes=%d,prio=%d\n",buffer,mbytes,prio);
	mqd_t mqid2;
	struct mq_attr attr2;
	attr2.mq_msgsize=256;
	attr2.mq_maxmsg=20;
	mqid2=mq_open("/mque2",O_WRONLY|O_CREAT,0555,&attr2);
	for(int counter=0;buf[counter]!=NULL;counter++)
    {
        if(buffer[counter]>='A' && buffer[counter]<='Z')
            buffer[counter]=buffer[counter]+32;
        else if(buffer[counter]>='a' && buffer[counter]<='z')
            buffer[counter]=buffer[counter]-32;
    }
	ret=mq_send(mqid2,buffer,mbytes+1,2);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqid);
	mq_close(mqid2);
	return 0;
}
