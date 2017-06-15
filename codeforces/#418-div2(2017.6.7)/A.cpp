#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
int a[200],b[200];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k); 
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<k;i++)
		scanf("%d",&b[i]);
	if(k==1)
	{
		for(int i=0;i<n;i++)
			if(a[i]==0)
				a[i]=b[0];
		bool f=false;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
				if(a[i]<=a[j])
					f=true;
		}
		if(f)
			printf("Yes\n");
		else
			printf("No\n");
	}
	else
		printf("Yes\n");
 	return 0;
}


