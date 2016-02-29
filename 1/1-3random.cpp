#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define random(x) (rand()%x)
#define N 993
#define M 993

int main(){
	FILE *fp;
	if((fp=fopen("1-3random.txt","w"))==NULL) 
    {
        printf("not open");
        exit(0);
    }
	srand((int)time(0));
	int start=clock();
	
	for(int i=0;i<N;i++)
		fprintf(fp,"%d ",random(M));
		
	int end=clock();
	printf("time:%dms",(end-start)*1000/CLOCKS_PER_SEC);	
	
	fclose(fp);
}
