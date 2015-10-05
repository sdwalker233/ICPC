#include<stdio.h>
#include<string.h>
int n,m,g[101][101],tree[;

 void run()
 {
 	int i,a,b;
 	memset(g,0,sizeof(int));
 	for(i=1;i<=n;i++){
 		scanf("%d%d",&a,&b);
 		g[a][b]=1;
 		g[b][a]=1;
 	}
 	tree_build(1,1);
int main()
{
	while(1){
		scanf("%d%d",&n,&m);
		if(n==-1&&m==-1) break;
		run();
	}
 return 0;
}

