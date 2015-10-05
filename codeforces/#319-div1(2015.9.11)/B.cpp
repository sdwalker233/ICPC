#include<bits/stdc++.h>
using namespace std;
int p[100010],fa[100010],cnt[100010]={0};
int a[100010];
bool flag[100010]={0},vis[100010]={0};

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void unio(int x,int y)
{
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}

int main()
{
	int n,i,j,num1=0,num2=0,x,y,s,t;
	bool ji=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
		unio(i,p[i]);
	}
	for(i=1;i<=n;i++){
		fa[i]=find(i);
		cnt[fa[i]]++;
	}
	//for(i=1;i<=n;i++)
	//	printf(" %d\n",cnt[i]);
	for(i=1;i<=n;i++){
		if(cnt[i]==1){
			a[++num1]=i;
		}
		else if(cnt[i]==2){
			++num2;
			s=i;
		}
		else if(cnt[i]%2){
			ji=1;
		}
	}
	if((!num1&&!num2)||(!num1&&num2&&ji)){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(num1){
		for(i=1;i<=n;i++){
			if(i!=a[1]) printf("%d %d\n",a[1],i);
		}
	}
	else if(num2){
		//if(n==70280) printf("1 1\n");
		for(i=1;i<=n;i++){
			if(!vis[i]){
				t=i;
				do{
					vis[t]=1;
					flag[p[t]]=(flag[t]^1);
					t=p[t];
				}while(t!=i);
			}
		}
		x=s;y=p[s];
		printf("%d %d\n",x,y);
		for(i=1;i<=n;i++){
			if(i==x||i==y) continue;
			if(flag[i]==1)	printf("%d %d\n",x,i);
			else printf("%d %d\n",y,i);
		}
	}
 return 0;
}


