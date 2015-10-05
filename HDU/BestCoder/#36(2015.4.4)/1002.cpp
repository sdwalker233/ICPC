#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,a[1000001],map[1000001],t[1000001],c;

 int b_search(int x,int l,int r)
 {
 	int m=(l+r)>>1;
 	if(l==r) return l;
 	if(map[m]>=x) return b_search(x,l,m);
 	else return b_search(x,m+1,r);
 }

 void run()
 {
 	int i,x,p;
 	memset(t,0,sizeof(t));
 	c=0;
 	for(i=1;i<=n;i++)
 		scanf("%d",&a[i]);
 	sort(a+1,a+n+1);
 	a[0]=0;
 	for(i=1;i<=n;i++){
 		if(a[i]!=a[i-1]){
 			c++;
 			map[c]=a[i];
 		}
 		t[c]++;
 	}
 	for(i=1;i<=m;i++){
 		scanf("%d",&x);
 		p=b_search(x,1,c);
 		printf("%d\n",t[p]);
 		t[p]=0;
 	}
 }

int main()
{
	while(~scanf("%d%d",&n,&m))
		run();
 return 0;
}

