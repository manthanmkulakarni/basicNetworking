#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(){


int socket_desc;
char datarecv[10000];
	struct sockaddr_in server;
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);

if(socket_desc==-1){
	printf("could not create socket\n");

}
else{
	
server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 80 );

		if(connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
		{
			printf("Error in connecting the socket\n");

		}

		else{
			

			if((send(socket_desc,"manthan",sizeof("manthan"),0)>0))
				printf("sent");

			else
				printf("Not received\n");

		}


}

return 0;
}
