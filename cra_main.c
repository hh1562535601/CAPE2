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

	char *url="http://10.106.108.179/techqq/index.htm";
	char *buf=(char*)malloc(250*1024*sizeof(char));
	char *recvbuf=NULL;

	/*while(1)
	{
		crawler(sockfd,url,buf);
  		assert (nn_bind (sockfd, IPC_URL) >= 0);
      	//printf ("NODE0: RECEIVED \"%s\"\n", buf);
		recv_ipc(sockfd,recvbuf);
		nn_freemsg (buf);
	}*/
	crawler(sockfd,url,buf);

	assert(nn_shutdown (sockfd, 0));
	
	return 0;
}
