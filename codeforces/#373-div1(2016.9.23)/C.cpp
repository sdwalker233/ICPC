#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;
const int mod=1e9+7;
struct mat{
	long long m[3][3];
	mat(){
		memset(m,0,sizeof(m));
	}
	friend bool operator==(const mat& x,const mat& y){
		if(x.m[1][1]==y.m[1][1]&&x.m[2][1]==y.m[2][1]&&x.m[1][2]==y.m[1][2]&&x.m[2][2]==y.m[2][2]) return 1;
		else return 0;
	}
}E,A;
struct SegTree{
	int l,r;
	long long x1,x2;
	mat m;
}tree[MAXN<<2];
int n,m,size;
int a[MAXN];

mat mul(mat a,mat b){
    mat tmp;
    int i,j,k;
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            for(k=1;k<=size;k++){
                tmp.m[i][j]=(tmp.m[i][j]+(a.m[i][k]*b.m[k][j])%mod)%mod;
            }
        }
    }
    return tmp;
}

mat QP(mat a,long long n){
    mat ans=E,tmp;
    memcpy(tmp.m,a.m,sizeof(tmp.m));
    while(n){
        if(n&1) ans=mul(ans,tmp);
        n>>=1;
        tmp=mul(tmp,tmp);
    }
    return ans;
}

void PushDown(int rt)
{
	if(!(tree[rt].m==E)){
		tree[rt<<1].m=mul(tree[rt<<1].m,tree[rt].m);
		tree[rt<<1|1].m=mul(tree[rt<<1|1].m,tree[rt].m);
		tree[rt].m=E;
	}
}

void PushUp(int rt)
{
	tree[rt].x1=(
		tree[rt<<1].x1*tree[rt<<1].m.m[1][1]+
		tree[rt<<1].x2*tree[rt<<1].m.m[1][2]+
		tree[rt<<1|1].x1*tree[rt<<1|1].m.m[1][1]+
		tree[rt<<1|1].x2*tree[rt<<1|1].m.m[1][2]
		)%mod;
	tree[rt].x2=(
		tree[rt<<1].x1*tree[rt<<1].m.m[2][1]+
		tree[rt<<1].x2*tree[rt<<1].m.m[2][2]+
		tree[rt<<1|1].x1*tree[rt<<1|1].m.m[2][1]+
		tree[rt<<1|1].x2*tree[rt<<1|1].m.m[2][2]
		)%mod;
}

void t_build(int l,int r,int rt)
{
	int m=(l+r)>>1;
	tree[rt].l=l;tree[rt].r=r;
	tree[rt].m=E;
	if(l==r){
		tree[rt].m=QP(A,a[l]-1);
		tree[rt].x1=1;
		tree[rt].x2=0;
		return;
	}
	t_build(l,m,rt<<1);
	t_build(m+1,r,rt<<1|1);
	PushUp(rt);
}

void t_add(mat v,int l,int r,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(tree[rt].l==l&&tree[rt].r==r){
		tree[rt].m=mul(tree[rt].m,v);
		return;
	}
	PushDown(rt);
	if(m>=r) t_add(v,l,r,rt<<1);
	else if(m<l) t_add(v,l,r,rt<<1|1);
	else{
		t_add(v,l,m,rt<<1);
		t_add(v,m+1,r,rt<<1|1);
	}
	PushUp(rt);
}

long long t_query(int l,int r,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	printf(" %d %d %d\n",rt,tree[rt].l,tree[rt].r);
	if(tree[rt].l==l&&tree[rt].r==r){
		return (
			tree[rt].x1*tree[rt].m.m[1][1]+
			tree[rt].x2*tree[rt].m.m[1][2]
			   )%mod;
	}
	if(m>=r) return t_query(l,r,rt<<1);
	if(m<l) return t_query(l,r,rt<<1|1);
	return (t_query(l,m,rt<<1)+t_query(m+1,r,rt<<1|1))%mod;
}

int main()
{
	int i,op,l,r,x;
	E.m[1][1]=E.m[2][2]=1;
	A.m[1][1]=A.m[1][2]=A.m[2][2]=1;
	size=2;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	t_build(1,n,1);
	while(m-->0){
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			scanf("%d",&x);
			t_add(QP(A,x),l,r,1);
		}
		else{
			printf("%lld\n",t_query(l,r,1));
		}
	}
 return 0;
}

