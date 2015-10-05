#include<stdio.h>
#include<math.h>
int n;
typedef struct node1{
	double x;
	double y;
}coordinate;
typedef struct node2{
	double xx;
	double yy;
	double r;
	coordinate pp[3];
}circle;
coordinate a[500];
 
 void printans(circle p)
 {
 	printf("%.2f %.2f\n%.2f\n%.2f %.2f %.2f %.2f %.2f %.2f\n\n",
	 p.xx,p.yy,p.r,p.pp[0].x,p.pp[0].y,p.pp[1].x,p.pp[1].y,p.pp[2].x,p.pp[2].y);
 }
 
 double distance(coordinate d,circle p)
 {
 	return (d.x-p.xx)*(d.x-p.xx)+(d.y-p.yy)*(d.y-p.yy);
 }

 bool in(coordinate d,circle p)
 {
 	if((d.x-p.xx)*(d.x-p.xx)+(d.y-p.yy)*(d.y-p.yy)>p.r*p.r) return 0;
 	return 1;
 }

 circle figure(coordinate d1,coordinate d2,coordinate d3)
 {
 	int ok=0;
 	double l[4]={0,(d2.x-d3.x)*(d2.x-d3.x)+(d2.y-d3.y)*(d2.y-d3.y),
	 	          (d1.x-d3.x)*(d1.x-d3.x)+(d1.y-d3.y)*(d1.y-d3.y),
		          (d1.x-d2.x)*(d1.x-d2.x)+(d1.y-d2.y)*(d1.y-d2.y)
			   };
	double c1,c2;
	circle t;
	if(l[2]+l[3]<l[1]) ok=1;
	if(l[1]+l[3]<l[2]) ok=2;
	if(l[1]+l[2]<l[3]) ok=3;
	t.pp[0].x=d1.x;t.pp[0].y=d1.y;
	t.pp[1].x=d2.x;t.pp[1].y=d2.y;
	t.pp[2].x=d3.x;t.pp[2].y=d3.y;
	//printf("%d\n",ok);
	if(ok){	//钝角三角形
		if(ok==1) {t.xx=(d2.x+d3.x)/2;
		           t.yy=(d2.y+d3.y)/2;
				   }
		if(ok==2) {t.xx=(d1.x+d3.x)/2;
		           t.yy=(d1.y+d3.y)/2;
				   }
		if(ok==3) {t.xx=(d1.x+d2.x)/2;
				   t.yy=(d1.y+d2.y)/2;
				   }
		t.r=sqrt(l[ok])/2;
		return t;
	}
	
	
	 c1=(d1.x*d1.x+d1.y*d1.y-d2.x*d2.x-d2.y*d2.y)/2;
     c2=(d1.x*d1.x+d1.y*d1.y-d3.x*d3.x-d3.y*d3.y)/2;

     t.xx = (c1 * (d1.y - d3.y) - c2 * (d1.y - d2.y)) /
            ((d1.x - d2.x) * (d1.y - d3.y) - (d1.x - d3.x) * (d1.y - d2.y));
     t.yy = (c1 * (d1.x - d3.x) - c2 * (d1.x - d2.x)) /
            ((d1.y - d2.y) * (d1.x - d3.x) - (d1.y - d3.y) * (d1.x - d2.x));
   	 t.r=sqrt((d1.x-t.xx)*(d1.x-t.xx)+(d1.y-t.yy)*(d1.y-t.yy));
	return t;
 }

 circle modify(coordinate d,circle p)
 {
 	circle q,max;
 	max.r=-1;
 	q=figure(p.pp[0],p.pp[1],d);
	//printf("p01\n");printans(q);
	if(in(p.pp[2],q)&&q.r>max.r) max=q;
 	q=figure(p.pp[0],p.pp[2],d);
	//printf("p02\n");printans(q);
	if(in(p.pp[1],q)&&q.r>max.r) max=q;
	q=figure(p.pp[1],p.pp[2],d);
	//printf("p12\n");printans(q);
	if(in(p.pp[0],q)&&q.r>max.r) max=q;
 	//if(max.r==-1)
	// 	printf("%d %d %d %d %d %d\n",
	//	        p.pp[0].x,p.pp[0].y,p.pp[1].x,p.pp[1].y,p.pp[2].x,p.pp[2].y);
	return max;
 }

 void init()
 {
 	int i,j,maxi;
 	bool visited[500]={0};
 	double maxdis;
 	circle ans;
	scanf("%lf%lf",&a[1].x,&a[1].y);
	if(n==1){
		printf("%.2lf %.2lf 0.00\n",a[1].x,a[1].y);
		return;
	}
	for(i=2;i<=n;i++){
 		scanf("%lf%lf",&a[2].x,&a[2].y);
		if(a[2].x==a[1].x&&a[2].y==a[1].y){
			n--;
			i--;
		}
		else break;
	}
 	for(i=3;i<=n;i++){
 		scanf("%lf%lf",&a[i].x,&a[i].y);
		if((a[i].x==a[1].x&&a[i].y==a[1].y)||(a[i].x==a[2].x&&a[i].y==a[2].y)){
			i--;
			n--;
		}
	}
	if(n==1){
		printf("%.2lf %.2lf 0.00\n",a[1].x,a[1].y);
		return;
	}
	if(n==2){
		printf("%.2lf %.2lf %.2lf\n",(a[1].x+a[2].x)/2,(a[1].y+a[2].y)/2,
		sqrt((a[1].x-a[2].x)*(a[1].x-a[2].x)+(a[1].y-a[2].y)*(a[1].y-a[2].y))/2);
		return;
	}
	
 	ans=figure(a[1],a[2],a[3]);
 	visited[1]=1;visited[2]=1;visited[3]=1;
 	//printans(ans);
 	while(1){
 		maxdis=-1;
 		for(i=1;i<=n;i++)
 			if(!visited[i]&&distance(a[i],ans)>maxdis){
 				maxdis=distance(a[i],ans);
 				maxi=i;
 			}
 	 	
 		if(maxdis==-1) break;
 		visited[maxi]=1;
 		if(in(a[maxi],ans)) break;
 		ans=modify(a[maxi],ans);
 	}
 	printf("%.2lf %.2lf %.2lf\n",ans.xx,ans.yy,ans.r);
 }

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out1.txt","w",stdout);
	while(1){
		scanf("%d",&n);
		if(n==0) return 0;
		init();
	}
}

