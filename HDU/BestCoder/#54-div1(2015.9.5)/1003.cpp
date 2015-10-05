#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
bool ok[1000010];
int n;


void fuck()
{
	int i,j,ans=0;
	memset(ok,0,sizeof(ok));
	scanf("%d",&n);
	n++;
	for(i=2;i<=n;i++){
		if(!ok[i]&&n%i==0){
			for(j=i;j<=n;j+=i)
				ok[j]=1;
		}
	}
	for(i=1;i<=n;i++)
		if(!ok[i]) ans++;
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}



