#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
map<int,int> mp;
vector<int> v;
int n;
int a[MAXN],p[MAXN],d[MAXN];
bool vis[MAXN],leaf[MAXN];

int main()
{
	int i,cnt=0;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=2;i<=n;i++){
		scanf("%d",&p[i]);
		leaf[p[i]]=1;
	}
	p[1]=1;
	queue<int> q;
	for(i=1;i<=n;i++)
		if(!leaf[i]){
			q.push(i);
			v.push_back(a[i]);
			vis[i]=1;
		}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(!vis[p[now]]){
			vis[p[now]]=1;
			d[p[now]]=d[now]+1;
			if(d[p[now]]%2==0) v.push_back(a[p[now]]);
			else mp[a[p[now]]]++;
			q.push(p[now]);
		}
	}
	int tmp=0;
	long long sz1=v.size(),sz2=n-sz1;
	long long ans=0;
	for(auto it:v) tmp^=it;
	if(tmp==0) ans+=sz1*(sz1-1)/2+sz2*(sz2-1)/2;
	for(auto it:v) ans+=mp[tmp^it];
	cout<<ans<<endl;
 return 0;
}

