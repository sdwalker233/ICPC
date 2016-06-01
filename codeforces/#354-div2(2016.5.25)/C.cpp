#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cassert>
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
int n,k,a[100010],b[100010];
char s[100010];

bool check(int x)
{
	rep(i,0,n-x){
		if(a[i+x]-a[i]<=k) return 1;
		if(b[i+x]-b[i]<=k) return 1;
	}
	return 0;
}

int main()
{
	scanf("%d%d%s",&n,&k,s+1);
	rep(i,1,n){
		a[i]=a[i-1];
		b[i]=b[i-1];
		if(s[i]=='a') a[i]++;
		else b[i]++;
	}
	int l=1,r=n,m,ans=0;
	while(l<=r){
		m=(l+r)>>1;
		if(check(m)){
			l=m+1;
			ans=m;
		}
		else r=m-1;
	}
	cout<<ans<<endl;
 return 0;
}

