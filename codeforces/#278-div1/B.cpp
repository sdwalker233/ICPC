#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n,s,l;
int a[MAXN],b[MAXN],dp[MAXN];
multiset<int> st;
multiset<int>::iterator it1,it2;

int main()
{
	int i,j,end;
	scanf("%d%d%d",&n,&s,&l);
	memset(dp,-1,sizeof(dp));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		//printf("%d %d ",end,st.size());
		if(st.empty()){
			st.insert(a[i]);
			end=i;
		}
		it1=st.begin();
		it2=st.end();it2--;
		int mn=*it1,mx=*it2;
		//printf(" %d %d ",*it1,*it2);
		if(mx-mn<=s){
			while(end<n&&a[end+1]-mn<=s&&mx-a[end+1]<=s){
				++end;
				st.insert(a[end]);
				mn=min(mn,a[end]);
				mx=max(mx,a[end]);
			}
			b[i]=end;
		}
		st.erase(st.find(a[i]));
		//printf(" %d\n",b[i]);
	}
	//for(i=1;i<=n;i++) printf("%d ",b[i]);
	//printf("\n");
	end=1;dp[0]=0;
	for(i=1;i<=n;i++){
		if(dp[i-1]==-1) continue;
		//printf("%d\n",dp[i]);
		/*if(dp[i]==0){
			dp[i]=dp[i-1]+1;
			end=i+1;
		}*/
		for(end=max(end,i+l-1);end<=b[i];end++)
			dp[end]=dp[i-1]+1;
	}
	//for(i=1;i<=n;i++) printf("%d ",dp[i]);
	//printf("\n");
	printf("%d\n",dp[n]);
 return 0;
}

