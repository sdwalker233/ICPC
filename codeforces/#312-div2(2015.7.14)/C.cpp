#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int b[100010][30];

void tran(int x,int x0[],int &l)
{
	 if(!x) return;
	 tran(x>>1,x0,l);
	 x0[l++]=x&1;
}

int main()
{
	int n,i,j,k,a[100010],len[100010]={0},p[100010],l,step,mn=0x7fffffff;
	memset(b,-1,sizeof(b));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tran(a[i],b[i],len[i]);
	}
//		for(i=1;i<=n;i++){
//			for(j=0;j<len[i];j++)
//				printf("%d",b[i][j]);
//			printf("\n");
//		}		
	for(i=0;i<=20;i++){
		if(b[1][i]==-1) break;
		for(j=2;j<=n;j++){
			if(b[j][i]!=b[1][i]) break;
		}
		if(j<=n) break;
	}
	l=i-1;
	//printf("%d\n",l);
	for(i=1;i<=n;i++){
		for(j=l+1;j<=20;j++)
			if(b[i][j]!=0){
				p[i]=j;
				break;
			}
	}
//	for(i=1;i<=n;i++)
//		printf(" %d\n",p[i]);
	for(i=l;i<=20;i++){
		step=0;
		for(j=1;j<=n;j++){
			if(p[j]<=i){
				if(b[j][p[j]]==1) step+=len[j]-p[j]+i-p[j]+1;
				else step+=i-p[j]+1;
				//printf("#%d ",step);
			}
			else{
				if(b[j][p[j]]==1) step+=len[j]-1-i;
				else step+=p[j]-i-1;
				//printf("*%d ",step);
			}
		}
		//printf("\n");
		mn=min(mn,step);
	}
	printf("%d\n",mn);
 return 0;
}

