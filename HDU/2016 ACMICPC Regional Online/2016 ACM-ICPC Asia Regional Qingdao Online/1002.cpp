#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double sum[1000010];
char s[10000];

int main()
{
	int i;
	for(i=1;i<=1000000;i++){
		sum[i]=sum[i-1]+1.0/i/i;
	}
	int t;
	long long n;
	while(~scanf("%s",s+1)){
		int l=strlen(s+1);
		if(l>8) n=1000000;
		else{
			n=0;
			for(i=1;i<=l;i++){
				n=n*10+s[i]-'0';
			}
		}
		n=min(n,1000000ll);
		printf("%.5f\n",sum[n]);
	}
 return 0;
}

