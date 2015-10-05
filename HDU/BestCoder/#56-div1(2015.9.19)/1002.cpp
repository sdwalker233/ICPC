#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 510
using namespace std;
int n,m,q,a[510][510];
//各位巨巨手下留情啊！！ 
struct Nodey
{
    int l,r;
    int v;
};
int locy[MAXN],locx[MAXN];
struct Nodex
{
    int l,r;
    Nodey sty[MAXN*4];
    void build(int i,int _l,int _r)
    {
        sty[i].l = _l;
        sty[i].r = _r;
        sty[i].v=0;
        if(_l == _r)
        {
        	//sty[i].v=a[_l][_r];
            locy[_l] = i;
            return;
        }
        int mid = (_l + _r)/2;
        build(i<<1,_l,mid);
        build((i<<1)|1,mid+1,_r);
        //sty[i].v=(sty[i<<1].v^sty[i<<1|1].v);
    }
    int query(int i,int _l,int _r)
    {
        if(sty[i].l == _l && sty[i].r == _r)
            return sty[i].v;
        int mid = (sty[i].l + sty[i].r)/2;
        if(_r <= mid)return query(i<<1,_l,_r);
        else if(_l > mid)return query((i<<1)|1,_l,_r);
        else return (query(i<<1,_l,mid)^query((i<<1)|1,mid+1,_r));
    }
}stx[MAXN*4];

void build(int i,int l,int r)
{
    stx[i].l = l;
    stx[i].r = r;
    stx[i].build(1,1,m);
    if(l == r)
    {
        locx[l] = i;
        return;
    }
    int mid = (l+r)/2;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
}

void Modify(int x,int y,int val)
{
    int tx = locx[x];
    int ty = locy[y];
    stx[tx].sty[ty].v = val;
    for(int i = tx;i;i >>= 1)
        for(int j = ty;j;j >>= 1)
        {
            if(i == tx && j == ty)continue;
            if(j == ty)
            {
                stx[i].sty[j].v = (stx[i<<1].sty[j].v^stx[(i<<1)|1].sty[j].v);
            }
            else
            {
                stx[i].sty[j].v = (stx[i].sty[j<<1].v^stx[i].sty[(j<<1)|1].v);
            }
        }
}

int query(int i,int x1,int x2,int y1,int y2)
{
    if(stx[i].l == x1 && stx[i].r == x2)
        return stx[i].query(1,y1,y2);
    int mid = (stx[i].l + stx[i].r)/2;
    if(x2 <= mid)return query(i<<1,x1,x2,y1,y2);
    else if(x1 > mid)return query((i<<1)|1,x1,x2,y1,y2);
    else return (query(i<<1,x1,mid,y1,y2)^query((i<<1)|1,mid+1,x2,y1,y2));
}


void fuck()
{
	int i,j,op,x1,y1,x2,y2,d;
	scanf("%d%d%d",&n,&m,&q);
	build(1,1,n);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			Modify(i,j,a[i][j]);
		}
	for(i=1;i<=q;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(query(1,x1,x2,y1,y2)==0) printf("No\n");
			else printf("Yes\n");
		}
		else{
			scanf("%d%d%d",&x1,&y1,&d);
			Modify(x1,y1,d);
		}
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}
