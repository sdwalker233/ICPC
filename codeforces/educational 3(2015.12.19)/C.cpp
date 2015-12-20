#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];

int abs(int x)
{
	return x>0?x:-x;
}

int main()
{
	int n,i,j,sum=0,aver,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	aver=sum/n;
	for(i=1;i<=n-sum%n;i++)
		b[i]=aver;
	for(i;i<=n;i++)
		b[i]=aver+1;
	for(i=1;i<=n;i++){
		cnt+=abs(a[i]-b[i]);
	}
	cout<<cnt/2;
 return 0;
}


