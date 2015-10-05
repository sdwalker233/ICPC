#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> a[1000];
int n,from[1000];
bool use[1000];

 bool hungary(int x)
 {
 	int i;
 	for(i=0;i<a[x].size();i++)
 		if(!use[a[x][i]]){
 			use[a[x][i]]=1;
 			if(from[a[x][i]]==-1||hungary(from[a[x][i]])){
 				from[a[x][i]]=x;
 				return 1;
 			}
 		}
 	return 0;
 }

 void run()
 {
 	int i,j,x,t,tot=0;
 	for(i=0;i<n;i++){
 		scanf("%d: (%d)",&x,&x);
 		for(j=1;j<=x;j++){
 			scanf("%d",&t);
 			a[i].push_back(t);
 		}
 	}
 	memset(from,-1,sizeof(from));
 	for(i=0;i<n;i++){
 		memset(use,0,sizeof(use));
 		if(hungary(i)) tot++;
 	}
 	if(tot%2) tot++;
 	printf("%d\n",n-tot/2);
 	for(i=0;i<n;i++) a[i].clear();
 }

int main()
{
	while(scanf("%d",&n)!=EOF){
		run();
	}
 return 0;
}

