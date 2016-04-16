#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,b[22];
long long Mod;

long long gcd(long long a, long long b)  
{  
    if(b==0)  
        return a;  
    return gcd(b,a%b);  
}  
  
long long Extend_Euclid(long long a, long long b, long long&x, long long& y)  
{  
    if(b==0)  
    {  
        x=1,y=0;  
        return a;  
    }  
    long long d = Extend_Euclid(b,a%b,x,y);  
    long long t = x;  
    x = y;  
    y = t - a/b*y;  
    return d;  
}  
  
//a在模n乘法下的逆元，没有则返回dd-1  
long long inv(long long a, long long n)  
{  
    long long x,y;  
    long long t = Extend_Euclid(a,n,x,y);  
    if(t != 1)  
        return -1;  
    return (x%n+n)%n;  
}  
  
//将两个方程合并为一个  
bool merge(long long a1, long long n1, long long a2, long long n2, long long& a3, long long& n3)  
{  
    long long d = gcd(n1,n2);  
    long long c = a2-a1;  
    if(c%d)  
        return false;  
    c = (c%n2+n2)%n2;  
    c /= d;  
    n1 /= d;  
    n2 /= d;  
    c *= inv(n1,n2);  
    c %= n2;  
    c *= n1*d;  
    c += a1;  
    n3 = n1*n2*d;  
    a3 = (c%n3+n3)%n3;  
    return true;  
}  
  
long long CRT(long long a[], long long m[])
{  
    long long a1=a[1],m1=m[1];
    long long a2,m2;
    for(int i = 2; i <= n ; i++)
    {
        long long aa,mm;
        a2 = a[i],m2=m[i];
        if(!merge(a1,m1,a2,m2,aa,mm))
            return -1;
        a1 = aa;
        m1 = mm;
    }
    Mod = m1;
    return (a1%m1+m1)%m1;
}

void fuck()
{
	int i,j,t;
	long long int a[22],m[22]={0};
	bool vis[22]={0};
	b[0]=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		b[t]=i;
	}
	for(i=1;i<=n;i++){
		a[i]=n-i+1;
		if(b[i-1]<b[i]){
			for(j=b[i-1]+1;j<=b[i];j++)
				if(!vis[j]) m[i]++;
		}
		else{
			for(j=b[i-1]+1;j<=n;j++)
				if(!vis[j]) m[i]++;
			for(j=1;j<=b[i];j++)
				if(!vis[j]) m[i]++;
		}
		vis[b[i]]=1;
	}
	//for(i=1;i<=n;i++) printf("%d %d\n",m[i],a[i]);
	long long ans=CRT(m,a);
	if(ans==0){
		ans=1;
		for(i=1;i<=n;i++)
			ans=ans/gcd(ans,i)*i;
	}
	if(ans==-1) cout<<"Creation August is a SB!"<<endl;
	else cout<<ans<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

