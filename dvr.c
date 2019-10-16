#include<stdio.h>
#include<stdlib.h>

struct Table{
int dest[10];
int d[10];
}table[10];

int main(){
int n,m[10][10],temp;
printf("Enter the value of n\n");
scanf("%d",&n);

printf("Enter the table\n");
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		scanf("%d",&m[i][j]);
		table[i].d[j]=m[i][j];
		table[i].dest[j]=j;
	}

}
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		printf("%d ",m[i][j]);

	}printf("\n");

}

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		for(int k=0;k<n;k++){
			temp=table[i].d[k]+table[k].d[j];
			if(table[i].d[j]>temp){
				table[i].d[j]=temp;
				table[i].dest[j]=k;
			}

		}

	}

}
for(int i=0;i<n;i++){
printf("table of %d\nTo d\n",i);
	for(int j=0;j<n;j++){
		
		printf("%d %d\n",j,table[i].d[j]);
		
		

	}

}

return 0;
}

