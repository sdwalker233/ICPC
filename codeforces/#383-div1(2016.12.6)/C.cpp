#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n,N;
int a[MAXN],b[MAXN],c[MAXN];
int d[MAXN];

void change(int x)
{
	d[x]=3-d[x];
	d[c[x]]=3-d[x];
}

int update(int x)
{
	int m[]={x,x+1,x+2},y;
	if(m[1]>n) m[1]-=n;
	if(m[2]>n) m[2]-=n;
	if(d[m[1]]==d[m[2]]&&d[m[2]]==d[m[0]]){
		int p=rand()%3;
		change(m[p]);
		return 1;
	}
	return 0;
}

int main()
{
	int i,t;
	srand(time(NULL));
	scanf("%d",&N);
	n=2*N;
	for(i=1;i<=N;i++){
		scanf("%d%d",&a[i],&b[i]);
		c[a[i]]=b[i];c[b[i]]=a[i];
		d[a[i]]=1;d[b[i]]=2;
	}
	//while(1){
	for(t=1;t<=2000;t++){
		for(i=n;i>=1;i--){
			if(update(i)) break;
		}
		if(i<1) break;
	}
	if(t>2000){printf("-1\n");return 0;}
	for(i=1;i<=N;i++)
		printf("%d %d\n",d[a[i]],d[b[i]]);
 return 0;
}

