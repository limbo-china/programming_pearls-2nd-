#include <stdio.h>
#define N 12
char c[N+1]="abcdefghijkl";

void reverse(int a,int b){
	int m,n;
	m=a,n=b;
	char temp;
	while(m <=(a+b)/2){
		temp=c[m];
		c[m]=c[n];
		c[n]=temp;
		m++,n--;
	}
}

int main()
{
	int i;
	scanf("%d",&i);
	reverse(0,i-1);
	reverse(i,N-1);
	reverse(0,N-1);
	puts(c);
}
