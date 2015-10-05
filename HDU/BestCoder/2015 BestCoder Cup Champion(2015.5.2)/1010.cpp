#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 1e9 
using namespace std;
int n,q;
struct node{
	int l,r,ans;
}b[1010];

 bool cmp(node x,node y)
 {
 	return x.ans>y.ans;
 }

 int gcd(int x,int y)
 {
 	if(!y) return x;
 	return gcd(y,x%y);
 }

 bool fuck()
 {
 	int i,j,x,y;
	long long a[1010]={0};
 	scanf("%d%d",&n,&q);
 	for(i=1;i<=q;i++)
 		scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].ans);
 	sort(b+1,b+q+1,cmp);
 	for(i=1;i<=q;i++){
 		y=0;
 		for(j=b[i].l;j<=b[i].r;j++){
 			if(!a[j]) a[j]=b[i].ans;
 			else{
 				x=gcd(b[i].ans,a[j]);
 				a[j]=(long long)a[j]/x*b[i].ans;
 				if(a[j]>MAXN) return 0;
 			}
 			y=gcd(a[j],y);
 		}
 		if(y!=b[i].ans) return 0;
 	}
 	for(i=1;i<n;i++){
 		printf("%I64d ",a[i]?a[i]:1);
 	}
 	printf("%I64d\n",a[i]?a[i]:1);
 	return 1;
 }

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
		if(!fuck()) printf("Stupid BrotherK!\n");
 return 0;
}

