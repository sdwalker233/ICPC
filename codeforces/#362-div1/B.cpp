#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int fa[MAXN],num[MAXN]={0};
vector<int> ch[MAXN];
double p[MAXN];

void DFS1(int x)
{
	int i;
	for(i=0;i<ch[x].size();i++){
		DFS1(ch[x][i]);
		num[x]+=num[ch[x][i]]+1;
	}
}

void DFS2(int x)
{
	int i;
	for(i=0;i<ch[x].size();i++){
		p[ch[x][i]]=p[x]+1+(num[x]-num[ch[x][i]]-1)/2.0;
		DFS2(ch[x][i]);
	}
}

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		ch[fa[i]].push_back(i);
	}
	p[1]=1;
	DFS1(1);
	DFS2(1);
	for(i=1;i<=n;i++){
		cout<<p[i]<<" ";
	}
 return 0;
}

