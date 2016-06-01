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

const double eps=1e-8;
int main()
{
	int n,t;
	double a[100]={0};
	scanf("%d%d",&n,&t);
	while(t-->0){
		a[1]+=2.0;
		rep(i,1,n)
			rep(j,i*(i-1)/2+1,i*(i+1)/2)
				if(a[j]>2){
					a[j+i]+=(a[j]-2)/2;
					a[j+i+1]+=(a[j]-2)/2;
					a[j]=2;
				}
	}
	int ans=0;
	rep(i,1,(n+1)*n/2)
		if(a[i]>=2-eps) ans++;
	cout<<ans<<endl;
 return 0;
}

