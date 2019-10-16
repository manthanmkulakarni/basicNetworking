#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){
int sn=socket(AF_INET,SOCK_STREAM,0);
if(sn==0){
printf("Error in socket\n");
return 0;
}
char name[20];
struct sockaddr_in client;
client.sin_addr.s_addr=inet_addr("10.42.0.1");
client.sin_family=AF_INET;
client.sin_port=htons(8090);

if(connect(sn,(struct sockaddr*)&client,sizeof(client))<0){
printf("Error in connect\n");
return 0;
}

scanf("%s",name);
send(sn,name,20,0);

return 0;
}
