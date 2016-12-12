#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
int n,s;
int a[MAXN],b[MAXN],c[MAXN],e[MAXN];

int main()
{
	int i,f=0;
	scanf("%d%d",&n,&s);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	if(n==1){
		printf("0\n");
		return 0;
	}
	if(a[s]){
		b[a[s]]--;
		b[0]++;
		a[s]=0;
		f++;
	}
	if(b[0]) c[n]=b[0]-1;
	for(i=n-1;i>=0;i--){
		c[i]=c[i+1]+b[i];
	}
	for(i=0;i<=n-1;i++){
		if(i) e[i]=e[i-1];
		if(b[i]==0) e[i]++;
	}
	int ans=n;
	for(i=1;i<n;i++){
		int tmp=max(e[i],c[i+1]);
		ans=min(ans,tmp);
	}
	cout<<ans+f<<endl;
 return 0;
}

