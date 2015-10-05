#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int i,j,sum,n,x;
	while(~scanf("%d",&n)){
		sum=2*n;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				scanf("%d",&x);
				if(i!=j) sum+=x;
			}
		printf("%d\n",sum);
	}
 return 0;
}

