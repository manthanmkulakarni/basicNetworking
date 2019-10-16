#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(){

int socket_desc,newsock;
	struct sockaddr_in server;
char databuf[1024]={0};
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);

if(socket_desc==-1){
	printf("could not create socket\n");

}
else{
	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8090 );

		if(bind(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
		{
			printf("Error in connecting the socket\n");

		}

		else{
			if(listen(socket_desc,10)<0) 
				printf("error in listening\n");
			else{
				printf("connected\n");

			newsock=accept(socket_desc,(struct sockaddr *)&server,(socklen_t*)sizeof(server));
			
			
			if(recv(socket_desc,databuf,1024,0)<0)
				printf("%s recv\n",databuf);

			else
				printf("Not recv");

			}

		}


}

return 0;
}
