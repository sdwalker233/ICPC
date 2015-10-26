#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[500010],b[500010],c[500010];
int n;

int main()
{
	int i,j,m=0,cnt=0;
	memset(b,-1,sizeof(b));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	b[++cnt]=0;
	a[0]=a[1];
	for(i=1;i<n;i++){
		if(a[i]==a[i+1]) b[++cnt]=i;
	}
	b[++cnt]=n;
	for(i=1;i<cnt;i++){
		m=max(m,(b[i+1]-b[i]-1)/2);
	}
	printf("%d\n",m);
	for(i=1;i<cnt;i++){
		if(a[b[i]]==a[b[i+1]]){
			for(j=b[i];j<b[i+1];j++)
				if(j) printf("%d ",a[b[i]]);
		}
		else{
			for(j=b[i];j<=(b[i]+b[i+1])/2;j++)
				if(j) printf("%d ",a[b[i]]);
			for(j;j<b[i+1];j++)
				if(j) printf("%d ",a[b[i+1]]);
		}
	}
	printf("%d\n",a[n]);
 return 0;
}