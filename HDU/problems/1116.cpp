#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,in[30],out[30],fa[30],vis[30];

int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

void unio(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}

bool fuck()
{
	int i,l,num1=0,num2=0,num[30]={0};
	bool ok=1;
	char s[1010];
	memset(in,0,sizeof(in));
	memset(vis,0,sizeof(vis));
	memset(out,0,sizeof(out));
	for(i=1;i<=26;i++) fa[i]=i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",s+1);
		l=strlen(s+1);
		in[s[1]-'a'+1]++;
		out[s[l]-'a'+1]++;
		unio(s[1]-'a'+1,s[l]-'a'+1);
		vis[s[1]-'a'+1]=vis[s[l]-'a'+1]=1;
	}
	for(i=1;i<=26;i++)
		if(vis[i]) num[find(i)]++;
	//for(i=1;i<=26;i++)
	//	printf(" %c %d\n",i-1+'a',num[i]);
	for(i=1;i<=26;i++)
		if(num[i])
			if(ok==1) ok=0;
			else return 0;
	for(i=1;i<=26;i++){
		if(in[i]-out[i]>1||out[i]-in[i]>1) return 0;
		if(in[i]>out[i]) num1++;
		else if(in[i]<out[i]) num2++;
	}
	if(num1==0&&num2==0) return 1;
	if(num1==1&&num2==1) return 1;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		if(fuck()) printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
 return 0;
}

