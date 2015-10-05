#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int t,i,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=sqrt((double)n);i;i--){
			if(n%i==0){
				printf("%d\n",(n/i+i)*2);
				break;
			}
		}
	}
 return 0;
}

