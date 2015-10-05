#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,i,a[100010],sum=0,left[100010]={0},right[100010]={0};
	scanf("%d",&n);
	a[0]=-1;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(a[n]||(sum==n-2&&!a[n]&&!a[n-1])){
		printf("NO\n");
		return 0;
	}
	if(n>1&&a[n-1]==0){
		if(n>2&&a[n-2]==0)
			left[n-3]=right[n-1]=1;
		else{
			for(i=n-2;i>=1;i--)
				if(a[i]==0) break;
			left[i-1]=left[i]=1;
			right[n-1]=2;
		}
	}
	printf("YES\n");
	for(i=1;i<n;i++){
		while(left[i-1]--) printf("(");
		printf("%d",a[i]);
		while(right[i]--) printf(")");
		printf("->");
	}
	printf("%d",a[n]);
 return 0;
}
