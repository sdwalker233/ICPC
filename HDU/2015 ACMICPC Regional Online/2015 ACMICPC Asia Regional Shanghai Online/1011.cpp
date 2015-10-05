#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
int c,k1,k2,b1;

long long QP(long long a,long long n,int m){
    long long tmp=a,ans=1;
    while(n){
        if(n&1)ans=ans*tmp%m;
        tmp=tmp*tmp%m;
        n>>=1;
    }
    return ans;
}

long long qpow(long long a,long long b,int c)
{
	return QP(a,b%(c-1),c);
}

void fuck()
{
	int i,j,a,b;
	long long n;
	long long x1,x2,t1,t2;
	bool ok=0,flag;
	k1=k1%(c-1);
	k2=k2%(c-1);
	b1=b1%(c-1);
	for(i=1;i<c;i++){
		a=i;
		t1=qpow(i,k1+b1,c);
		b=t2=c-t1;
		if(b==0||b==c) continue;
		flag=1;
		for(n=2;n<c;n++){
			x1=qpow(a,k1*n+b1,c);
			x2=qpow(b,k2*n-k2+1,c);
			if(x1==t1&&x2==t2) break;
			if(x1+x2!=c){
				flag=0;
				break;
			}
			//printf(" %d %d %d\n",a,b,n);
		}
		/*for(j=1;j<=5;j++){
			n=rand()%1000+2;
			if(x1+x2!=c) break;
		}*/
		if(!flag) continue;
		printf("%d %d\n",a,b);
		ok=1;
	}
	if(!ok) printf("-1\n");
}

int main()
{
	int t=0;
	//srand(time(NULL));
	while(~scanf("%d%d%d%d",&c,&k1,&b1,&k2)){
		printf("Case #%d:\n",++t);
		fuck();
	}
 return 0;
}
