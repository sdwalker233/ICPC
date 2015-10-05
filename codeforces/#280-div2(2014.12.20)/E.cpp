#include<stdio.h>
struct node{
	int x,y;
	bool visit;
}p[100001];

int main()
{
	int n,m,dx,dy,i,j;
	int max=0,maxi,xn,yn,count;
	scanf("%d%d%d%d",&n,&m,&dx,&dy);
	for(i=1;i<=m;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].visit=0;
	}
	for(i=1;i<=m;i++){
		if(p[m].visit==1) continue;
		xn=p[i].x;yn=p[i].y;count=0;
		do{
			xn=(xn+dx)%n;
			yn=(yn+dy)%n;
			for(j=1;j<=m;j++)
				if(xn==p[j].x&&yn==p[j].y){
					count++;
					p[j].visit=1;
				}
		}while(xn!=p[i].x||yn!=p[i].y);
		if(count>max){
			max=count;
			maxi=i;
		}
	}
	printf("%d %d\n",p[maxi].x,p[maxi].y);
 return 0;
}

