#include <bits/stdc++.h>
using namespace std;
int q;
unsigned long long n,F[70],B[70];

unsigned long long f(unsigned long long x)
{
	if(x==0) return 0;
	int t=log(1.0*x)/log(2.0);
	unsigned long long tmp=(1ll<<t);
	return F[t]+f(x-tmp);
}

unsigned long long h(unsigned long long x,int t)
{
	//cout<<"h"<<x<<" "<<t<<endl;
	if(t==0) return 1;
	unsigned long long tmp=(1ll<<(t-1));
	if(x<=tmp) return h(x,t-1)+1;
	return h(x-tmp,t-1);
}

unsigned long long g(unsigned long long x,unsigned long long n)
{
	//cout<<"g"<<x<<" "<<n<<endl;
	//if(x==1) return 0;
	int t=log(1.0*n)/log(2.0);
	unsigned long long tmp=(1ll<<t);
	if(x<=tmp) return h(x,t);
	else return g(x-tmp,n-tmp);
}

void fuck()
{
	int i,op;
	unsigned long long l,r,x,ans;
	while(q-->0){
		scanf("%d",&op);
		if(op==1){
			scanf("%llu%llu",&l,&r);
			printf("%llu\n",f(r)-f(l-1));
		}
		else{
			scanf("%llu",&x);
			printf("%llu\n",g(x,n));
		}
	}
}

int main()
{
	int i;
	F[0]=B[0]=1;
	for(i=1;i<=64;i++){
		B[i]=2*B[i-1];
		F[i]=2*F[i-1]+B[i-1];
		//cout<<i<<" "<<F[i]<<endl;
	}
	//for(i=1;i<=100;i++) printf("%d %d\n",i,(i&-i));
	while(~scanf("%llu%d",&n,&q)) fuck();
 return 0;
}

