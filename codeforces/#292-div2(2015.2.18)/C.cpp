#include<stdio.h>

int main()
{
	int i,n,t2=0,t3=0,t5=0,t7=0;
	char s;
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++){
		s=getchar();
		switch(s){
			case('9'):t3+=2;
			case('8'):t2+=3;
			case('7'):t7++;
			case('6'):t2++;t3++;
			case('5'):t5++;
			case('4'):t2+=2;
			case('3'):t3++;
			case('2'):t2++;break;	
		}
	}
	for(i=1;i<=t7;i++)
		printf("7");
	t2-=4*t7;t3-=2*t7;t5-=t7;
	for(i=1;i<=t5;i++)
		printf("5");
	t2-=3*t5;t3-=t5;
	for(i=1;i<=t3;i++)
		printf("3");
	t2-=t3;
	for(i=1;i<=t2;i++)
		printf("2");
 return 0;
}

