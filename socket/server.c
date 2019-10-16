#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){
int sn,newsn,port=8090,alen,p=0;
char databuf[1024]={0},name[50]={0};

struct sockaddr_in server;
if((sn=socket(AF_INET,SOCK_STREAM,0))==0){
printf("Error in socket\n");
return 0;
}
server.sin_addr.s_addr=inet_addr("127.0.0.1");
server.sin_family=AF_INET;
server.sin_port=htons(port);
alen=sizeof(server);
if(bind(sn,(struct sockaddr*)&server,sizeof(server))<0){
printf("Error in bind\n");
return 0;
}
if(listen(sn,3)==-1){
return 0;
}
printf("Listning\n");
if((newsn=accept(sn,(struct sockaddr*)&server,&alen))<0){
printf("Not found\n");
return 0;
}
read(newsn,name,50);
printf("recived file name %s\n",name);

FILE *fptr=NULL;

fptr=fopen(name,"r");
if(fptr==NULL){
printf("Erro in file open\n");
}

char c;

while((c=getc(fptr))!=EOF)
	databuf[p++]=c;

//printf("%s\n",databuf);
send(newsn,databuf,1024,0);

return 0;
}
