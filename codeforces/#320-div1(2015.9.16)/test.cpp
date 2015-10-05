#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;

int main()
{
	freopen("in.txt","w",stdout);
	srand(time(NULL));
	int i,n;
	n=10;
	printf("%d\n",n);
	for(i=1;i<=n;i++)
		printf("%d ",rand()%200-100);
	printf("\n");
 return 0;
}


