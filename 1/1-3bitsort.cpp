#include <stdio.h>
#include <stdlib.h>

#define BitsPerWord 32
#define Shift 5
#define Mask 0x1F
#define N 1000

int a[1+N/BitsPerWord];

void set(int i){
	a[i>>Shift] |= (1<<(i&Mask));
}
void clr(int i){
	a[i>>Shift] &= ~(1<<(i&Mask));
}
int test(int i){
	return a[i>>Shift] & (1<<(i&Mask));
}

int main(){
	FILE *fp1,*fp2;
	if((fp1=fopen("1-3random.txt","r"))==NULL)
	{
		printf("not open\n");
		exit(0);
	}
	if((fp2=fopen("1-3sortres.txt","w"))==NULL)
	{
		printf("not open\n");
		exit(0);
	}
	for(int i=0;i<N;i++)
		clr(i);
	int temp,num1=0,num2=0;
	while((fscanf(fp1,"%d",&temp))!=EOF)
		set(temp),num1++;
	for(int i=0;i<N;i++)
		if(test(i))
			fprintf(fp2,"%d ",i),num2++;
			printf("%d %d",num1,num2);
	return 0;		
}
