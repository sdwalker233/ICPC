#include<iostream>
#include<cstdio>
int n,w,h,a[200000],a1[200000],a2[200000];
struct node{
	int l,r,sum;
}tree[1000000],tree1[1000000],tree2[1000000];

 int min(int x,int y)
 {
 	return x<y?x:y;
 }

 int abs(int x)
 {
 	return x>0?x:-x;
 }

 void t_build(int l,int r,int rt,node tree[],int a[])
 {
 	int m=(l+r)>>1;
 	tree[rt].l=l;tree[rt].r=r;
 	if(l==r){
 		tree[rt].sum=a[l];
 		return;
 	}
 	t_build(l,m,rt<<1,tree,a);
 	t_build(m+1,r,rt<<1|1,tree,a);
 	tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
 }

 int t_query(int l,int r,int rt,node tree[])
 {
 	int m=(tree[rt].l+tree[rt].r)>>1;
 	if(l==tree[rt].l&&r==tree[rt].r) return tree[rt].sum;
 	if(m>=r) return t_query(l,r,rt<<1,tree);
 	if(m<l) return t_query(l,r,rt<<1|1,tree);
 	return t_query(l,m,rt<<1,tree)+t_query(m+1,r,rt<<1|1,tree);
 }

 void run()
 {
 	int i,j,t,p,ans=0x7fffffff;
	long long sum=0;
	for(i=1;i<=w;i++){
		a[i]=a[i+w+n]=h;
		a1[i]=a1[i+w+n]=h;
		a2[i]=a2[i+w+n]=0;
	}
		
 	for(i=w+1;i<=w+n;i++){
 		scanf("%d",&t);
 		sum+=t;
 		a[i]=h-t;
 		if(h>t){
 			a1[i]=h-t;
 			a2[i]=0;
 		}
 		else{
 			a1[i]=0;
 			a2[i]=t-h;
 		}
 	}
 	if(sum<(long long)w*h){
 		printf("-1\n");
 		return;
 	}
 	t_build(1,2*w+n-1,1,tree,a);
 	t_build(1,2*w+n-1,1,tree1,a1);
 	t_build(1,2*w+n-1,1,tree2,a2);
 	for(i=1;i<=w+n;i++){
 		t=t_query(i,i+w-1,1,tree);
 		if(t>0) p=t+t_query(i,i+w-1,1,tree2);
 		else p=-t+t_query(i,i+w-1,1,tree1);
 		ans=min(ans,p);
 		//printf(" %d\n",t_query(i,i+w-1,1));
 	}
 	printf("%d\n",ans);
 }

int main()
{
	while(~scanf("%d%d%d",&n,&w,&h))
		run();
 return 0;
}

