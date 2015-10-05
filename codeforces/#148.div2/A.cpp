#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int y,n,k,s;
	bool ok=0;
	scanf("%d%d%d",&y,&k,&n);
	for(s=k;s<=n;s+=k){
		if(s-y>0){
			printf("%d ",s-y);
			ok=1;
		}
	}
	if(ok==0) printf("-1");
 return 0;
}

