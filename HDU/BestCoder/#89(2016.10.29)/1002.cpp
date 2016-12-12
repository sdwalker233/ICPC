#include <bits/stdc++.h>
using namespace std;
int x,k,t;
int dp[1000010];
void fuck()
{
	int i;
	deque<int> qu;
	scanf("%d%d%d",&x,&k,&t);
	//memset(dp,-1,sizeof(dp));
	if(t==0){
		dp[1]=0;
		for(i=1;i<=x;i++){
			if(i*k<=x) dp[i*k]=dp[i]+1;
		}
		printf("%d\n",dp[x]);
		return;
	}
	dp[1]=0;qu.push_back(1);
	for(i=2;i<=x;i++){
		while(qu.front()<i-t) qu.pop_front();
		dp[i]=dp[qu.front()]+1;
		if(i%k==0) dp[i]=min(dp[i],dp[i/k]+1);
		while(!qu.empty()&&dp[qu.back()]>dp[i])
			qu.pop_back();
		qu.push_back(i);
	}
	printf("%d\n",dp[x]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

