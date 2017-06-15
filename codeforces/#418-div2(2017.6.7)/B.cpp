#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
int n;
int a[1100];
int b[1100];
int pos[1100];
int id[1100];
int vis[1100];
int p[1100];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	memset(vis,0,sizeof(vis));
	memset(p,0,sizeof(p));
	int num=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
			pos[num++]=i;
		else
		{
			p[i]=a[i];
			vis[a[i]]=1;
		}
	}
	if(num==1)
	{
		for(int i=1;i<=n;i++)
			if(vis[i]==0)
			{
				p[pos[0]]=i;
				break;
			}
	}
	else
	{
		int c=0;
		for(int i=1;i<=n;i++)
			if(vis[i]==0)
			{
				id[c++]=i;
			}
		int num1=0,num2=0;
		if(id[0]!=a[pos[0]])
			num1++;
		if(id[0]!=b[pos[0]])
			num2++;
		if(id[1]!=a[pos[1]])
			num1++;
		if(id[1]!=b[pos[1]])
			num2++;
		if(num1==1&&num2==1)
		{
			p[pos[0]]=id[0];
			p[pos[1]]=id[1];
		}
		else
		{
			p[pos[0]]=id[1];
			p[pos[1]]=id[0];
		}
	}
	
	for(int i=0;i<n;i++)
		if(i==0)
			printf("%d",p[i]);
		else
			printf(" %d",p[i]);
	printf("\n");

 	return 0;
}

