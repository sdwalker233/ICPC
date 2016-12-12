#include<stdio.h>
#include<string.h>
#include<math.h>
const int mod=1e9+7;
struct mat{
	long long m[5][5];
	mat(){
		memset(m,0,sizeof(m));
	}
};
int size;

long long eular(long long n)
{
	long long ret=1,i;
	for(i=2;i*i<=n;i++){
		if(n%i==0){
			n/=i,ret*=i-1;
			while(n%i==0) n/=i,ret*=i;
		}
	}
	if(n>1) ret*=n-1;
	return ret;
}

long long extgcd(long long a,long long b,long long &x,long long &y)  
{  
    if(b==0){  
        x=1;  
        y=0;  
        return a;  
    }  
    long long gcd = extgcd(b, a % b, x, y);  
    long long tmp = x;  
    x = y;  
    y = tmp - (a/b) * y;  
    return gcd;  
}  

mat mul(mat a,mat b,long long mod)
{
    mat tmp;
    int i,j,k;
    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
            for(k=1;k<=size;k++){
                tmp.m[i][j]=(tmp.m[i][j]+(a.m[i][k]*b.m[k][j])%mod)%mod;
            }
        }
    }
    return tmp;
}

mat QP(mat a,long long n,long long mod)
{
    mat ans,tmp;
    memcpy(tmp.m,a.m,sizeof(tmp.m));
    for(int i=1;i<=size;i++){
        ans.m[i][i]=1;
    }
    while(n){
        if(n&1) ans=mul(ans,tmp,mod);
        n>>=1;
        tmp=mul(tmp,tmp,mod);
    }
    return ans;
}

long long qpow(long long a,long long n,long long mod){
    long long tmp=a,ans=1;
    while(n){
        if(n&1) ans=ans*tmp%mod;
        tmp=tmp*tmp%mod;
        n>>=1;
    }
    return ans;
}

void fuck()
{
	int i,j;
	long long n,y,x,s;
	scanf("%lld%lld%lld%lld",&n,&y,&x,&s);
	long long phi=eular(s+1);
	size=4;
	mat A,B;
	A.m[1][1]=5;A.m[1][2]=5;A.m[1][3]=-1;
	A.m[2][1]=1;A.m[3][2]=1;A.m[4][1]=1;A.m[4][4]=1;
	B=QP(A,n*y-1,phi);
	long long g=4*B.m[4][1]+B.m[4][2]+B.m[4][4];
	long long a=(g+phi)%phi+phi;
	//printf(" %lld\n",g);
	//printf(" %lld\n",a);
	long long ans=qpow(x,a,s+1);
	printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}
