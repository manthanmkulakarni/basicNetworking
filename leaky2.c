#include<stdio.h>
#include<stdlib.h>

int main(){
int bucket,s,rem,rate,n,data[100];

printf("Enter the bucket size\n");
scanf("%d",&s);

printf("Enter the rate\n");
scanf("%d",&rate);
rem=s;
bucket=0;
printf("Enter the n\n");
scanf("%d",&n);

for(int i=0;i<n;i++){
scanf("%d",&data[i]);

}
for(int i=0;i<n;i++){
if(data[i]>rem){
printf("Over flow\n");
return 0;
}
rem=rem-data[i];
bucket+=data[i];

if(bucket<rate){
printf("%d sent\n",bucket);
bucket=0;
rem=s;
}
else{
printf("%d sent\n",rate);
bucket=bucket-rate;
rem+=rate;
}
}
return 0;
}
