#include<stdio.h>
int n,a[500001],b[500001],count=0;

 int b_search(int b[],int l,int r,int x)
 {
 	int m=(l+r)>>1;
 	if(l==r) return l;
 	if(b[m+1]>x) return b_search(b,l,m,x);
 	if(b[m+1]<x) return b_search(b,m+1,r,x);
 }

 void run()
 {
 	int i,p,q,k;
 	for(i=1;i<=n;i++){
 		scanf("%d%d",&p,&q);
 		a[p]=q;
 	}
 	b[0]=0;
 	k=0;
 	for(i=1;i<=n;i++)
 		if(a[i]>b[k]) b[++k]=a[i];
 		else b[b_search(b,0,k,a[i])+1]=a[i];
 	printf("Case %d:\nMy king, at most %d road",++count,k);
 	if(k!=1) printf("s");
 	printf(" can be built.\n\n");
 }

int main()
{
	while(scanf("%d",&n)!=EOF)
		run();
 return 0;
}

