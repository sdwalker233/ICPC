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

int main()
{
    int a[110],n;
	int p1,p2;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(a[i]==1) p1=i;
		if(a[i]==n) p2=i;
	}
	if(p1>p2) swap(p1,p2);
	cout<<max(p2-1,n-p1)<<endl;
 return 0;
}

