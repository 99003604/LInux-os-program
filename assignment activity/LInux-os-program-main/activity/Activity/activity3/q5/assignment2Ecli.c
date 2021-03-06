
#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int ret,nbytes1;
	struct mq_attr attr1;
	attr1.mq_msgsize=256;
	attr1.mq_maxmsg=10;
	mqd_t mqid3;
	mqid3=mq_open("/mque1",O_RDONLY|O_CREAT,0555,&attr1);
	if(mqid3<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buffer[8192];
	int maxlength=256,prio;
	nbytes1=mq_receive(mqid3,buffer,maxlength,&prio);
	if(nbytes1<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buffer[nbytes1]='\0';
	int k;
    printf("%s",buffer);

	k =execlp("/bin/gcc","gcc",buffer,0);
    if(k<0)
		{
			perror("execlp");
			exit(1);
		}
		exit(5);
		
	printf("receive msg:%s,nbytes=%d,prio=%d\n",buffer,nbytes1,prio);
	mq_close(mqid3);
	return 0;
}
