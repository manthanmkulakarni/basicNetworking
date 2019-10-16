#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){
int sn,port=8090;
char databuf[1024]={0},name[50];

struct sockaddr_in server;
if((sn=socket(AF_INET,SOCK_STREAM,0))==0){
printf("Error in socket\n");
return 0;
}
server.sin_addr.s_addr=inet_addr("10.42.0.1");
server.sin_family=AF_INET;
server.sin_port=htons(port);

if(connect(sn,(struct sockaddr*)&server,sizeof(server))==-1){
printf("Error in bind\n");
return 0;
}
printf("Enter the name\n");
scanf("%s",name);
if(send(sn,name,50,0)<0){
return 0;
}

printf("Name sent\n");

read(sn,databuf,1024);

printf("%s",databuf);

return 0;
}
