#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[20],p[20];
long long x,y;

inline long long mulmod(long long x, long long y, long long mod){
	long long ret = 0;
	__asm__("movq %1,%%rax\n imulq %2\n idivq %3\n":"=d"(ret):"m"(x),"m"(y),"m"(mod):"%rax");
	return ret;
}

long long extend_gcd(long long a,long long b,long long &x,long long &y){  
    long long d;  
    if(b==0){  
        x=1;y=0;  
        return a;  
    }  
    d=extend_gcd(b,a%b,y,x);  
    y-=a/b*x;
    return d;  
}

long long crt(int a[],int m[],int n){
    long long M=1;
    for(int i=1;i<=n;i++) M*=m[i];
    long long ret=0;
    for(int i=1;i<=n;i++){
    	long long x,y;
    	long long tm=M/m[i];
    	extend_gcd(tm,m[i],x,y);
    	ret=(ret+mulmod(mulmod(tm,x,M),a[i],M))%M;
	}
	return (ret+M)%M;
}

void fuck()
{
	int i,j;
	int A[20],P[20],cnt;
	long long ans=0,res1,res2,res;
	scanf("%d%lld%lld",&n,&x,&y);
	for(i=1;i<=n;i++) scanf("%d%d",&p[i],&a[i]);
	for(i=0;i<(1<<n);++i){
		int bit=1;
		long long mul=1;
		cnt=0;
		for(j=1;j<=n;++j){
			if(i&(1<<(j-1))){
				bit++;
				++cnt;
				A[cnt]=a[j];
				P[cnt]=p[j];
				mul*=p[j];
			}
		}
		cnt++;A[cnt]=0;P[cnt]=7;mul*=7;
		long long tmp=crt(A,P,cnt);
		res1=y/mul+((y%mul>=tmp)?1:0);
		res2=(x-1)/mul+(((x-1)%mul>=tmp)?1:0);
		res=res1-res2;
		//printf(" %d %lld %lld %lld\n",i,tmp,mul,res);
		if(bit%2)ans+=res;
		else ans-=res;
	}
	cout<<ans<<endl;
}

int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}

