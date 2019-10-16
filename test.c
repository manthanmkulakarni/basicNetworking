#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
char query[]="arp ";
char address[]="192.168.43.184";

system(strcat(query,address));
return 0;
}
