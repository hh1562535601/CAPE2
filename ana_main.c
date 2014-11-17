#include "analyzer.h"

int main()
{
	setbuf(stdout,NULL);

    	urlset us;
	int sockfd = nn_socket (AF_SP, NN_PAIR);
	int timeout=100;
	int i;

	assert (sockfd >= 0);
	nn_setsockopt (sockfd, NN_SOL_SOCKET, NN_RCVTIMEO, &timeout, sizeof (timeout));

    	us.n_read=-1;
    	us.n_write=-1;
	us.url=(char**)malloc(160*1024*sizeof(char*));

	for(i=0;i<160*1024;i++)
	{
		us.url[i]=NULL;
	}
//printf("us.n_write:%d\n",us.n_write);
	while(1)
	analyze(&us,sockfd);

	assert(nn_shutdown (sockfd, 0));

	return 0;
}
