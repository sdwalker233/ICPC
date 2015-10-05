#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,xx,yy;
int g[110][110];

void p(char ch,int n)
{
	while(n-->0) putchar(ch);
}

void fuck()
{
	int i,j,mn=100000,x,y,sum=0;;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&g[i][j]);
			sum+=g[i][j];
		}
	if(n%2){
		printf("%d\n",sum);
		for(i=1;i<=n/2;i++){
			p('R',m-1);
			putchar('D');
			p('L',m-1);
			putchar('D');
		}
		p('R',m-1);
		putchar('\n');
		return;
	}
	if(m%2){
		printf("%d\n",sum);
		for(i=1;i<=m/2;i++){
			p('D',n-1);
			putchar('R');
			p('U',n-1);
			putchar('R');
		}
		p('D',n-1);
		putchar('\n');
		return;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if((i+j)%2&&mn>g[i][j]){
				mn=g[i][j];
				xx=i;yy=j;
			}
	printf("%d\n",sum-g[xx][yy]);
	for(i=1;i<=((yy+1)/2*2-2)/2;i++){
		p('D',n-1);
		putchar('R');
		p('U',n-1);
		putchar('R');
	}
	if(xx==1){
		putchar('D');
		for(i=1;i<=n/2-1;i++) printf("RDLD");
		putchar('R');
	}
	else if(xx==n){
		for(i=1;i<=n/2-1;i++) printf("RDLD");
		printf("RD");
	}
	else if(xx%2==0){
		for(i=1;i<=xx/2-1;i++) printf("RDLD");
		printf("RDDLD");
		for(i=1;i<=(n-xx)/2-1;i++) printf("RDLD");
		putchar('R');
	}
	else{
		for(i=1;i<=xx/2;i++) printf("RDLD");
		putchar('D');
		for(i=1;i<=(n-xx)/2;i++) printf("RDLD");
		putchar('R');
	}
	if((yy+1)/2*2!=m){
		for(i=1;i<=(m-(yy+1)/2*2)/2;i++){
			putchar('R');
			p('U',n-1);
			putchar('R');
			p('D',n-1);
		}
	}
	putchar('\n');
}
int main()
{
	while(~scanf("%d%d",&n,&m))
		fuck();
 return 0;
}

