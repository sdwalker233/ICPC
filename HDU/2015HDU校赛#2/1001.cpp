#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[110][50];

void fuck()
{
	int i,j,k,l1,l2;
	bool b[110]={0};
	for(i=1;i<=n;i++)
		scanf("%s",&s[i][1]);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++){
			l1=strlen(&s[i][1]);
			l2=strlen(&s[j][1]);
			if(l1!=l2) continue;
			int cnt=0;
			for(k=1;k<=l1;k++){
				if(s[i][k]==s[j][k]||s[i][k]-s[j][k]==32||s[i][k]-s[j][k]==-32)
					cnt++;
			}
			if(cnt>2) b[i]=b[j]=1;
		}
	int ans=0;
	for(i=1;i<=n;i++)
		if(b[i]) ans++;
	printf("%d\n",ans);
}

int main()
{
	while(~scanf("%d",&n))
		fuck();
 return 0;
}


