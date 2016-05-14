#include <bits/stdc++.h>
using namespace std;
long long c[500010],b[500010];

int main()
{
	int i;
	int n,k;
	long long sum=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%I64d",&c[i]);
		sum+=c[i];
	}
	long long ave=sum/n,re=sum%n;
	long long op=0;
	sort(c+1,c+n+1,greater<long long>());
	for(i=1;i<=n;i++){
		if(i<=re) b[i]=1;
		else b[i]=0;
		if(c[i]-ave-b[i]>0) op+=c[i]-ave-b[i];
	}
	if(op<=k){
		if(re) printf("1\n");
		else printf("0\n");
		return 0;
	}
	long long mx,mn;
	long long kk=k;
	for(i=1;i<=n;i++){
		long long nxt=max(c[i+1],ave+b[i+1]);
		long long now=max(c[i],ave+b[i]);
		if(nxt==ave){
			if(i*(now-ave-1)+i-re<kk){
				kk-=i*(now-ave-1)+i-re;
			}
			else{
				mx=max(now-kk/i,ave+b[1]);
				break;
			}
			continue;
		}
		if(i*(now-nxt)<kk){
			kk-=i*(now-nxt);
		}
		else {
			mx=now-kk/i;
			break;
		}
	}
	kk=k;
	for(i=n;i>=1;i--){
		long long nxt=min(c[i-1],ave+b[i-1]);
		long long now=min(c[i],ave+b[i]);
		if(nxt==ave+1){
			if((n-i+1)*(ave-now)+re-i+1<kk){
				kk-=(n-i+1)*(ave-now)+re-i+1;
			}
			else{
				mn=min(now+kk/(n-i+1),ave);
				break;
			}
			continue;
		}
		if((n-i+1)*(nxt-now)<kk){
			kk-=(n-i+1)*(nxt-now);
		}
		else {
			mn=now+kk/(n-i+1);
			break;
		}
	}
	cout<<mx-mn<<endl;
 return 0;
}

