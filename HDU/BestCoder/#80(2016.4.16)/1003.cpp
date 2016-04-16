#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1e9+7;
int size=3;
struct mat{
    long long m[4][4];
	mat(){
		memset(m,0,sizeof(m));
	}
};
int a,b,c,p;
long long n;

mat mul(mat a,mat b,long long mod){
    int i,j,k;
	mat tmp;
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            for(k=1;k<=size;k++){
                tmp.m[i][j]=(tmp.m[i][j]+(a.m[i][k]*b.m[k][j])%mod)%mod;
            }
        }
    }
    return tmp;
}

mat QP(mat a,long long n,long long mod){
    mat ans,tmp;
    memcpy(tmp.m,a.m,sizeof(tmp.m));
    for(int i=1;i<=size;i++){
        ans.m[i][i]=1;
    }
    while(n){
        if(n&1) ans=mul(ans,tmp,mod);
        n>>=1;
        tmp=mul(tmp,tmp,mod);
    }
    return ans;
}

long long qpow(long long x, long long y, long long mod)
{
	long long ret = 1,tmp=x;
	while(y){
		if(y&1) ret=(ret*tmp)%mod;
		y>>=1;
		tmp=(tmp*tmp)%mod;
	}
	return ret;
}

void fuck()
{
	int i;
	cin>>n;
	scanf("%d%d%d%d",&a,&b,&c,&p);
	mat A;
	A.m[1][1]=c;A.m[1][2]=1;A.m[1][3]=1;
	A.m[2][1]=1;A.m[3][3]=1;
	A=QP(A,n-1,p-1);
	long long d=b*A.m[1][3]%(p-1);
	d+=p-1;
	long long ans=qpow(a,d,p);
	cout<<ans<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

