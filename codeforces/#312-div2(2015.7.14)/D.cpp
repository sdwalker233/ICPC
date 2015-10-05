#include<bits/stdc++.h>
using namespace std;
map<long long,int> f;
set<long long> s;
int h,q;
long long num[200010];
int pos[200010];
struct node1{
	long long l,r;
}a[200010];
struct node2{
	int l,r,sum;
}tree[1200000];

void t_build(int l,int r,int rt)
{
	int m=(l+r)>>1;
	tree[rt].l=l;tree[rt].r=r;tree[rt].sum=0;
	if(l==r){
		pos[l]=rt;
		return;
	}
	t_build(l,m,rt<<1);
	t_build(m+1,r,rt<<1|1);
}

void PushDown(int rt)
{
	if(tree[rt].sum){
		tree[rt<<1].sum+=tree[rt].sum;
		tree[rt<<1|1].sum+=tree[rt].sum;
		tree[rt].sum=0;
	}
}

void t_add(int l,int r,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(tree[rt].l==l&&tree[rt].r==r){
		tree[rt].sum++;
		return;
	}
	PushDown(rt);
	if(r<=m) t_add(l,r,rt<<1);
	else if(l>m) t_add(l,r,rt<<1|1);
	else{
		t_add(l,m,rt<<1);
		t_add(m+1,r,rt<<1|1);
	}
}

void t_go(int rt)
{
	if(tree[rt].l==tree[rt].r) return;
	PushDown(rt);
	t_go(rt<<1);
	t_go(rt<<1|1);
}

int main()
{
	int i,tot=0,j,ans,tmp=0;
	long long p,l,r,ll,rr;
	scanf("%d%d",&h,&q);
	ll=(1ll<<(h-1));rr=(1ll<<h)-1;
	//cout<<ll<<" "<<rr<<endl;
	for(i=1;i<=q;i++){
		//cin>>p>>l>>r>>ans;
		scanf("%I64d%I64d%I64d%d",&p,&l,&r,&ans);
		l=(l<<(h-p));r=((r+1)<<(h-p))-1;
		if(ans) {++tot;a[tot].l=l;a[tot].r=r+1;}
		else {
			if(l>ll) {++tot;a[tot].l=ll;a[tot].r=l;}
			if(r<rr) {++tot;a[tot].l=r+1;a[tot].r=rr+1;}
		}
	}
	for(i=1;i<=tot;i++){
		s.insert(a[i].r);
		s.insert(a[i].l);
	}
	for(set<long long>::iterator it=s.begin();it!=s.end();it++){
		tmp++;
		f.insert(pair<long long,int>(*it,tmp));
		num[tmp]=*it;
	}
	if(s.size()==0){
		if(q==0){
			if(h==1) printf("1");
			else printf("Game cheated!\n");
		}
		else printf("Game cheated!\n");
		return 0;
	}
	t_build(1,s.size()-1,1);
	for(i=1;i<=tot;i++){
		//cout<<f[a[i].l]<<" "<<f[a[i].r]-1<<endl;
		t_add(f[a[i].l],f[a[i].r]-1,1);
	}
	t_go(1);
	int find=0;
	for(i=1;i<=s.size()-1;i++){
		if(tree[pos[i]].sum==q){
			p=i;
			find++;
		}
	}
	//if(q==27472) cout<<find<<endl;
	if(find>1) printf("Data not sufficient!\n");
	else if(find<1) printf("Game cheated!\n");
	else if(num[p+1]-num[p]==1) cout<<num[p]<<endl; 
	else printf("Data not sufficient!\n");
 return 0;
}

