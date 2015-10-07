#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
	int x[5],num;
	int step;
};
int x[5],y;

int tran(int x[])
{
	return x[4]+x[3]*10+x[2]*100+x[1]*1000;
}

int BFS()
{
	bool vis[10010]={0};
	int i;
	queue<node> q;
	node tmp,now;
	memcpy(tmp.x,x,sizeof(x));
	tmp.num=tran(tmp.x);
	tmp.step=0;
	vis[tmp.num]=1;
	q.push(tmp);
	while(!q.empty()){
		now=q.front();
		q.pop();
		if(now.num==y) return now.step;
		for(i=1;i<=4;i++){
			tmp=now;tmp.step++;
			tmp.x[i]++;
			if(tmp.x[i]>9) tmp.x[i]=1;
			tmp.num=tran(tmp.x);
			if(!vis[tmp.num]){
				vis[tmp.num]=1;
				q.push(tmp);
			}

			tmp=now;tmp.step++;
			tmp.x[i]--;
			if(tmp.x[i]<1) tmp.x[i]=9;
			tmp.num=tran(tmp.x);
			if(!vis[tmp.num]){
				vis[tmp.num]=1;
				q.push(tmp);
			}
		}
		for(i=1;i<4;i++){
			tmp=now;tmp.step++;
			swap(tmp.x[i],tmp.x[i+1]);
			tmp.num=tran(tmp.x);
			if(!vis[tmp.num]){
				vis[tmp.num]=1;
				q.push(tmp);
			}
		}
	}
}

void fuck()
{
	int i;
	for(i=1;i<=4;i++) scanf("%1d",&x[i]);
	scanf("%d",&y);
	printf("%d\n",BFS());
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}