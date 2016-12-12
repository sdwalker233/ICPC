#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int mod=1e9+7;
const int dx[]={0,1,1,1,0,-1,-1,-1},dy[]={1,1,0,-1,-1,-1,0,1};
int dd[10];
int n,m;
bool gu[30];
vector<int> ngu[30];
char g[10][10];
long long fact[30],ans;

void print(int x)
{
	int i;
	for(i=0;i<n*m;i++)
		if((1<<i)&x) printf("1");
		else printf("0");
	printf("\n");
}

void DFS(int nxt,int used)
{
	int i,j,k,nn,mask=0;
	if(nxt==((1<<(n*m))-1)){
		//print(nxt);
		//print(used);
		int cnt=0;
		for(i=0;i<n*m;i++)
			if(((1<<i)&nxt)&&((1<<i)&used)==0) cnt++;
		ans+=fact[cnt];ans%=mod;
		return;
	}
	//print(nxt);
	for(i=0;i<n*m;i++){
		if(((1<<i)&nxt)&&((1<<i)&used)==0){
			mask=0;
			//printf(" %d\n",i);
			for(j=0;j<8;j++){
				//printf("  %d\n",j);
				nn=i+dd[j];
				//if(nn==2) print(used);
				if(nn<0||nn>=n*m) continue;
				if( () ) continue;
				if(((1<<nn)&nxt)==0) mask|=(1<<nn);
			}
			//if(i==2) print(used);
			if(j<8) continue;
			DFS(nxt|mask,used|(1<<i));
		}
	}
}

void fuck()
{
	int i,j,mask=0;
	memset(gu,0,sizeof(gu));
	for(i=0;i<n*m;i++) ngu[i].clear();
	ans=0;
	for(i=0;i<n;i++) scanf("%s",g[i]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			if(g[i][j]=='X'){
				mask|=(1<<(i*m+j));
				gu[(1<<(i*m+j))]=1;
			}
		}
	for(i=0;i<8;i++){
		dd[i]=dx[i]*m+dy[i];
	}
	for(i=0;i<n*m;i++){
		for(j=0;j<8;j++){
			int nn=dd[j]+i;
			if(nn<0||nn>=n*m) continue;
			if(gu[nn]) ngu[i]|=(1<<nn);
		}
	}
	DFS(mask,0);
	cout<<ans<<endl;
}

int main()
{
	int t=1,i;
	fact[0]=1;
	for(i=1;i<=25;i++) fact[i]=fact[i-1]*i%mod;
	while(~scanf("%d%d",&n,&m)){
		printf("Case #%d: ",t++);
		fuck();
	}
 return 0;
}

