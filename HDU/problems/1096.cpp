#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n,x,t,sum;
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&x);
			sum+=x;
		}
		printf("%d\n",sum);
		if(t) printf("\n");
	}
 return 0;
}

