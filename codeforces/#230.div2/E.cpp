#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int c[50][50],size;
long long n,k;
struct mat{
    long long m[100][100];
	mat(){
		memset(m,0,sizeof(m));
	}
};
mat M;

mat multiply(mat &A,mat &B){
    mat tmp;
    int i,j,k;
	for(k=1;k<=size;k++){
		for(i=1;i<=size;i++){
			if(!A.m[i][k]) continue;
			for(j=1;j<=size;j++)
				tmp.m[i][j]=(tmp.m[i][j]+(A.m[i][k]*B.m[k][j])%MOD)%MOD;
		}
	}
	return tmp;
}

mat Quick_power(mat &A,long long n){
    mat ans,tmp;
    memcpy(tmp.m,A.m,sizeof(tmp.m));
	for(int i=1;i<=size;i++)
		ans.m[i][i]=1;
	while(n){
		if(n&1) ans=multiply(ans,tmp);
		n>>=1;
        tmp=multiply(tmp,tmp);
    }
    return ans;
}

void Combination()
{
	int i,j;
	for(i=0;i<=k;i++){
		c[i][0]=c[i][i]=1;
		for(j=1;j<i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	}
}

void Init()
{
	int i,j,l;
	M.m[1][1]=1;
	for(i=0;i<=k;i++){
		M.m[1][i+2]=M.m[1][i+k+3]=c[k][i];
	}
	for(i=2;i<=k+2;i++){
		for(j=i;j<=k+2;j++){
			M.m[i][j]=M.m[i][j+k+1]=M.m[i+k+1][j]=c[k+2-i][j-i];
		}
	}
}

int main()
{
    int i,j;
	long long ans=0;
	cin>>n>>k;
	Combination();
	/*for(i=0;i<=k;i++){
		for(j=0;j<=i;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}*/
	Init();
	size=2*k+3;
	/*for(i=1;i<=size;i++){
		for(j=1;j<=size;j++)
			printf("%d ",M.m[i][j]);
		printf("\n");
	}*/
	M=Quick_power(M,n-1);
	for(i=1;i<=size;i++)
		ans=(ans+M.m[1][i])%MOD;
	cout<<ans;
 return 0;
}

