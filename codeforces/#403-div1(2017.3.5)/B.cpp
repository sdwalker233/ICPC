#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
struct node{
	int x,y,index,b;
}a[MAXN];
set<int> st;
queue<int> qu;
int n,vis[20000];
char ss1[MAXN][5],ss2[MAXN][5];

bool cmp1(const node &x, const node &y)
{
	return x.x<y.x;
}

bool cmp2(const node &x, const node &y)
{
	return x.index<y.index;
}

int main()
{
	int i;
	char s1[22],s2[22];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s%s",s1,s2);
		a[i].index=i;a[i].b=-1;
		a[i].x=(s1[0]-'A')+(s1[1]-'A')*26+(s1[2]-'A')*26*26;
		a[i].y=(s1[0]-'A')+(s1[1]-'A')*26+(s2[0]-'A')*26*26;
		ss1[i][0]=ss2[i][0]=s1[0];
		ss1[i][1]=ss2[i][1]=s1[1];
		ss1[i][2]=s1[2];ss2[i][2]=s2[0];
		ss1[i][3]=ss2[i][3]=0;
	}
	sort(a+1,a+1+n,cmp1);
	a[0].x=a[n+1].x=-1;
	for(i=1;i<=n;i++){
		if(a[i].x==a[i-1].x||a[i].x==a[i+1].x||a[i].x==a[i].y){
			a[i].b=2;
			if(vis[a[i].y]){
				printf("NO\n");
				return 0;
			}
			vis[a[i].y]=1;
			qu.push(a[i].y);
		}
	}
	while(!qu.empty()){
		int now=qu.front();
		qu.pop();
		for(i=1;i<=n;i++){
			if(a[i].b>=0) continue;
			if(vis[a[i].x]){
				a[i].b=2;
				if(vis[a[i].y]){
					printf("NO\n");
					return 0;
				}
				vis[a[i].y]=1;
				qu.push(a[i].y);
			}
		}
	}
	sort(a+1,a+1+n,cmp2);
	printf("YES\n");
	for(i=1;i<=n;i++){
		if(a[i].b==2) printf("%s\n",ss2[i]);
		else printf("%s\n",ss1[i]);
	}
 return 0;
}

