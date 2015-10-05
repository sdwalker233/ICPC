#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,n,num,ans[21];
	long long a[21]={1,1},m;
	bool use[21];
	for(i=2;i<=20;i++){
		a[i]=i*(a[i-1]+1);
		//printf("%I64d\n",a[i]);
	}
	while(scanf("%d%I64d",&n,&m)!=EOF){
		memset(use,0,sizeof(use));
		for(i=1;i<=n;i++){
			if(m==0) break;
			//printf("%d\n",m);
			num=(int)((m-1)/(a[n-i]+1)+1);
			m=(m-1)%(a[n-i]+1);
			for(j=1;j<=n;j++){
				if(use[j]==0) num--;
				if(num==0){
					use[j]=1;
					ans[i]=j;
					break;
				}
			}
		}
		for(j=1;j<i-1;j++)
			printf("%d ",ans[j]);
		printf("%d\n",ans[j]);
	}
 return 0;
}

