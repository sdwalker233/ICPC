#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1e9+7;
struct Mat{
	int m[25][25];
	Mat(){
		memset(m,0,sizeof(m));
	}
	Mat(const Mat& M){
		memcpy(m,M.m,sizeof(m));
	}
}E;
int size,n,m,k;

Mat mul(Mat a,Mat b)
{
	int i,j,k;
	Mat res;
	for(k=1;k<=size;k++){
		for(i=1;i<=size;i++){
			if(a.m[i][k]==0) continue;
			for(j=1;j<=size;j++){
				res.m[i][j]=(1ll*a.m[i][k]*b.m[k][j]+res.m[i][j])%mod;
			}
		}
	}
	return res;
}

Mat qpow(Mat a,int n)
{
	Mat tmp=a,res=E;
	while(n){
		if(n&1) res=mul(tmp,res);
		tmp=mul(tmp,tmp);
		n>>=1;
	}
	return res;
}

void fuck()
{
	int i,j;
	scanf("%d%d%d",&n,&m,&k);
	size=2*m+3;
	Mat A;
	for(i=1;i<=size;i++) E.m[i][i]=1;
	for(i=1;i<=m;i++){
		A.m[i][i+1]=k;
		A.m[i+m+1][i+m+2]=k;
		A.m[m+1][i+1]=k*k-k;
	}
	for(i=m+2;i<=2*m+2;i++){
		A.m[2*m+2][i]=k*k-k;
		A.m[2*m+3][i]=1;
	}
	A.m[2*m+2][1]=k*k-k;
	A.m[2*m+3][1]=1;
	Mat B=qpow(A,n+1);
	printf("%lld\n",B.m[size][m+1]);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

