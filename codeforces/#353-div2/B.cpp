#include <bits/stdc++.h>
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

int main()
{
    int n,a,b,c,d;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	ll ans=0;
	rep(i,1,n){
		if(i+b-c<1||i+b-c>n) continue;
		if(i+a-d<1||i+a-d>n) continue;
		if(i+a-d+b-c<1||i+a-d+b-c>n) continue;
		ans++;
	}
	ans*=n;
	cout<<ans<<endl;
 return 0;
}

