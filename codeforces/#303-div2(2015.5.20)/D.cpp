#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n,i,cnt=0;
	long long t[100010],assum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%I64d",&t[i]);
	sort(t+1,t+n+1);
	for(i=1;i<=n;i++){
		if(t[i]>=assum){
			assum+=t[i];
			cnt++;
		}
	}
	printf("%d\n",cnt);
 return 0;
}

