#include <bits/stdc++.h>
#define MAXN 7010
using namespace std;
int n,k1,k2;
vector<int> a,b;
queue<int> qa,qb;
int aa[MAXN]={0},bb[MAXN]={0};
bool vis1[MAXN],vis2[MAXN];
int c1[MAXN],c2[MAXN],c3[MAXN],c4[MAXN];

int main()
{
	int i,j,x;
	scanf("%d%d",&n,&k1);
	for(i=1;i<=k1;i++){
		scanf("%d",&x);
		a.push_back(x);
	}
	scanf("%d",&k2);
	for(i=1;i<=k2;i++){
		scanf("%d",&x);
		b.push_back(x);
	}
	for(auto it : a){
		aa[n+1-it]=1;
		vis1[n+1-it]=1;
		qa.push(n+1-it);
	}
	for(auto it : b){
		bb[n+1-it]=-1;
		vis2[n+1-it]=1;
		qb.push(n+1-it);
	}
	vis1[1]=vis2[1]=1;
	while(!qa.empty()||!qb.empty()){
		if(!qa.empty()){
			int now=qa.front();
			qa.pop();
			//printf("qa:%d\n",now);
			for(auto it : b){
				int nxt=(now-it+n-1)%n+1;
				c1[nxt]+=aa[now];
				if(vis2[nxt]) continue;
				//printf("%d %d %d %d\n",now,it,nxt,aa[now]);
				if(aa[now]==-1){
					bb[nxt]=-1;
					vis2[nxt]=1;
					qb.push(nxt);
				}
				else if(c1[nxt]==k2){
					bb[nxt]=1;
					vis2[nxt]=1;
					qb.push(nxt);
				}
			}
		}
		if(!qb.empty()){
			int now=qb.front();
			//printf("qb:%d\n",now);
			qb.pop();
			for(auto it : a){
				int nxt=(now-it+n-1)%n+1;
				c2[nxt]+=bb[now];
				//printf("%d %d %d %d\n",now,it,nxt,bb[now]);
				if(vis1[nxt]) continue;
				if(bb[now]==1){
					aa[nxt]=1;
					vis1[nxt]=1;
					qa.push(nxt);
				}
				else if(c2[nxt]==-k1){
					aa[nxt]=-1;
					vis1[nxt]=1;
					qa.push(nxt);
				}
			}
		}
	}
	for(i=2;i<=n;i++)
		if(aa[i]==1) printf("Win ");
		else if(aa[i]==-1) printf("Lose ");
		else printf("Loop ");
	printf("\n");
	for(i=2;i<=n;i++)
		if(bb[i]==-1) printf("Win ");
		else if(bb[i]==1) printf("Lose ");
		else printf("Loop ");

 return 0;
}

