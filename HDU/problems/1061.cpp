#include<stdio.h>
int a[10][10]={
	{0},
	{1},
	{2,4,8,6},
	{3,9,7,1},
	{4,6},
	{5},
	{6},
	{7,9,3,1},
	{8,4,2,6},
	{9,1}};
int loop[10]={0,1,4,4,2,1,1,4,4,2};

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n%10==0) printf("0\n");
		else printf("%d\n",a[n%10][(n-1)%loop[n%10]]);
	}
 return 0;
}

