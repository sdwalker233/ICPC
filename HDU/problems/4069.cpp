#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MaxN=800;
const int MaxM=400;
const int maxnode=3000;
const int v[5]={0,16,32,64,128},dx[]={0,-1,0,1,0},dy[]={0,0,1,0,-1};
int m[10][10][5],mark[10][10],ans[100];

void save();

struct DLX
{
	bool f;
	int n,m,size,cnt;
	int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
	int H[MaxN],S[MaxM];
	int ansd,ans[MaxN];
	void init(int _n,int _m)
	{
		cnt = 0;
		f = false;
		n = _n;
		m = _m;
		ansd=0;
		for(int i = 0;i <= m;i++)
		{
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i-1;
			R[i] = i+1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for(int i = 1;i <= n;i++)H[i] = -1;
	}
	void Link(int r,int c)
	{
		++S[Col[++size]=c];
		Row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if(H[r] < 0)H[r] = L[size] = R[size] = size;
		else
		{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c)
	{
		L[R[c]] = L[c]; R[L[c]] = R[c];
		for(int i = D[c];i != c;i = D[i])
			for(int j = R[i];j != i;j = R[j])
			{
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[Col[j]];
			}
	}
	void resume(int c)
	{
		for(int i = U[c];i != c;i = U[i])
			for(int j = L[i];j != i;j = L[j])
				++S[Col[U[D[j]]=D[U[j]]=j]];
		L[R[c]] = R[L[c]] = c;
	}
	void Dance(int d)
	{
		if(f) return;
		if(R[0] == 0)
		{
			save();
			++cnt;
			if(cnt>1) f=true;
			return;
		}
		int c = R[0];
		for(int i = R[0];i != 0;i = R[i])
			if(S[i] < S[c])
				c = i;
		remove(c);
		for(int i = D[c];i != c;i = D[i])
		{
			ans[d] = Row[i];ansd=d+1;
			for(int j = R[i];j != i;j = R[j])remove(Col[j]);
			Dance(d+1);
			if(f) return;
			for(int j = L[i];j != i;j = L[j])resume(Col[j]);
		}
		resume(c);
	}
}a;

void save()
{
	int i;
	for(i=0;i<a.ansd;i++)
		ans[(a.ans[i]-1)/9+1]=(a.ans[i]-1)%9+1;
}

 void insert(int x,int y,int v)
 {
	 int l=((x-1)*9+y-1)*9+v;
	 a.Link(l,(x-1)*9+y);
	 a.Link(l,81+(x-1)*9+v);
	 a.Link(l,162+(y-1)*9+v);
	 a.Link(l,243+(mark[x][y])*9+v);
 }

void DFS(int x,int y,int cnt)
{
	int i;
	mark[x][y]=cnt;
	for(i=1;i<=4;i++){
		if(m[x][y][i]) continue;
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>9||ny<1||ny>9) continue;
		if(mark[nx][ny]==-1) DFS(nx,ny,cnt);
	}
}

void fuck()
{
	int i,j,k;
	memset(m,0,sizeof(m));
	memset(mark,-1,sizeof(mark));
	for(i=1;i<=9;i++)
		for(j=1;j<=9;j++){
			scanf("%d",&m[i][j][0]);
			for(k=4;k>=1;k--)
				if(m[i][j][0]>=v[k]){
					m[i][j][k]=1;
					m[i][j][0]-=v[k];
				}
		}
	
	int cnt=0;
	for(i=1;i<=9;i++)
		for(j=1;j<=9;j++)
			if(mark[i][j]==-1) DFS(i,j,cnt++);
	/*for(i=1;i<=9;i++){
		for(j=1;j<=9;j++)
			printf("%d",mark[i][j]);
		printf("\n");
	}*/

	a.init(729,324);
	for(i=1;i<=9;i++)
		for(j=1;j<=9;j++)
			if(m[i][j][0]!=0) insert(i,j,m[i][j][0]);
			else for(k=1;k<=9;k++) insert(i,j,k);
	a.Dance(0);
	if(a.cnt>1){
		printf("Multiple Solutions\n");
		return;
	}
	if(a.cnt==0){
		printf("No solution\n");
		return;
	}
	for(i=1;i<=9;i++){
		for(j=1;j<=9;j++)
			printf("%d",ans[(i-1)*9+j]);
		printf("\n");
	}
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case %d:\n",i);
		fuck();
	}
 return 0;
}

