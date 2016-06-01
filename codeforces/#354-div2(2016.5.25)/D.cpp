#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head
struct node{
	int x,y;
	int step;
	node(int _x=0,int _y=0,int _step=0){
		x=_x;y=_y;step=_step;
	}
	friend bool operator<(const node& x,const node& y){
		return x.step>y.step;
	}
};
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n,m,sx,sy,ex,ey;
char s[1010][1010];
int cost[1010][1010][4];
int open[1010][1010]={0},close[1010][1010]={0};

int main()
{
    cin>>n>>m;
	rep(i,1,n) scanf("%s",&s[i][1]);
	cin>>sx>>sy>>ex>>ey;
	rep(i,1,n)
		rep(j,1,m){
			cost[i][j][0]=cost[i][j][1]=cost[i][j][2]=cost[i][j][3]=1;
			if(s[i][j]=='|'||s[i][j]=='^'||s[i][j]=='R') cost[i][j][0]=2;
			if(s[i][j]=='-'||s[i][j]=='>'||s[i][j]=='D') cost[i][j][1]=2;
			if(s[i][j]=='|'||s[i][j]=='v'||s[i][j]=='L') cost[i][j][2]=2;
			if(s[i][j]=='-'||s[i][j]=='<'||s[i][j]=='U') cost[i][j][3]=2;
			if(s[i][j]=='^') {cost[i][j][1]=3;cost[i][j][2]=4;}
			if(s[i][j]=='>') {cost[i][j][2]=3;cost[i][j][3]=4;}
			if(s[i][j]=='v') {cost[i][j][3]=3;cost[i][j][0]=4;}
			if(s[i][j]=='<') {cost[i][j][0]=3;cost[i][j][1]=4;}
		}
	priority_queue<node> qu;
	qu.push(node(sx,sy,0));
	int ans=-1;
	while(!qu.empty()){
		node now=qu.top();
		qu.pop();
		if(close[now.x][now.y]) continue;
		close[now.x][now.y]=1;
		//printf(" %d %d %d\n",now.x,now.y,now.step);
		if(now.x==ex&&now.y==ey){
			ans=now.step;
			break;
		}
		int nx,ny,nstep;
		rep(i,0,3){
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			if(nx<1||ny<1||nx>n||ny>m||s[nx][ny]=='*'||close[nx][ny]) continue;
			nstep=now.step+cost[now.x][now.y][i];
			if(open[nx][ny]==0||open[nx][ny]>nstep){
				open[nx][ny]=nstep;
				qu.push(node(nx,ny,nstep));
			}
		}
	}
	printf("%d\n",ans);
 return 0;
}

