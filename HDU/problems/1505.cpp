#include<stdio.h>
#include<string.h>
struct node{
	int x,y;
}p[1000001];
int n,m,count,pos[1001];

 int max(int x,int y)
 {
 	return x>y?x:y;
 }

 void run()
 {
 	int i,j,y1,y2,ans=0;
 	char s[5];
 	scanf("%d%d",&n,&m);
 	p[0].x=0;p[0].y=0;
	p[1].x=0;p[1].y=m+1;
 	count=2;pos[0]=0;
 	for(i=1;i<=n;i++){
 		pos[i]=count+1;
 		for(j=1;j<=m;j++){
 			scanf("%s",s);
 			if(s[0]=='R'){
 				++count;
 				p[count].x=i;
 				p[count].y=j;
 			}
 		}
 	}
 	pos[n+1]=++count;
 	p[count].x=n+1;p[count].y=0;
 	++count;
 	p[count].x=n+1;p[count].y=m+1;
 	for(i=0;i<=count&&p[i].x<n;i++){
 		y1=0;y2=m+1;
 		for(j=pos[p[i].x+1];j<=count;j++){
 			//printf("%d,%d  %d,%d  %d,%d  %d\n",p[i].x,p[i].y,p[j].x,p[j].y,y1,y2,ans);
 			if(ans>=(n-p[i].x)*(y2-y1-1)) break;
 			ans=max(ans,(p[j].x-p[i].x-1)*(y2-y1-1));
 			if(p[j].y<y2&&p[j].y>=p[i].y) y2=p[j].y;
 			if(p[j].y>y1&&p[j].y<p[i].y) y1=p[j].y;
 		}
 	}
 	printf("%d\n",ans*3);	
 }
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		run();
 return 0;
}

