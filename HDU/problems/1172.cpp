#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p[10010][5];
 
void split()
{
	int i,x;
	for(i=1000;i<=9999;i++){
		x=i;
		p[i][1]=x%10;x/=10;
		p[i][2]=x%10;x/=10;
		p[i][3]=x%10;x/=10;
		p[i][4]=x;
	}
	
}

void run()
{
	bool ok[10010];
	int i,j,k,l,e,f,a,b,c,x[5],num=0;
	for(i=1000;i<=9999;i++)
		ok[i]=1;
	for(k=1;k<=n;k++){
		scanf("%d%d%d",&a,&b,&c);
		for(i=1000;i<=9999;i++)
			if(ok[i]){
				e=f=0;
				x[1]=p[a][1];x[2]=p[a][2];x[3]=p[a][3];x[4]=p[a][4];
				for(j=1;j<=4;j++)
					if(x[j]==p[i][j]) f++;
				for(j=1;j<=4;j++){
					for(l=1;l<=4;l++){
						if(p[i][j]==x[l]){
							x[l]=-1;
							e++;
							break;
						}
					}
				}
				//if(i==3585) printf("%d %d\n",e,f);
				if(e!=b||f!=c) ok[i]=0;
			}
	}
	for(i=1000;i<=9999;i++)
		num+=ok[i];
	if(num!=1){
		printf("Not sure\n");
		return;
	}
	for(i=1000;i<=9999;i++)
		if(ok[i]) printf("%d\n",i);
}

int main()
{
	split();
	while(~scanf("%d",&n)&&n)
		run();
 return 0;
}

