#include "crawler.h"


int main()
{
	setbuf(stdout,NULL);
	/*int i;
	threadpool tp=create_threadpool(NUM_THREADS);
	char *url="www.baidu.com";
	
	for(i=0;i<NUM_THREADS;i++)
	{
		dispatch(tp,crawler,url);
	}

	do_work(tp);

	destroy_threadpool(tp);*/

	char *url="/techqq/index.htm";
	char *recvbuf=(char*)malloc(1024*sizeof(char));
	FILE *file=fopen("./cra_recv.dat","a+");
	/*int recSize=10*1024*1024;
	//char *recvbuf=NULL;
	int sockfd=nn_socket(AF_SP,NN_PAIR);//nanomsg socket declaration before tcp socket may cause problems.	
	
	assert (sockfd >= 0);
	assert( nn_setsockopt (sockfd, NN_SOL_SOCKET,NN_RCVBUF,&recSize,sizeof(recSize))>=0);
	assert( nn_setsockopt (sockfd, NN_SOL_SOCKET,NN_SNDBUF,&recSize,sizeof(recSize))>=0);
	assert (nn_connect (sockfd, "ipc://./cra_ana.ipc") >= 0);*/
		
	crawler(url);
	//send_ipc("hello","ipc://./cra_ipc.ipc");
	recvbuf[0]='\0';
	//int count=0;
	while(1)
	{	//puts("before recv-ipc");
		//recv_ipc(sockfd,recvbuf,1024*1024);
		//puts("after recv-ipc");
		
    		//fprintf(file,"recvbuf:%s\n",recvbuf);
    		//fclose(file);			
		//printf("fasfasf");
		fgets(recvbuf,1024,file);
		printf("recvbuf:%s\n",recvbuf);
		crawler(recvbuf);
		//printf("count:%d\n",count++);
		/*while(crawler(sockfd,recvbuf) == 0)
		{puts("1");
			free(recvbuf);
			recv_ipc(sockfd,recvbuf,1024*1024);
			file=fopen("./cra_recv.dat","a");
    			fprintf(file,"recvbuf:%s\n",recvbuf);
    			fclose(file);
			//printf("recvbuf:%s\n",recvbuf);			
		}*/
		
		//free(recvbuf);
	}
	
	//nn_close(sockfd);
	
	return 0;
}
