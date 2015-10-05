#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=2015;
struct mat{
	int m[60][60];
	mat(){
		memset(m,0,sizeof(m));
	}
};
int m,n,size;

mat multiply(mat a,mat b)
{
    mat tmp;
    int i,j,k;
	for(k=1;k<=size;k++)
		for(i=1;i<=size;i++){
			if(a.m[i][k]==0) continue;
			for(j=1;j<=size;j++)
				tmp.m[i][j]=(tmp.m[i][j]+a.m[i][k]*b.m[k][j]%mod)%mod;
			}
    return tmp;
}

mat quick_power(mat a,int n)
{
	int i;
    mat ans,tmp;
    memcpy(tmp.m,a.m,sizeof(tmp.m));
	for(int i=1;i<=size;i++)
        ans.m[i][i]=1;
    while(n){
        if(n&1) ans=multiply(ans,tmp);
        n>>=1;
        tmp=multiply(tmp,tmp);
    }
    return ans;
}

void fuck()
{
	int i,j,x,y,ans=0;
	mat A;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		for(j=1;j<=x;j++){
			scanf("%d",&y);
			A.m[i][y]=1;
		}
	}
	for(i=1;i<=n+1;i++)
		A.m[n+1][i]=1;
	size=n+1;
	A=quick_power(A,m);
	for(i=1;i<=n+1;i++)
		ans=(ans+A.m[n+1][i])%mod;
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		fuck();
 return 0;
}


