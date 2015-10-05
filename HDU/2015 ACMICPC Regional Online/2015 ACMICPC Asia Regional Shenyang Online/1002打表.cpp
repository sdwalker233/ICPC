#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
struct mat{
    long long m[3][3];
    mat(){
		memset(m,0,sizeof(m));
	}
};

int size=2;
int mod;

mat mul(mat a,mat b){
    mat tmp;
    int i,j,k;
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            for(k=1;k<=size;k++){
                tmp.m[i][j]=(tmp.m[i][j]+(a.m[i][k]*b.m[k][j])%mod)%mod%mod;
            }
        }
    }
    return tmp;
}

mat QP(mat a,int n){
    mat ans,tmp;
    memcpy(tmp.m,a.m,sizeof(tmp.m));
    for(int i=1;i<=size;i++){
        ans.m[i][i]=1;
    }
    while(n){
        if(n&1)ans=mul(ans,tmp);
        n>>=1;
        tmp=mul(tmp,tmp);
    }
    return ans;
}

void check(int x)
{
	map<pair<int,int>,int> mp;
	pair<int,int> tmp;
	mat A,B;
	A.m[1][1]=10%x;A.m[1][2]=(x-1)%x;A.m[2][1]=1;A.m[2][2]=0;
	B.m[1][1]=1;B.m[1][2]=0;B.m[2][1]=0;B.m[2][2]=1;
	int i;
	mod=x;
	for(i=1;;i++){
		B=mul(A,B);
		tmp=make_pair(B.m[1][1],B.m[1][2]); 
		if(mp[tmp]){
			printf("%d,",i-1);
			return;
		}
		mp[tmp]=i;
	}
}

int main()
{
	freopen("out.txt","w",stdout);
	int i,j;
	bool is_prime[50000]={0};
	for(i=2;i<=46337;i++)
		if(is_prime[i]==0){
			for(j=i*2;j<=46337;j+=i)
				is_prime[j]=1;
		}

	for(i=2;i<=46337;i++){
		if(is_prime[i]==0)	check(i);
	}
 return 0;
}


