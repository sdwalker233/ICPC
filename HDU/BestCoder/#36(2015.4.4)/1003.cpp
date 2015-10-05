#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	int num,pos;
}a[50001];
int n,m,b[50001],map[50001],t[50001],ans[50001],c;

 bool cmp(node x,node y)
 {
 	return x.num<y.num;
 }

 void run()
 {
 	int i,x,p;
 	memset(t,0,sizeof(t));
 	c=0;
 	a[0].num=-1;
 	for(i=1;i<=n;i++){
 		scanf("%d",&a[i].num);
 		if(a[i].num==a[i-1].num){
 			n--;
 			i--;
 			continue;
 		}
 		b[i]=a[i].num;
 		a[i].pos=i;
 	}
 	sort(a+1,a+n+1,cmp);
 	
 	for(i=1;i<=n;i++){
 		if(a[i].num!=a[i-1].num){
 			c++;
 			map[c]=a[i].num;
 		}
 		b[a[i].pos]=c;
 	}
 	b[0]=b[n+1]=0;
 	for(i=1;i<=n;i++){
 		if(b[i-1]<b[i]&&b[i]>b[i+1]) t[b[i]]--;
 		if(b[i-1]>b[i]&&b[i]<b[i+1]) t[b[i]]++;
 	}
 	ans[0]=1;
 	for(i=1;i<=c;i++){
 		ans[i]=ans[i-1]+t[i];
 	}
 	for(i=1;i<=m;i++){
 		scanf("%d",&x);
 		p=upper_bound(map+1,map+c+1,x)-map-1;
 		printf("%d\n",ans[p]);
 	}
 }

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	while(~scanf("%d%d",&n,&m))
		run();
 return 0;
}

