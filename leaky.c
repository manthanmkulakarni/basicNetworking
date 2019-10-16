#include<stdio.h>
#include<stdlib.h>

int main(){
int bsize=100,bucket[100],rem=100,frame,rate=5,ptrf=0,ptrb=0;
char c;
while(1){
	printf("Enter x to terminate else N: ");
	
	scanf("%c",&c);
	if(c=='x')return 0;

	else{
		printf("Enter the frame\n");
			scanf("%d",&frame);
			if(frame>rem){
				printf("Bucket over flow\n");
				return 0;
			}
			else{
				bucket[ptrb]=frame;
				rem=rem-frame;
			
				ptrb++;
			}
			//Removing the data at rate
			int temp=rate;
			while(ptrb!=ptrf&&temp!=0){
			
				if(bucket[ptrf]<temp){

					printf("Sent %d\n",bucket[ptrf]);
					rem=rem+bucket[ptrf];
					temp=temp-bucket[ptrf++];
				
				
				}
				else if(bucket[ptrf]==temp){
					printf("sent %d",temp);
					rem=rem+temp;
					temp=0;
					ptrf++;
			
				}
				else{
					printf("Sent %d\n",temp);
					rem=rem+temp;
					bucket[ptrf]=bucket[ptrf]-temp;
					temp=0;
				}

		}
	}	

}

return 0;
}
