#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100010
#define Key_Value ch[ch[root][1]][0]
using namespace std;
struct node{
	int h,k;
}a[MAXN];
int n,q[MAXN];
int tot,root,ch[MAXN][2],fa[MAXN],val[MAXN],size[MAXN],ans[MAXN],cnt;

void travel(int x)
{
	if(!x) return;
	travel(ch[x][0]);
	if(val[x]!=-1) ans[++cnt]=val[x];
	travel(ch[x][1]);
}

bool cmp(const node& x,const node& y)
{
	return x.h<y.h;
}

void PushUp(int rt)
{
	size[rt]=size[ch[rt][0]]+size[ch[rt][1]]+1;
}

void Rotate(int rt,int kind)
{
	int y=fa[rt];
	ch[y][!kind]=ch[rt][kind];
	fa[ch[rt][kind]]=y;
	if(fa[y]) ch[fa[y]][ch[fa[y]][1]==y]=rt;
	fa[rt]=fa[y];
	ch[rt][kind]=y;
	fa[y]=rt;
	PushUp(y);
}

void Splay(int rt,int goal)
{
	while(fa[rt]!=goal){
		if(fa[fa[rt]]==goal){
			Rotate(rt,ch[fa[rt]][0]==rt);
		}
		else{
			int y=fa[rt],kind=(ch[fa[y]][0]==y);
			if(ch[y][kind]==rt){
				Rotate(rt,!kind);
				Rotate(rt,kind);
			}
			else{
				Rotate(y,kind);
				Rotate(rt,kind);
			}
		}
	}
	PushUp(rt);
	if(goal==0) root=rt;
}

void NewNode(int v,int pre,int &rt)
{
	rt=++tot;
	fa[rt]=pre;
	val[rt]=v;
	ch[rt][0]=ch[rt][1]=0;
	size[rt]=1;
}

void init()
{
	tot=root=cnt=0;
	ch[root][0]=ch[root][1]=fa[root]=val[root]=size[root]=0;
	NewNode(-1,0,root);
	NewNode(-1,root,ch[root][1]);
	PushUp(ch[root][1]);
	PushUp(root);
}

int Find_Min(int rt)
{
	if(!ch[rt][0]) return rt;
	else return Find_Min(ch[rt][0]);
}

int Find_Kth(int k,int rt)
{
	int t=size[ch[rt][0]]+1;
	if(t==k) return rt;
	if(k<t) return Find_Kth(k,ch[rt][0]);
	else return Find_Kth(k-t,ch[rt][1]);
}

void fuck()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].h,&a[i].k);
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++){
		a[i].k=min(a[i].k,n-i-a[i].k);
		if(a[i].k<0){
			printf("impossible\n");
			return;
		}
	}
	init();
	for(i=n;i>=1;i--){
		Splay(Find_Kth(a[i].k+1,root),0);
		Splay(Find_Kth(a[i].k+2,root),root);
		NewNode(a[i].h,ch[root][1],Key_Value);
		PushUp(ch[root][1]);
		PushUp(root);
		
	}
	travel(root);
	//debug();
	for(i=1;i<n;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}

