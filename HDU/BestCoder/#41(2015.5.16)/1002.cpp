#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
map<string,int> mm;
 int gcd(int x,int y)
 {
 	if(y==0) return x;
 	return gcd(y,x%y);
 }

 void  run()
 {
 	int n,i,m=0,p=0,q,r;
 	mm.clear();
 	string s[20001];
 	scanf("%d",&n);
 	for(i=1;i<=n;i++){
 		cin>>s[i];
 		mm[s[i]]++;
 		if(s[i].length()%2==0) m++;
 	}
 	for(i=1;i<=n;i++){
 		p+=mm[s[i]]*(mm[s[i]]-1)/2;
 		mm[s[i]]=1;
 	}
 	q=(n*(n-1))/2;
 	p+=m*(n-m);
 	r=gcd(p,q);
 	if(r==0){
 		printf("0/1\n");
 		return;
 	}
 	printf("%d/%d\n",p/r,q/r);
 }
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		run();
 return 0;
}

