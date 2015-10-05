#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m,k;
long long p[20],r[20];
long long jie[100010];

inline long long mulmod(long long x, long long y, long long mod)
{
	long long ret = 0;
	__asm__("movq %1,%%rax\n imulq %2\n idivq %3\n":"=d"(ret):"m"(x),"m"(y),"m"(mod):"%rax");
	return ret;
}

long long extend_gcd(long long a,long long b,long long &x,long long &y)    //扩展欧几里得算法  
{  
    long long d;  
    if(b==0)  
    {  
        x=1;y=0;  
        return a;  
    }  
    d=extend_gcd(b,a%b,y,x);  
    y-=a/b*x;
    return d;  
}  
  
long long crt(long long a[],long long m[],long long n)
{
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

long long quick(long long a,long long x,long long p)
{
  long long ans=1;
  a%=p;
  while (x)
  {
	if (x%2) ans=mulmod(ans,a,p);
	x/=2;
	a=mulmod(a,a,p);
  }
  return ans;
}

long long C(long long n,long long m,long long p)
{
  if (m>n) return 0;
  return jie[n]*quick(jie[n-m]*jie[m],p-2,p)%p;
}

long long lucas(long long n,long long m,long long p)
{
  if (m==0) return 1;
  return C(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}

void fuck()
{
	int i,j;
	long long pr=1;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for(i=1;i<=k;i++){
		scanf("%I64d",&p[i]);
		jie[0]=1;
		for(j=1;j<=p[i];j++)
			jie[j]=jie[j-1]*j%p[i];
		r[i]=lucas(n,m,p[i]);
		pr*=p[i];
	}
	long long x=crt(r,p,k);
	printf("%I64d\n",x%pr);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}

