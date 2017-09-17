#include <bits/stdc++.h>
using namespace std;

int f()
{
	string s;
	int i,a,b,l,r;
	cin>>a>>b>>l>>r;
	if(l==r) return 1;
	if(l<=a+b){
		if(r<=a+b) return r-l+1;
		if(r<=2*a+b) return a+b-l+1;
		if(r<=2*a+b+b){
			return min(a+b-l+1+r-2*a-b,a+b);
		}
		if(a>b) return min(a-l+1+b,a);
		return b+1;
	}
	l-=a+b+1;
	r-=a+b+1;
	int p1=l/(a+b),r1=l%(a+b);
	int p2=r/(a+b),r2=r%(a+b);
	bool f1=(r1>=a),f2=(r2>=a);
	printf(" %d %d %d %d %d %d\n",p1,r1,f1,p2,r2,f2);
	if(!f1&&!f2&&p1==p2) return 1;
	if(!f1&&!f2&&p1!=p2) return b+1;
	if(f1&&f2){
		if(p1==p2) return r-l+1;
		if(p2-p1>1) return b+1;
		for(i=1;i<=a;i++) s+='a';
		for(i=1;i<=b;i++) s+='a'+i-1;
		for(i=1;i<=a;i++) s+='a'+b-1;
		for(i=1;i<=b;i++) s+='a'+i;
		int cnt[30]={0},aaa=0;
		for(i=r1;i<=r2+a+b;i++) cnt[s[i]-'a']++;
		for(i=0;i<26;i++) aaa+=(cnt[i]>0);
		return aaa;
	}
	if(!f1&&f2){
		if(p1==p2) return r2-a+2;
		return b+1;
	}
	if(f1&&!f2){
		if(p1+1==p2) return a+b-r1;
		return b+1;
	}

 return 0;
}

int main()
{
	cout<<f()<<endl;
 return 0;
}



