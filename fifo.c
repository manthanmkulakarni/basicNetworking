#include<iostream.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>

int main(int argc,char* argv[])
{
if(argc!=2 && argc!=3)
{
cout<<"usage:"<<argv[0]<<"<file> [<arg>]";
return 0;
}
int fd;
char buf[256];
(void) mkfifo(argv[1], S_IFIFO | S_IRWXU | S_IRWXG | S_IRWXO );
if(argc==2)
{
fd=open(argv[1],O_RDONLY | O_NONBLOCK);
while(read(fd,buf,sizeof(buf))==-1 && errno==EAGAIN)
sleep(1);
while(read(fd,buf,sizeof(buf))>0)
cout<<buf<<endl;
}
else
{
fd=open(argv[1],O_WRONLY);
write(fd,argv[2],strlen(argv[2]));
}
close(fd);
}
