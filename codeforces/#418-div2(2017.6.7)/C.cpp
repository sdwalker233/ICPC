#include <bits/stdc++.h>
using namespace std;
int mp[30][1505];
vector<int> v[30];
string s;
int cnt[30],n;

int main()
{
	int i,j,k;
	cin >>n;
	cin>>s;
	i=1;
	for(auto it:s){
		v[it-'a'].push_back(i++);
		cnt[it-'a']++;
	}
	for(i=0;i<26;i++){
		//st[i].insert(0);
		if(cnt[i]) mp[i][0]=1;
		for(j=0;j<v[i].size();j++){
			for(k=j+1;k<v[i].size();k++){
				mp[i][v[i][k]-v[i][j]-(k-j)]=max(mp[i][v[i][k]-v[i][j]-(k-j)],v[i][k]-v[i][j]+1);
			}
		}
		int mx=0;
		for(j=1;j<=n;j++){
			mp[i][j]=max(mp[i][j],min(mp[i][j-1]+1,n));
		}
	}

	int q,m;
	char C[5];
	cin>>q;
	while(q-->0){
		scanf("%d%s",&m,C);
		int c=C[0]-'a';
		printf("%d\n",mp[c][m]);
	}
 return 0;
}

