#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
int sn,newsn,adlen;
char data[1024],name[20];

if((sn=socket(AF_INET,SOCK_STREAM,0))==0){
printf("Sock error\n");
return 0;
}
struct sockaddr_in server;

server.sin_addr.s_addr=inet_addr("10.42.0.1");
server.sin_family=AF_INET;
server.sin_port=htons(8090);
adlen=sizeof(server);

if(bind(sn,(struct sockaddr*)&server,adlen)<0){
printf("Error in bind\n");
return 0;
}
if(listen(sn,3)<0){
printf("error in listning\n");
return 0;
}

if((newsn=accept(sn,(struct sockaddr*)&server,&adlen))<0){

printf("error in accept\n");
return 0;
}

if(newsn<0){
printf("error in accept\n");
return 0;
} 

read(newsn,name,20);
printf("%s",name);

return 0;
}
