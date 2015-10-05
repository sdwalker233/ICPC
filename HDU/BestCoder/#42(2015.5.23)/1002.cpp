#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int h,num,f;
	bool operator<(node x)const	{
		return h<x.h;
	}
}bird[200010];
int n,m;
queue<int> a[200010];

 inline bool cmp2(node x,node y)
 {
 	return x.num<y.num;
 }

 int read()
 {
 	int x=0;
 	char c=getchar();
 	while(c>'9'||c<'0') c=getchar();
 	while(c<='9'&&c>='0'){
 		x*=10;
 		x+=c-'0';
 		c=getchar();
 	}
 	return x;
 }

int main()
{
	int i,p;
	int q;
	bird[0].h=-1;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=100000;i++)
			while(!a[i].empty()) a[i].pop();
		for(i=1;i<=n+m;i++){
			bird[i].h=read();
			bird[i].num=i;
		}
		sort(bird+1,bird+n+m+1);
		p=0;
		for(i=1;i<=n+m;i++){
			if(bird[i-1].h!=bird[i].h) ++p;
			bird[i].f=p;
		}
		sort(bird+1,bird+n+m+1,cmp2);
		for(i=1;i<=n;i++)
			a[bird[i].f].push(i);
		for(i;i<=m+n;i++){
			p=bird[i].f;
			if(a[p].empty()) printf("-1\n");
			else{
				printf("%d\n",a[p].front());
				a[p].pop();
			}			
		}
	}
 return 0;
}

