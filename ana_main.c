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
	us.url=(char**)malloc(256*1024*sizeof(char*));

	for(i=0;i<256*1024;i++)
	{
		us.url[i]=NULL;
	}

	analyze(&us,sockfd);

	assert(nn_shutdown (sockfd, 0));

	return 0;
}
