#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int getnum(char *str){
int temp=0;
for(int i=0;i<8;i++){
if(str[7-i]=='1')temp=temp+pow(2,i);

}
return temp;
}
int main(){
int ar[3],er,b[4];
int n=255;
char num1[8],num2[8];
printf("Enter the number\n");
scanf("%s",num1);
scanf("%s",num2);

ar[0]=getnum(num1);
ar[1]=getnum(num2);

ar[2]=(n-ar[0])+(n-ar[1]);

printf("Enter 1 to add error\n");
scanf("%d",&er);
if(er==1){
ar[1]=ar[1]+rand()%2;
ar[2]=ar[2]+rand()%2;

}

printf("Data received\n");
printf("%d %d checksum %d\n",ar[0],ar[1],ar[2]);

b[0]=n-ar[0];
b[1]=n-ar[1];
b[2]=2*n-ar[2]+1;
b[3]=b[0]+b[1]+b[2];

printf("%d\n",2*n-b[3]);
int res=2*n-b[3]+1;
res=res*(-1);

if(res==0)printf("No error\n");

else printf("Error %d\n",res);

return 0;

}
