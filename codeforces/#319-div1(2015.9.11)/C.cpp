#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,v,num;
};
vector<node> a[1010][1010];

bool cmp(const node& x,const node& y)
{
	if(x.v!=y.v) return x.v<y.v;
	return x.x<y.x;
}

int main()
{
	int n,i,j,k,x,y;
	node tmp;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		x--;y--;
		tmp.v=x+y;
		tmp.num=i;
		a[x/1000][y/1000].push_back(tmp);
	}
	for(i=0;i<1000;i++){
		if(i%2==0)
			for(j=0;j<1000;j++){
				sort(a[i][j].begin(),a[i][j].end(),cmp);
				for(k=0;k<a[i][j].size();k++)
					printf("%d ",a[i][j][k].num);
			}
		else
			for(j=999;j>=0;j--){
				sort(a[i][j].begin(),a[i][j].end(),cmp);
				for(k=0;k<a[i][j].size();k++)
					printf("%d ",a[i][j][k].num);
			}
	}	
 return 0;
}


