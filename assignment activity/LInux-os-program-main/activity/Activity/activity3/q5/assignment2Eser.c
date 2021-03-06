#include"sol2e.h"
int main()
{
	int ret;
	mqd_t mqid3;
	struct mq_attr attr1;
	attr1.mq_msgsize=256;
	attr1.mq_maxmsg=10;
	mqid3=mq_open("/mque1",O_WRONLY|O_CREAT,0555,&attr1);
	if(mqid3<0)
	{
		perror("mq_open");
		exit(1);
	}
	char str1[]="temp.c";
	int len=strlen(str1);
	ret=mq_send(mqid3,str1,len+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqid3);
	return 0;
}
