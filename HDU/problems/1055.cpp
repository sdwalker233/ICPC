#include<stdio.h>
#include<string.h>
int n,r,cost[1001],head[1001],sum[1001],now;
bool visit[1001];
struct node{
	int next,w;
}list[2001];

 void add_list(int x,int y)
 {
 	int p=head[x];
 	if(p==0){
 		head[x]=now;
 		list[now++].w=y;
 		return;
 	}
 	while(list[p].next) p=list[p].next;
 	list[p].next=now;
 	list[now++].w=y;
 }

 int cal_sum(int x)
 {
 	int p=head[x];
 	while(p){
 		if(!visit[p]){
 			visit[p]=1;
 			sum[x]+=cal_sum(p);
 		}
 		p=list[p].next;
 	}
 	return sum[x];
 }

 void run()
 {
 	int i,x,y;
 	now=1;
 	memset(head,0,sizeof(head));
 	memset(sum,0,sizeof(sum));
 	memset(visit,0,sizeof(visit));
 	for(i=1;i<n;i++) scanf("%d",&cost[i]);
 	for(i=1;i<n;i++){
 		scanf("%d%d",&x,&y);
 		add_list(x,y);
 		add_list(y,x);
 	}
 	for(i=1;i<now;i++)
 		printf("%d %d\n",list[i].w,list[i].next);
 	cal_sum(r);
 	for(i=1;i<n;i++)
 		printf("%d\n",sum[i]);
 }
int main()
{
	while(scanf("%d%d",&n,&r)!=EOF){
		run();
	}
 return 0;
}

