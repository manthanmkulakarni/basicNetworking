#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int getnum(char *str){
int temp=0;
for(int i=0;i<8;i++){
	if(str[7-i]=='0')temp+=pow(2,i);
}
return temp;
}

char *getbinary(int num){
char *str;
int i=0;
str=(char*)malloc(sizeof(char)*8);
str="00000000";

while(num>1){
if(num%2==1)str[7-i]='1';
else str[7-i]='0';
num=num/2;
i++;
}
str[i]='1';
return str;
}

int main(){
char num1[8],num2[8];
scanf("%s",num1);
scanf("%s",num2);

int a[3],b[4],n=255;
a[0]=getnum(num1);
a[1]=getnum(num2);
a[2]=(n-a[0])+(n-a[1]);

printf("Check sum %d\n",a[2]);

b[0]=a[0];
b[1]=a[1];
b[2]=a[2];
b[3]=(n-b[0])+(n-b[1])+(2*n-b[2]);
b[3]=2*n-b[3];

printf("%d\n",b[3]);
return 0;
}
