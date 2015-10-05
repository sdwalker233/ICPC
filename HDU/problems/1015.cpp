#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int l,ans[5];
long long n;
char s[15];
bool ok,mark[15]={0};

  bool cmp(char x,char y)
 {
 	return x>y;
 }

 void DFS(int step,long long sum)
 {
 	int i,j,p;
 	if(step==5){
 			//for(i=0;i<=4;i++)
				//printf("%c",ans[i]+'A'-1);
 			//printf(" %lld\n",sum);
 		if(sum==n) ok=1;
		return;
	}
 	for(i=0;i<l;i++)
 		if(!ok&&!mark[i]){
 			ans[step]=s[i]-'A'+1;
 			p=1;
 			for(j=0;j<=step;j++)
 				p*=ans[step];
 			if(step%2) p=0-p;
 			mark[i]=1;
 		 	DFS(step+1,sum+p);
 		 	mark[i]=0;
 		}
 }

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i;
	while(scanf("%I64d%s",&n,s),n){
		l=strlen(s);
		sort(s,s+l,cmp);
		//puts(s);
		ok=0;
		DFS(0,0);
		if(ok){
			for(i=0;i<=4;i++)
				printf("%c",ans[i]+'A'-1);
			printf("\n");
		}
		else printf("no solution\n");
	}
 return 0;
}

