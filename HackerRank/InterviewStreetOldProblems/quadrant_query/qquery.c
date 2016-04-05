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
	int *array=(int*)malloc(n*sizeof(int));

	int countone, counttwo, countthree, countfour;
	for(i=0;i<n;i++)
	{
		scanf("%d%d", &x, &y);
		if(x>0 && y>0)
			array[i]=1;
		else if(x<0 && y>0)
			array[i]=2;
		else if(x<0 && y<0)
			array[i]=3;
		else if(x>0 && y<0)
			array[i]=0;
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
				if(array[l]==1)	countone++;
				else if(array[l]==2) counttwo++;
				else if(array[l]==3) countthree++;
				else if(array[l]==0) countfour++;
			}
			printf("%d %d %d %d\n", countone, counttwo, countthree, countfour);
		}
		else if(query=='X')
			for(l=j-1;l<=k-1;l++)
				array[l]=(5-array[l])%4;
		else if(query=='Y')
			for(l=j-1;l<=k-1;l++)
				array[l]=(7-array[l])%4;
	}
	return 0;
}
