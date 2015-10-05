#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
struct node{
	char name[100];
	int d,c;
}h[16];
struct node2{
	int d,t,num;
	int sq[16];
	node2(){
		t=0x7fffffff;
	}
}dp[65536];

 bool cmp(node x,node y)
 {
 	return strcmp(x.name,y.name)<0;
 }

 void run()
 {
	 int n,i,j,dd,tt,p,b;
	 scanf("%d",&n);
	 for(i=1;i<=n;i++)
		 scanf("%s%d%d",h[i].name,&h[i].d,&h[i].c);
	 p=(1<<n);
	 sort(h+1,h+n+1,cmp);
	 dp[0].d=dp[0].t=dp[0].num=0;
	 for(i=0;i<p;i++)
		 for(j=1,b=1;j<=n;b<<=1,j++)
			 if((i|b)!=i){
				 dd=dp[i].d+h[j].c;
				 tt=dp[i].t;
				 if(dd>h[j].d) tt+=dd-h[j].d;
				 if(tt<dp[i|b].t){
					 dp[i|b].t=tt;
					 dp[i|b].d=dd;
					 dp[i|b].num=dp[i].num+1;
					 memcpy(dp[i|b].sq,dp[i].sq,sizeof(dp[i].sq));
					 dp[i|b].sq[dp[i|b].num]=j;
				 }
			}
	 for(i=1;i<=n;i++)
	 	//printf("%d\n",dp[p-1].sq[i]);
		printf("%s\n",h[dp[p-1].sq[i]].name);
 }

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		run();
 return 0;
}

