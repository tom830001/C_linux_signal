#include <stdio.h>	//standar input
#include <signal.h> 	//signal
#include <stdlib.h>	//exit
void signal_handler(int signum)
{
	printf("Get signal %d\n",signum);
	exit(0);					//normal exit
}

void init_signal()
{
	struct sigaction sa_usr;
	sa_usr.sa_flags = 0; 				// if handler exist set 0
	sa_usr.sa_handler = signal_handler;		//handler will start if catch signal below
	sigaction(SIGINT,&sa_usr,NULL);			//Ctrl C
	sigaction(SIGTSTP,&sa_usr,NULL);		//Ctrl Z
	sigaction(SIGQUIT,&sa_usr,NULL);		//Ctrl +\                     //
	sigaction(SIGTERM,&sa_usr,NULL);		//normal terminate 15 killall/and default kill
}

int main()
{
	init_signal();
	
	while(1)
	{
		;
	}
}
