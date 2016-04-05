#include<stdio.h>
#include<string.h>
//this problem is very interesting because you need to prove from math first to find the essence of the problem. 
//theory 1: the final reduction must be of only one characters. 
//theory 2: if orginal string is not pure one character, it must be reduced to 1 or 2. 
//proof: if not, assume reduced to 3. then you could think about the last step you do, repalce one charactre with other two characters. Immediately you would find a better way to solve the problem. 
//theory 3: any string that have a result of 2 could only come to the stage of 3that 3 distinct characters are there. 
//realizing that string order is not a issue while string character number is a issue, then try to find the invariable among changes. trace the number of 'a's, 'b's, 'c's

//num(a)+num(b), num(b)+num(c), num(a)+num(c), these three numbers are interesting. if it all even number. 
int main()
{
	char str[101];
	int i,j;
	int length;
	int tests;
	int counta, countb, countc, sumab, sumbc, sumac;

	scanf("%d", &tests);
	for(i=0;i<tests;i++)
	{
		scanf("%s", str);
		length=strlen(str);
		counta=countb=countc=0;
		for(j=0;j<length;j++)
		{
			if(str[j]=='a') counta++;
			else if(str[j]=='b') countb++;
			else if(str[j]=='c') countc++;
		}
		if(counta==0 && countb==0)
		{
			printf("%d\n",countc);
			break;
		}
		if(countb==0 && countc==0)
		{
			printf("%d\n",counta);
			break;
		}
		if(counta==0 && countc==0)
		{
			printf("%d\n",countb);
			break;
		}
		sumab=counta+countb;
		sumac=counta+countc;
		sumbc=countb+countc;
		if((sumab%2)==1 || (sumac%2)==1)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}
