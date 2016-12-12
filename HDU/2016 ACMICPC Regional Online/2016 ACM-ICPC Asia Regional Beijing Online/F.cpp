#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#define MAXN 60010
using namespace std;
const long double PI=acos(-1.0);
int n,A[MAXN],B[MAXN];
long long C[MAXN<<3];

struct complex{
    long double r,i;
    complex(long double _r=0.0,long double _i=0.0){
        r=_r;i =_i;
    }
    complex operator +(const complex &b){
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b){
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b){
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};

void change(complex y[],int len)
{
    int i,j,k;
    for(i=1,j=len/2;i<len-1;i++){
        if(i<j) swap(y[i],y[j]);
        k=len/2;
        while(j>=k){
            j-=k;
            k/=2;
        }
        if(j<k) j+=k;
    }
}

void FFT(complex y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1){
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j=0;j <len;j+=h){
            complex w(1,0);
            for(int k=j;k < j+h/2;k++){
                complex u=y[k];
                complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1)
        for(int i=0;i<len;i++)
           y[i].r/=len;
}
complex a[MAXN<<3],b[MAXN<<3],c[MAXN<<3];

void fuck()
{
	int i,len=1,p;
	long long mx=-1,sum=0;
	scanf("%d",&n);
    while(len<((2*n)<<1)) len<<=1;
	//printf(" %d\n",len);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
		a[i+n]=a[i]=complex(A[i],0);
		sum+=(long long)A[i]*A[i];
	}
	for(i=0;i<n;i++){
		scanf("%d",&B[i]);
		b[i]=complex(0,0);
		b[2*n-i-1]=complex(B[i],0);
		sum+=(long long)B[i]*B[i];
	}
	for(i=2*n;i<len;i++)
		a[i]=b[i]=complex(0,0);
	FFT(a,len,1);
	FFT(b,len,1);
	for(i=0;i<len;i++)
		c[i]=a[i]*b[i];
	FFT(c,len,-1);
	for(i=2*n;i<3*n;i++){
		C[i]=(long long)(c[i].r+0.5);
		if(mx<C[i]){
			mx=C[i];
			p=i;
		}
		//printf("%lld\n",C[i]);
	}
	p-=2*n-1;
	//printf(" %d\n",p);
	long long ans=0;
	for(i=0;i<n;i++){
		ans+=(long long)(B[i]-A[(i+p)%n])*(B[i]-A[(i+p)%n]);
	}
	printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

