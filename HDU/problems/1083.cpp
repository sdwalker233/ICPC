#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int p,n,from[500];
bool use[500];
vector<int> g[500];

 bool hungary(int x)
 {
	 int i;
	 for(i=0;i<g[x].size();i++)
		 if(!use[g[x][i]]){
			 use[g[x][i]]=1;
			 if(from[g[x][i]]==-1||hungary(from[g[x][i]])){
				 from[g[x][i]]=x;
				 return 1;
			 }
		 }
	 return 0;
 }

 void run()
 {
	 int i,cnt,j,x;
	 memset(from,-1,sizeof(from));
	 scanf("%d%d",&p,&n);
	 for(i=1;i<=p;i++){
		 g[i].clear();
		 scanf("%d",&cnt);
		 for(j=1;j<=cnt;j++){
			 scanf("%d",&x);
			 g[i].push_back(x);
		 }
	 }
	 for(i=1;i<=p;i++){
		 memset(use,0,sizeof(use));
		 if(hungary(i)==0) break;
	 }
	 if(i>p) printf("YES\n");
	 else printf("NO\n");
 }
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) run();
 return 0;
}

