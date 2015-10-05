#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int size[100000],i,n;
	size[0]=1;
	size[1]=2;
	for(i=2;i<=43;i++){
		size[i]=size[i-1]+size[i-2]+1;
		//printf("%d\n",size[i]);
	}
	while(~scanf("%d",&n)&&n)
	{
		for(i=0;i<=43;i++)
			if(n<size[i]){
				printf("%d\n",i-1);
				break;
			}
	}
 return 0;
}

