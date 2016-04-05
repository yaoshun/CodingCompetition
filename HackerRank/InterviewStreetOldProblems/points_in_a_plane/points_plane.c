#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,k;
	int tests;	//number of tests
	int n;		//number of points
	scanf("%d", &tests);
	int *x, *y;
	
	for(i=0;i<tests;i++)
	{
		scanf("%d", n);
		x=(int*)malloc(n*sizeof(int));
		y=(int*)malloc(n*sizeof(int));
		for(j=0;j<n;j++)
			scanf("%d%d",x+j,y+j);
		
	}
}
