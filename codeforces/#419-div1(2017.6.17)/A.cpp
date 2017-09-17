#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
int n,m,g[MAXN][MAXN];
vector<int> ans1,ans2;

void f2()
{
	int i,j;
	for(j=1;j<=m;j++){
		int mn=1000;
		for(i=1;i<=n;i++) mn=min(mn,g[i][j]);
		for(i=1;i<=mn;i++) ans2.push_back(j);
		for(i=1;i<=n;i++) g[i][j]-=mn;
	}
}

void f1()
{
	int i,j;
	for(i=1;i<=n;i++){
		int mn=1000;
		for(j=1;j<=m;j++) mn=min(mn,g[i][j]);
		for(j=1;j<=mn;j++) ans1.push_back(i);
		for(j=1;j<=m;j++) g[i][j]-=mn;
	}
}

int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&g[i][j]);
	if(n<m){
		f1();f2();
	}
	else{
		f2();f1();
	}
	int sum=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++) sum+=g[i][j];
	if(sum){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ans1.size()+ans2.size());
	for(auto it : ans1) printf("row %d\n",it);
	for(auto it : ans2) printf("col %d\n",it);
 return 0;
}

