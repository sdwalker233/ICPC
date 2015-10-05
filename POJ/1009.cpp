#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int wid,a[2][100001],p[2][100001],x[4]={1,1,1,0},y[4]={-1,0,1,1};

 int max(int x1,int x2)
 {
 	return x1>x2?x1:x2;
 }

 int figure()
 {
 	int i,j;
 	/*for(i=1;i<=wid;i++) printf("%d ",a[0][i]);
 	printf("\n");
 	for(i=1;i<=wid;i++) printf("%d ",a[1][i]);
 	printf("\n");*/
 	for(i=1;i<=3;i++){
 		p[0][1]=max(p[0][1],abs(a[0][1]-a[x[i]][1+y[i]]));
 		p[x[i]][1+y[i]]=max(p[x[i]][1+y[i]],abs(a[0][1]-a[x[i]][1+y[i]]));
 	}
 	for(i=2;i<wid;i++)
 		for(j=0;j<=3;j++){
 			p[0][i]=max(p[0][i],abs(a[0][i]-a[x[j]][i+y[j]]));
 			p[x[j]][i+y[j]]=max(p[x[j]][i+y[j]],abs(a[0][i]-a[x[j]][i+y[j]]));
 		}
 	for(i=0;i<=1;i++){
 		p[0][wid]=max(p[0][wid],abs(a[0][wid]-a[x[i]][wid+y[i]]));
 		p[x[i]][wid+y[i]]=max(p[x[i]][wid+y[i]],abs(a[0][wid]-a[x[i]][wid+y[i]]));
		}
 	/*for(i=1;i<wid;i++)
 		printf("%d ",p[0][i]);
 	printf("%d\n",p[0][wid]);*/
 }

 void run()
 {
 	long long left=0;
 	int i,n,pos=0,ok=0;
 	for(i=1;i<=wid;i++)
 		p[0][i]=p[1][i]=0;
 	while(1){
 		if(left==0) {
 			scanf("%d%lld",&n,&left);
 			if(!n&&!left) {
			 	for(i=1;i<wid;i++)
				 	printf("%d ",p[0][i]);
				printf("%d\n",p[0][wid]);
				break;
			}
 		}
 		a[1][++pos]=n;
 		left--;
 		printf("%lld\n",left);
 		if(pos==wid) {
 			if(ok) figure();
		 	for(i=1;i<=wid;i++){
		 		a[0][i]=a[1][i];
		 		p[0][i]=p[1][i];
		 		p[1][i]=0;
		 	}
		 	pos=0;
			 //printf("left=%d\n",left);
		 	ok=1;
		 	}
		 }
 }

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	clock_t begin;
	while(scanf("%d",&wid)){
		begin=clock();
		run();
		printf("time=%d\n",clock()-begin);
	}
 return 0;
}

