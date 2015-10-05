#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct node{
	int x,y,z;
	node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
}b[100];
int n,p,ans,h[100];

 bool cmp(node x,node y){
 	return x.x>y.x;
 }

 void dfs(int x,int y,int z,int c)
 {
 	int i=c;
 	if(z>=h[c]) h[c]=z;
 	else return;
 	while(i<=p&&b[i].x>=x) i++;
 	for(i;i<=p;i++){
 		if(y>b[i].y) dfs(b[i].x,b[i].y,z+b[i].z,i+1);
 	}
 	if(z>ans) ans=z;
 }

 void run(){
 	int i,a[3];
 	p=-1;ans=0;
 	memset(h,0,sizeof(h));
 	for(i=1;i<=n;i++){
 		scanf("%d%d%d",&a[0],&a[1],&a[2]);
 		sort(a,a+3);
 		b[++p]=node(a[2],a[1],a[0]);
 		b[++p]=node(a[2],a[0],a[1]);
 		b[++p]=node(a[1],a[0],a[2]);
 	}
 	sort(b,b+p+1,cmp);
 	dfs(INF,INF,0,0);
 	printf("%d\n",ans);
 }

int main()
{
	int i=1;
	while(scanf("%d",&n)!=EOF&&n){
		printf("Case %d: maximum height = ",i++);
		run();
	}
 return 0;
}

