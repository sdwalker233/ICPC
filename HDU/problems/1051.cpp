#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int l,w;
}a[5001];

 bool cmp(node x,node y){
 	if(x.l==y.l) return x.w<y.w;
 	return x.l<y.l;
 }

 void run()
 {
 	int n,i,j,ans=0,last,count;
 	bool visit[5001]={0};
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 		scanf("%d%d",&a[i].l,&a[i].w);
 	sort(a,a+n,cmp);
 	//for(i=0;i<n;i++)
 		//printf("%d %d\n",a[i].l,a[i].w);
 	for(i=0;i<n;i++){
 		if(visit[i]==1) continue;
 		last=a[i].w;
 		for(j=i;j<n;j++)
 			if(visit[j]==0&&a[j].w>=last){
 				visit[j]=1;
 				last=a[j].w;
 				//printf("%d\n",a[j].w);
 			}
 		ans++;
 	}
 	printf("%d\n",ans);
 }

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		run();
 return 0;
}

