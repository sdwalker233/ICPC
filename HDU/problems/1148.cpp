#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p;
bool ok=0;

int f(char s[])
{
	if(strcmp(s,"rock")==0) return 0;
	if(strcmp(s,"paper")==0) return 1;
	if(strcmp(s,"scissors")==0) return -1;
}

void fuck()
{
	if(ok) printf("\n");
	ok=1;
	int i;
	int w[110]={0},l[110]={0},a,b,x,y;
	char s1[10],s2[10];
	scanf("%d",&p);
	for(i=1;i<=p;i++){
		scanf("%d%s%d%s",&x,s1,&y,s2);
		a=f(s1);b=f(s2);
		//printf(" %d %d\n",x,y);
		if((a>0&&b==0)||(a==0&&b<0)||(a<0&&b>0)){
			w[x]++;l[y]++;
		}
		else if((a<0&&b==0)||(a==0&&b>0)||(a>0&&b<0)){
			w[y]++;l[x]++;
		}
	}
	for(i=1;i<=n;i++){
		if(w[i]+l[i]==0) printf("-\n");
		else printf("%.3lf\n",(double)w[i]/(w[i]+l[i]));
	}
		
}

int main()
{
	while(~scanf("%d",&n)&&n){		
		fuck();
	}
 return 0;
}

