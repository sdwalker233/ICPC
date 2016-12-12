#include <bits/stdc++.h>
using namespace std;
int a,p,q,l;
vector<int> fact;

inline int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

void fuck()
{
	int i;
	fact.clear();
	for(i=1;i*i<=a;i++){
		if(a%i) continue;
		fact.push_back(i);
		if(i*i!=a) fact.push_back(a/i);
	}
	for(auto g:fact){
		if(l%g) continue;
		int n=a/g,m=l/g;
		if(n*n<4*m) continue;
		int r=sqrt(1.0*n*n-4.0*m);
		if(r*r!=n*n-4*m) continue;
		if((n-r)%2||n-r<0) continue;
		int p=(n-r)/2,q=(n+r)/2;
		if(gcd(p,q)>1) continue;
		printf("%d %d\n",(n-r)/2*g,(n+r)/2*g);
		return;
	}
	printf("No Solution\n");
}

int main()
{
	while(~scanf("%d%d",&a,&l)) fuck();	
 return 0;
}

