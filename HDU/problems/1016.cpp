#include<stdio.h>
int n,ring[20];
bool mark[20]={0},p[41]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0};

 void DFS(int step)
 {
 	int i;
 	if(step>n){
 			//for(i=1;i<n;i++)
 				//printf("%d ",ring[i]);
 			//printf("%d\n",ring[n]);
 		if(p[ring[n]+ring[1]]){
 			for(i=1;i<n;i++)
 				printf("%d ",ring[i]);
 			printf("%d\n",ring[n]);
 		}
 		return;
 	}
 	for(i=2;i<=n;i++){
 		if(mark[i]||!p[ring[step-1]+i]) continue;
 		mark[i]=1;
 		ring[step]=i;
 		DFS(step+1);
 		mark[i]=0;
 	}	
 }

int main()
{
	int i=1;
	ring[1]=1;
	mark[1]=1;
	while(scanf("%d",&n)!=EOF){
		printf("Case %d:\n",i++);
		DFS(2);
		printf("\n");
	}
 return 0;
}

