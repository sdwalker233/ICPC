#include<bits/stdc++.h>
using namespace std;
char s[510][510];
int dp1[510][510]={0},dp2[510][510]={0};

int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%s",&s[i][1]);
		for(j=2;j<=m;j++){
			dp1[i][j]=dp1[i][j-1];
			if(s[i][j-1]=='.'&&s[i][j]=='.') dp1[i][j]++;
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			dp2[j][i]=dp2[j-1][i];
			if(s[j][i]=='.'&&s[j-1][i]=='.') dp2[j][i]++;
		}
	}
	int q,x1,x2,y1,y2;
	scanf("%d",&q);
	while(q-->0){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		long long ans=0;
		if(y1!=y2)
		for(i=x1;i<=x2;i++){
			ans+=dp1[i][y2]-dp1[i][y1];
		}
		if(x1!=x2)
		for(i=y1;i<=y2;i++){
			ans+=dp2[x2][i]-dp2[x1][i];
		}
		cout<<ans<<endl;
	}
 return 0;
}


