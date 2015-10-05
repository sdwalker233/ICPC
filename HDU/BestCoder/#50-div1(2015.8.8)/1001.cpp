#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x[21],y[21];

int dis(int t1,int t2)
{
	return (x[t1]-x[t2])*(x[t1]-x[t2])+(y[t1]-y[t2])*(y[t1]-y[t2]);
}

int four()
{
	int i,j,k,l,d[10],cnt=0;
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			for(k=j+1;k<=n;k++)
				for(l=k+1;l<=n;l++){
					d[1]=dis(i,j);
					d[2]=dis(i,k);
					d[3]=dis(i,l);
					d[4]=dis(j,k);
					d[5]=dis(j,l);
					d[6]=dis(k,l);
					sort(d+1,d+7);
					if(d[1]==d[2]&&d[2]==d[3]&&d[3]==d[4]&&d[5]==d[4]*2&&d[5]==d[6]) cnt++;
				}
	return cnt;
}

void fuck()
{
	int i;
	for(i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	printf("%d\n",four());
}

int main()
{
	while(~scanf("%d",&n))
		fuck();	
 return 0;
}

