#include<stdio.h>
#include<stdlib.h>
void quicksort(int* array, int a, int b)
{
	//sort from index a to b
	//
	int i, temp;
	int leftcount=0;
	if(a>=b) return;
	for(i=a;i<b;i++)
	{
		if(array[i]<array[b])
		{
			temp=array[i];
			array[i]=array[a+leftcount];
			array[a+leftcount]=temp;
			leftcount++;
		}
	}
	temp=array[b];
	array[b]=array[a+leftcount];
	array[a+leftcount]=temp;
	quicksort(array, a, a+leftcount-1);
	quicksort(array, a+leftcount+1, b);
	return;
}

int main()
{
	int i,j;
	unsigned int n, k;
	int *array;
	scanf("%d%d", &n, &k);
	array=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d", &array[i]);

	//quicksort
	quicksort(array, 0, n-1);

	int count=0;
	i=j=0;
	while(j<=(n-1) && i<=(n-1))
	{
		if(array[j]-array[i]<k)
			j++;
		else if(array[j]-array[i]==k)
		{
			count++;
			j++;
		}
		else
		{
			i++;
		}
	}
	printf("%d\n", count);

	free(array);
	return 0;
}
