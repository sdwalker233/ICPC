#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct mat{
	double m[62][62];
	mat(){
		memset(m,0,sizeof(m));
	}
};
int m,n,size;
double x;

mat multiply(mat a,mat b)
{
    mat tmp;
    int i,j,k;
	for(k=1;k<=size;k++)
		for(i=1;i<=size;i++)
			for(j=1;j<=size;j++)
				tmp.m[i][j]=(tmp.m[i][j]+a.m[i][k]*b.m[k][j]);
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
	int i,j;
	double c,s;
	mat A;
	scanf("%d%d%lf",&m,&n,&x);
	c=cos(x);s=sin(x);
	for(i=1;i<=m;i++){
		A.m[i][i]=c;
		if(i<m) A.m[i][i+1]=c;
		A.m[i+m][i]=s;
		if(i<m) A.m[i+m][i+1]=s;
		A.m[i][i+m]=-s;
		A.m[i+m][i+m]=c;
	}
	size=2*m;
	/*for(i=1;i<=size;i++){
		for(j=1;j<=size;j++)
			printf("%.3lf ",A.m[i][j]);
		printf("\n");
	}*/
	A=quick_power(A,n-1);
	printf("%lf\n",A.m[1][m]*c+A.m[1][2*m]*s);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}

