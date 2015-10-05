#include<stdio.h>
#include<algorithm>
#define MAX_INT 0x7fffffff
using namespace std;


int main()
{
	long long a[110];
	int n,i,l,r,count,t=0;
	while(scanf("%d",&n)!=EOF){
		printf("Case #%d: ",++t);
		for(i=1;i<=n;i++)
			scanf("%I64d",&a[i]);
		sort(a+1,a+n+1);
		if(a[1]==a[n]){
			printf("-1\n");
			continue;
		}
		a[0]=a[n];a[n+1]=a[1];count=0;
		for(i=1;i<=n;i++){
			l=r=i;
			while(a[--l]==a[i]);
			while(a[++r]==a[i]);
			if((a[l]+a[i])%MAX_INT==a[r]) count++;
		}
		printf("%d\n",count);
	}
 return 0;
}

