#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(~scanf("%d",&n)){
		int i;
		if(n==1||n%2==0){
			printf("2^? mod %d = 1\n",n);
			continue;
		}
		int tmp=1;
		for(i=1;i<=n;i++){
			tmp*=2;
			tmp%=n;
			if(tmp==1) break;
		}
		if(tmp==1) printf("2^%d mod %d = 1\n",i,n);
		else printf("2^? mod %d = 1\n",n);
	}
 return 0;
}

