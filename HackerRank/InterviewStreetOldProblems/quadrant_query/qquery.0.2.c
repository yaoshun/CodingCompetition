#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,k,l;
	int n;		//number of points
	int q;		//number of queries
	char query;

	scanf("%d",&n);
	int x, y;
	unsigned int *array=(unsigned int*)malloc(n*sizeof(unsigned int));

	int countone, counttwo, countthree, countfour;
	for(i=0;i<n;i++)
	{
		scanf("%d%d", &x, &y);
		array[i]=((x>>31)&1) | ((y>>30)&2);
	}
	scanf("%d", &q);
	for(i=0;i<q;i++)
	{
		query=getchar();
		while(query!='C'&&query!='X'&&query!='Y')
			query=getchar();
		scanf("%d%d", &j, &k);
		if(query=='C')
		{
			countone=counttwo=countthree=countfour=0;
			for(l=j-1;l<=k-1;l++)
			{
				if((array[l]^0)==0)	countone++;
				else if((array[l]^1)==0) counttwo++;
				else if((array[l]^3)==0) countthree++;
				else if((array[l]^2)==0) countfour++;
			}
			printf("%d %d %d %d\n", countone, counttwo, countthree, countfour);
		}
		else if(query=='X')
			for(l=j-1;l<=k-1;l++)
				array[l] ^= 2;
		else if(query=='Y')
			for(l=j-1;l<=k-1;l++)
				array[l] ^= 1;
	}
	return 0;
}
