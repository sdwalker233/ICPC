#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n,i,a,d,j,cnt=0;
	int b[100010],c[100010];
	vector<int> va[100010];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		va[a].push_back(i);
	}
	for(i=1;i<=100000;i++){
		if(va[i].size()==0) continue;
		if(va[i].size()==1){
			cnt++;
			b[cnt]=i;c[cnt]=0;
			continue;
		}
		d=va[i][1]-va[i][0];
		for(j=1;j<va[i].size();j++){
			if(d!=va[i][j]-va[i][j-1]) break;
		}
		if(j>=va[i].size()){
			cnt++;
			b[cnt]=i;c[cnt]=d;
			continue;
		}
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++)
		printf("%d %d\n",b[i],c[i]);
 return 0;
}

