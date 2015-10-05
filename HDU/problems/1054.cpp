#include<stdio.h>
#include<string.h>
int n,g[1500][1500],count[1500];

 void run()
 {
 	int i,j,w1,w2,m,k,ans=0;
 	memset(g,0,sizeof(g));
 	memset(count,0,sizeof(count));
 	for(i=1;i<=n;i++){
 		scanf("%d:(%d)",&w1,&m);
 		for(j=1;j<=m;j++){
 			scanf("%d",&w2);
 			g[w1][w2]=g[w2][w1]=1;
 			count[w1]++;
 			count[w2]++;
 		}
 	}
 	//for(i=0;i<n;i++)
 		//printf("count[%d]=%d\n",i,count[i]);
 	while(1){
 		for(i=0;i<n;i++){
 			if(count[i]==1){
 				for(j=0;j<n;j++)
 					if(g[i][j]) break;
 				g[i][j]=0;
 				count[i]=count[j]=0;
 				for(k=0;k<n;k++)
 					if(g[j][k]){
 						g[j][k]=0;
 						g[k][j]=0;
 						count[k]--;
 					}
 				break;
 			}
 		}
 		if(i>=n) break;
 		ans++;
 	}
 	printf("%d\n",ans);
 }
int main()
{
	while(scanf("%d",&n)!=EOF){
		run();
	}
 return 0;
}

