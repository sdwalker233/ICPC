#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#define MAXN 100010
using namespace std;
int n,m,a[MAXN],f[MAXN][20];

int getv(int pos,int len)
{
	int i=0;
	while(len){
		if(len&1) pos=f[pos][i];
		i++;
		len>>=1;
	}
	return pos;
}

int find(int pos,int v)
{
	int l=1,r=n,mid,res=n+1,p;
	while(l<=r){
		mid=(l+r)>>1;
		p=getv(pos,mid);
		if(a[p]>v){
			l=mid+1;
		}
		else{
			res=min(p,res);
			r=mid-1;
		}
	}
	return res;
}

void fuck()
{
	int i,j,l,r,p,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	stack<int> st;
	a[n+1]=-1;f[n+1][0]=n+1;
	for(i=1;i<=n+1;i++){
		while(!st.empty()&&a[st.top()]>=a[i]){
			f[st.top()][0]=i;
			st.pop();
		}
		st.push(i);
	}
	//for(i=1;i<=n;i++) printf(" %d",f[i][0]);
	//puts("");
	for(i=1;i<=18;i++)
		for(j=1;j<=n+1;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	scanf("%d",&m);
	while(m-->0){
		scanf("%d%d",&l,&r);
		v=a[l];p=l;
		while(1){
			p=find(p,v);
			//printf(" %d %d\n",v,p);
			if(p>r) break;
			if(a[p]==0){
				v=0;
				break;
			}
			v%=a[p];
		}
		printf("%d\n",v);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

