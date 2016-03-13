#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
struct node
{
	int v,index;
	node(int _v,int _index){
		v=_v;
		index=_index;
	}
};
int n,q,a[100010],x,y,b[100010];
int l[100010],r[100010];

int abs(int x)
{
	return x>0?x:-x;
}

void fuck()
{
	int i,l,r,k;
	long long sum=0;
	stack<node> s;
	node now;
	while(!s.empty()) s.pop();
	for(i=x;i<y;i++){
		if(s.empty()) s.push(node(b[i],i));
		else{
			while(!s.empty()){
				now=s.top();
				if(now.v>)
			}
			
		}
	}
	cout<<sum<<endl;
}

int main()
{
	int i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i-1]=abs(a[i-1]-a[i]);
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		fuck();
	}
 return 0;
}