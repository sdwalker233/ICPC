#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int x[2010],y[2010];
int h,w,n;

int main()
{
	int i,j,p1[100010]={0},p2[100010],p3[100010]={0},last=0;
	scanf("%d%d%d",&h,&w,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		p3[x[i]]=1;
	}
	for(i=1;i<=h;i++){
		if(p3[i]){
			p3[i]=i-last;
			last=i;
		}
	}
	for(i=1;i<=h;i++){
		memset(p2,0,sizeof(p2));
		if(p3[i]||i=1){
			for(j=1;j<=n;j++){
				//printf(" %d %d %d\n",i,x[j],y[j]);
				if(x[j]==i){
					p2[y[j]]=-1;
					//printf("%d %d\n",x[j],y[j]);
				}
			}
			if(i==1){
				p1[1]=0;
				for(j=2;j<=w;j++){
					if(p2[j]==-1) p1[j]=0;
					else p1[j]=1;
				}
				continue;
			}
			if(p2[1]==-1) p1[1]=0;
				else p1[1]=1;
			for(j=2;j<=w;j++){
				if(p2[j]==-1) p1[j]=0;
				else p1[j]=(p1[j]+p1[j-1])%MOD;
			}
		}
		/*for(j=1;j<=w;j++)
			printf("%d ",p1[j]);
		printf("\n");*/
	}
	printf("%d\n",p1[w]);
 return 0;
}

