#include<iostream>
#include<cstdio>
#define N 10000
using namespace std;
int n;

 void run()
 {
 	int i,j,a[10010],x,t,ans=0;
 	int p[10010]={0};
 	bool ok;
 	for(i=1;i<=n;i++)
 		scanf("%d",&a[i]);
 	for(i=n;i>=1;i--){
 		p[a[i]]=i;t=N+1;
 		for(j=a[i]*2;j<=N;j+=a[i]){
 			if(p[j]&&p[j]<t){
 				t=p[j];
 			}
 		}
 		if(t<=N) ans+=t;
 	}
 	printf("%d\n",ans);
 }

int main()
{
	while(~scanf("%d",&n))
		run();
 return 0;
}

