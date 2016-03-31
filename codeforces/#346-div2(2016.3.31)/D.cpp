#include<bits/stdc++.h>
using namespace std;
int x[1010],y[1010];

int dir(int a,int b)
{
	if(y[a]<y[b]) return 1;
	if(x[a]<x[b]) return 2;
	if(y[a]>y[b]) return 3;
	if(x[a]>x[b]) return 4;
}

int main()
{
    int n,i;
	scanf("%d",&n);
	for(i=1;i<=n+1;i++)
		scanf("%d%d",&x[i],&y[i]);
	x[n+2]=x[2];
	y[n+2]=y[2];
	int cnt=0;
	for(i=1;i<=n;i++){
		int d1=dir(i,i+1);
		int d2=dir(i+1,i+2);
		if((d1-d2+4)%4==1) ++cnt;
	}
	cout<<cnt<<endl;
 return 0;
}

