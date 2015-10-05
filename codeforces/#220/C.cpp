#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
struct node1{
	int x1,x2,y1,y2,p;
}DIMA[3000000];
struct node2{
	int x,y;
}DDD[3000001];
struct node3{
	int to,next;
}edge[3000000];
int n,m,maze[1002][1002],tot1=0,tot2=0,tot3=0,mx=0,cnt=0,dp[3000000]={0};
int head[3000000],in[3000000]={0};
int dx[]={1,0,0,-1},dy[]={0,1,-1,0};
char s[1010][1010];
int vis[3000000]={0},is_circle=0;
vector<int> pos[1002][1002];
set<pair<int,int> > st;

void addedge(int x,int y)
{
	++tot3;
	edge[tot3].to=y;
	edge[tot3].next=head[x];
	head[x]=tot3;
	in[y]++;
}

void addv(int x1,int y1,int x2,int y2)
{
	if(x1==x2&&y1==y2) is_circle=1;
	++tot1;
	pos[x1][y1].push_back(tot1);
	DIMA[tot1].x1=x1;
	DIMA[tot1].x2=x2;
	DIMA[tot1].y1=y1;
	DIMA[tot1].y2=y2;
	DIMA[tot1].p=tot1;
}

void ext(int sx,int sy,int x,int y,int p)
{
	int i,nx,ny;
	if(p>=4){
		st.insert(make_pair(x,y));
		return;
	}
	for(i=0;i<4;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>n||nx<1||ny>m||ny<1) continue;
		//printf(" %d %d %d %d\n",nx,ny,maze[nx][ny],p+1);
		if(maze[nx][ny]==p+1) ext(sx,sy,nx,ny,p+1);
	}
}

int DFS(int x)
{
	int i,ss;
	vis[x]=-1;
	//printf(" %d %d\n",x,step);
	if(is_circle) return -1;
	for(i=head[x];i!=-1;i=edge[i].next){
		if(vis[edge[i].to]==-1){
			is_circle=1;
			return -1;
		}
		if(vis[edge[i].to]==1) ss=dp[edge[i].to];
		else ss=DFS(edge[i].to);
		dp[x]=max(dp[x],ss);
	}
	vis[x]=1;
	dp[x]++;
	mx=max(mx,dp[x]);
	return dp[x];
}

int main()
{
	int i,j,k,l,x,y,nx,ny;
	set<pair<int,int> >::iterator it;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%s",&s[i][1]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			switch(s[i][j]){
				case('D'):
					maze[i][j]=1;
					tot2++;
					DDD[tot2].x=i;DDD[tot2].y=j;
					break;
				case('I'):maze[i][j]=2;break;
				case('M'):maze[i][j]=3;break;
				case('A'):maze[i][j]=4;break;
			}
	for(i=1;i<=tot2;i++){
		st.clear();
		ext(DDD[i].x,DDD[i].y,DDD[i].x,DDD[i].y,1);
		//printf("%d %d\n",DDD[i].x,DDD[i].y);
		for(it=st.begin();it!=st.end();it++)
			addv(DDD[i].x,DDD[i].y,(*it).first,(*it).second);
	}
		
	if(tot1==0){
		printf("Poor Dima!");
		return 0;
	}
	for(i=1;i<=tot1;i++){
		x=DIMA[i].x2;y=DIMA[i].y2;
		for(j=0;j<4;j++){
			nx=x+dx[j];
			ny=y+dy[j];
			if(nx>n||nx<1||ny>m||ny<1) continue;
			if(!pos[nx][ny].empty()){
				for(k=0;k<pos[nx][ny].size();k++){
					addedge(i,DIMA[pos[nx][ny][k]].p);
					//printf("  %d %d\n",i,DIMA[pos[nx][ny][k]].p);
				}

			}
		}
	}
	//return 0;
	/*for(i=1;i<=tot1;i++){
		printf(" %d %d %d %d %d\n",DIMA[i].x1,DIMA[i].y1,DIMA[i].x2,DIMA[i].y2,DIMA[i].p);
	}*/
	//if(n==1000&&m==1000&&s[1][2]=='A')
		//printf("%d %d %d\n",tot1,tot2,tot3);
	for(i=1;i<=tot1;i++){
		if(!is_circle&&!vis[i]){
			DFS(i);
		}
	}
	
	if(is_circle) printf("Poor Inna!");
	else printf("%d",mx);
 return 0;
}

