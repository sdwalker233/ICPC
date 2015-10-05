#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int i,n,a[1000010],t[1000010]={0},mx=-1,mxlen=-1,l=-1,r=1000001,num,first[1000010],last[1000010];

int main()
{
	memset(first,-1,sizeof(first));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		t[a[i]]++;
		if(first[a[i]]==-1) first[a[i]]=i;
		last[a[i]]=i;
	}
	for(i=1;i<=1000000;i++)
		mx=max(mx,t[i]);
	for(i=1;i<=1000000;i++){
		if(t[i]==mx){
			if(last[i]-first[i]<r-l){
				r=last[i];
				l=first[i];
			}
		}
	}
	printf("%d %d\n",l,r);
 return 0;
}

