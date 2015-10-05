#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n,i,j,k,p,a[110],b[101];
	bool ok;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(k=1;k<=n;k++){
		memset(b,-1,sizeof(b));
		p=1;ok=1;
		for(i=1;i<=k;i++){
			if(b[i]==-1) b[i]=a[p];
			else if(b[i]==0){
				ok=0;
				break;
			}
			else b[i]=min(a[p],b[i]-1);
			//printf("%d\n",b[i]);
			p++;
			if(p>n) break;
			if(i==k) i=0;
		}
		if(ok==1){
			printf("%d\n",k);
			return 0;
		}
	}
 return 0;
}
