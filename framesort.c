#include<stdio.h>
#include<stdlib.h>

struct Frame{
int seq;
char data[2];
};

int nframe=1;


typedef struct Frame Frame;

Frame * divide(char *data,int len){

Frame *f;
f=(Frame*)malloc(sizeof(Frame)*40);
int i,j;
for(i=0,j=0;i<len;){
	(f+j)->data[0]=data[i];
	(f+j)->data[1]=data[i+1];
	i=i+2;
	(f+j)->seq=j;
	j=j+1;
}

nframe=j+1;

return f;
}


void fsort(Frame *f){
char temp;
int t;

for(int i=0;i<nframe;i++){
	for(int j=0;j<nframe-1;j++){
		if(((f+j)->seq)>((f+j+1)->seq)){
			temp=(f+j)->data[1];
			(f+j)->data[1]=(f+j+1)->data[1];
			(f+j+1)->data[1]=temp;

			temp=(f+j)->data[0];
			(f+j)->data[0]=(f+j+1)->data[0];
			(f+j+1)->data[0]=temp;

			t=(f+j)->seq;
			(f+j)->seq=(f+j+1)->seq;
			(f+j+1)->seq=t;


			}
	
		}

	}

}

void shuffel(Frame *f){
int j,t;
char temp;
for(int i=0;i<nframe;i++){
	j=rand()%nframe;
printf("%d %d\n",j,i);
	
			temp=(f+j)->data[1];
			(f+j)->data[1]=(f+i)->data[1];
			(f+i)->data[1]=temp;

			temp=(f+j)->data[0];
			(f+j)->data[0]=(f+i)->data[0];
			(f+i)->data[0]=temp;

			t=(f+j)->seq;
			(f+j)->seq=(f+i)->seq;
			(f+i)->seq=t;

	

	}



}

int main(){

char seq[100];
int n=0;
Frame *fptr;

scanf("%d",&n);
scanf("%s",seq);
if((n%2)==1)
{
seq[n]='!';
n=n+1;
}
fptr=divide(seq,n);

for (int i=0;i<nframe;i++)
	printf("%s",(fptr+i)->data);
printf("\n");

shuffel(fptr);
printf("After shuffel\n");

for(int i=0;i<nframe;i++)
	printf("%s",(fptr+i)->data);
printf("\n");

fsort(fptr);

for(int i=0;i<nframe;i++)
	printf("%s",(fptr+i)->data);



return 0;
}
