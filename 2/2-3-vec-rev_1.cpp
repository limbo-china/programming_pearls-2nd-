#include <stdio.h>
#include <time.h>
#define N 12
char a[N+1]="abcdefghijkl";

int gcd(int a,int b){
	int temp=a%b;
	while(temp){
		a=b;
		b=temp;
		temp=a%b;
	}
	return b;
}
int main()
{
	int i,k;
	scanf("%d",&i);
	int start=clock();
	for(int j=0;j<gcd(N,i);j++){
		char temp=a[j];
		k=j;
		while((k+i)%N!=j){
			a[k]=a[(k+i)%N];
			k=(k+i)%N;
		}
		a[k]=temp;	
	}
	int end=clock();
	puts(a);
	printf("time:%dms",(end-start)*1000/CLOCKS_PER_SEC);
}
