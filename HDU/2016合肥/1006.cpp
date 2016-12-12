#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,t;
}a[400010];
int n,m,k,c;
set<pair<int,int> > st;
bool f;

void check1()
{
	int i,j;
	for(i=1;i<=2*c;i++){
		if(a[i].c) continue;
		for(j=i;a[j].c==0&&a[j].x==a[i].x;j++);
		j--;
		if(j-i+1>=k){
			f=1;
			return;
		}
		if(j-i+k==k-1){
			if(a[i-1].x==a[i].x&&a[i-1].y!=a[i].y-1&&a[i].y>1)
				st.insert(make_pair(a[i].x,a[i].y-1));
			if(a[j+1].x==a[j].x&&a[j+1].y!=a[j].y+1&&a[j].y<m)
				st.insert(make_pair(a[j].x,a[j].y+1));
		}
		if(j-i+k==k-2){
			if(
				(a[i-1].x==a[i].x&&a[i-1].y!=a[i].y-1&&a[i].y>1)
				&&
				(a[j+1].x==a[j].x&&a[j+1].y!=a[j].y+1&&a[j].y<m)
			  ) return 1;
		}
	}
}

bool check2()
{
	int i,j;
	for(i=1;i<=2*c;i++){
		if(a[i].c) continue;
		for(j=i;a[j].c==0&&a[j].x==a[i].x;j++);
		j--;
		if(j-i+1>=k) return 1;
		if(j-i+k==k-1){
			if(
				(a[i-1].x==a[i].x&&a[i-1].y!=a[i].y-1&&a[i].y>1)
				||
				(a[j+1].x==a[j].x&&a[j+1].y!=a[j].y+1&&a[j].y<m)
			  ) return 1;
		}
		if(j-i+k==k-2){
			if(
				(a[i-1].x==a[i].x&&a[i-1].y!=a[i].y-1&&a[i].y>1)
				&&
				(a[j+1].x==a[j].x&&a[j+1].y!=a[j].y+1&&a[j].y<m)
			  ) return 1;
		}
	}
}

bool cmp1(const node& x,const node& y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}

void fuck()
{
	int i,j;
	f=0;
	st.clear();
	scanf("%d%d%d%d",&n,&m,&k,&c);
	for(i=1;i<=c;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].t=0;
	}
	for(i=1+c;i<=c+c;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].t=1;
	}
	sort(a+1,a+2*c+1,cmp1);
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

