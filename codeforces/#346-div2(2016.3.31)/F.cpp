#include<bits/stdc++.h>
using namespace std;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
struct node{
	int v,x,y;
}b[1000010];
int n,m,a[1010][1010],fa[1000010],size[1000010]={0},num,c[1010][1010],vv;
long long k;

int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

void unio(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(size[fx]<size[fy]) swap(fx,fy);
	if(fx==fy) return;
	fa[fy]=fx;
	size[fx]+=size[fy];
}

bool cmp(const node& x,const node& y)
{
	return x.v>y.v;
}

void DFS(int x,int y)
{
	int i;
	if(c[x][y]) return;
	if(num){
		c[x][y]=vv;
		num--;
	}
	else return;
	for(i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m) continue;
		if(a[nx][ny]<vv) continue;
		DFS(nx,ny);
	}
}
int main()
{
    int i,j,cnt=0;
	memset(c,0,sizeof(c));
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			++cnt;
			b[cnt].x=i;
			b[cnt].y=j;
			b[cnt].v=a[i][j];
		}
	sort(b+1,b+cnt+1,cmp);
	for(i=1;i<=cnt;i++){
		fa[i]=i;
		size[i]=1;
	}
	for(i=1;i<=cnt;i++){
		int p=(b[i].x-1)*m+b[i].y;
		for(j=0;j<4;j++){
			int nx=b[i].x+dx[j];
			int ny=b[i].y+dy[j];
			if(nx<1||nx>n||ny<1||ny>m) continue;
			if(a[nx][ny]<b[i].v) continue;
			unio(p,(nx-1)*m+ny);
		}
		if(k%b[i].v==0&&size[find(p)]>=k/b[i].v)
			break;
	}
	if(i>cnt){
		printf("NO\n");
		return 0;
	}
	vv=b[i].v;
	num=k/b[i].v;
	DFS(b[i].x,b[i].y);
	printf("YES\n");
	for(i=1;i<=n;i++){
		for(j=1;j<m;j++){
			printf("%d ",c[i][j]);
		}
		printf("%d\n",c[i][j]);
	}
 return 0;
}

