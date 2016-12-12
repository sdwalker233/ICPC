#include <bits/stdc++.h>
using namespace std;
set<int> st;
vector<int> ans;
long long extend_gcd(long long a,long long b,long long &x,long long &y)
{  
    long long d;  
    if(b==0){  
        x=1;y=0;  
        return a;  
    }  
    d=extend_gcd(b,a%b,y,x);  
    y-=a/b*x;
    return d;  
}

int main()
{
	bool f=1;
	int n,i;
	scanf("%d",&n);
	if(n==4){
		printf("YES\n1\n3\n2\n4\n");
		return 0;
	}
	st.insert(1);
	ans.push_back(1);
	for(i=2;i<n;i++){
		long long x,y;
		long long g=extend_gcd(i-1,n,x,y);
		//x=(x+i-1)%(i-1);
		//if(g<0) g=-g;
		x*=i/g;
		x=(x%n+n)%n;
		if(st.find(x)!=st.end()||i%g){
			f=0;
			break;
		}
		ans.push_back(x);
	}
	if(n>1){
		if(st.find(n)!=st.end()) f=0;
		ans.push_back(n);
	}
	if(f==0) printf("NO\n");
	else{
		printf("YES\n");
		for(auto it:ans)
			cout<<it<<endl;
	}
 return 0;
}

