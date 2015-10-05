#include<stdio.h>

int main()
{
	int a[3],i;
	for(i=0;i<3;i++)
		scanf("%d",&a[i]);
	for(i=0;i<3;i++)
		if(a[i]<=168){
			printf("CRASH %d\n",a[i]);
			return 0;
			}
	printf("NO CRASH\n");
 return 0;
}

