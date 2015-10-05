#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
using namespace std;
int a[110][110];
int t[110];

int main()
{
	int n,m,i,j,num=0,p;
	bool ok;
	while(~scanf("%d%d",&n,&m)){
		num=0;ok=1;
		for(i=1;i<=m;i++){
			scanf("%d",&a[i][1]);
			if(a[i][1]!=-1){
				for(j=2;j<=n;j++)
					scanf("%d",&a[i][j]);
				memset(t,0,sizeof(t));
				for(j=1;j<=n;j++){
					if(t[a[i][j]]==0) t[a[i][j]]=1;
					else ok=0;
				}
			}
			else num++;
		}
		if(ok==0){
			printf("0\n");
			continue;
		}
		if(num==0){
			for(i=1;i<=n;i++){
				p=a[m][i];
				for(j=m-1;j>=1;j--){
					p=a[j][p];
				}
				if(p!=i) break;
			}
			if(i>n) printf("1\n");
			else printf("0\n");
			continue;
		}
		long long int fact=1,ans=1;
		for(i=1;i<=n;i++)
			fact=(fact*i)%mod;
		for(i=1;i<num;i++)
			ans=(ans*fact)%mod;
		printf("%lld\n",ans);
	}
 return 0;
}

