#include<iostream>
#include<stdio.h>
#include<string>
#define MOD 1000000007
using namespace std;

 long long inv(long long a)
 {
  long long b=MOD,b0=b,t,q,x0=0,x1=1;
  if (b==1) return 1;
  while (a>1)
  {
    q=a/b;
    t=b,b=a%b,a=t;
    t=x0,x0=x1-q*x0,x1=t;
  }
  if (x1<0) x1+=b0;
  return x1;
 }

 int cal(int p,int c)
 {
 	int z;
	long long i,a=1;
 	for(i=p+2;i<=p*2;i++)
 		a=(a*i)%MOD;
 	for(i=c+1;i<=p+c;i++)
 		a=(a*i)%MOD;
 	for(i=1;i<=p;i++){
 		z=inv(i);
 		a=(a*z)%MOD;
 		a=(a*z)%MOD;
 	}
 	return a;
 }

int main()
{
	string s;
	int n,c,p,ans,i;
	while(scanf("%d",&n)!=EOF){
		getchar();
		c=0;
		getline(cin,s);
		for(i=0;i<s.length();i++){
			if(s[i]=='(') c++;
			else if(c==0) break;
				else c--;
		}
		if(n%2||i<s.length()){
			printf("0\n");
			continue;
		}
		n-=s.length();
		p=(n-c)/2;
		printf("%d\n",cal(p,c));
	}
 return 0;
}

