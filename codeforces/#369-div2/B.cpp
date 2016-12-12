#include <bits/stdc++.h>
using namespace std;
long long a[510][510];

int main()
{
	int n,i,j,px,py;
	long long ans=-1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%I64d",&a[i][j]);
			if(a[i][j]==0){
				px=i;py=j;
			}
		}
	if(n==1){
		printf("1\n");
		return 0;
	}
	int xx=1;
	long long sum=0,sum1;
	if(px==1) xx=2;
	for(i=1;i<=n;i++) sum+=a[xx][i];
	for(i=1;i<=n;i++){
		sum1=0;
		for(j=1;j<=n;j++)
			sum1+=a[i][j];
		if(i==px) ans=sum-sum1;
		else if(sum1!=sum){
			printf("-1\n");return 0;
		}
	}
	a[px][py]=ans;
	for(i=1;i<=n;i++){
		sum1=0;
		for(j=1;j<=n;j++)
			sum1+=a[j][i];
		if(sum1!=sum){
			printf("-1\n");return 0;
		}
	}
	sum1=0;
	for(i=1;i<=n;i++) sum1+=a[i][i];
	if(sum1!=sum){
		printf("-1\n");return 0;
	}
	sum1=0;
	for(i=1;i<=n;i++) sum1+=a[i][n-i+1];
	if(sum1!=sum){
		printf("-1\n");return 0;
	}
	if(ans<=0) ans=-1;
	cout<<ans<<endl;
 return 0;
}

