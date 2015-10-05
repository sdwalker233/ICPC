#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,a[50],count;

 void DFS(int x,int y){
 	int i;
 	if(x==n&&y==m){
 		for(i=2;i<=n+m;i++)
 			if(a[i-1]==0&&a[i]==1) count++;
 		return;
 	}
 	if(x<n){
 		a[x+y+1]=1;
 		DFS(x+1,y);
 	}
 	if(y<m){
 		a[x+y+1]=0;
 		DFS(x,y+1);
 	}
 }

 int ccc(int x,int y)
 {
 	unsigned long long i,ans=1;
 	for(i=n+1;i<=n+m;i++)
 		ans*=i;
 	for(i=1;i<=m;i++)
 		ans/=i;
 	return ans;
 }

 int gcd(int x,int y)
 {
 	if(y==0) return x;
 	else return gcd(y,x%y);
 }

int main()
{
	freopen("out.txt","w",stdout);
	int b,d;
	/*while(~scanf("%d%d",&n,&m)){
		count=0;
		DFS(0,0);
		printf("%d\n",count);
	}*/
	for(n=1;n<=12;n++){
		for(m=1;m<=12;m++){
			count=0;
			DFS(0,0);
			//printf("%d\n",count);
			d=ccc(n,m+n);
			b=gcd(count,d);
			printf("\"%d/%d\",",count/b,d/b);
		}
		printf("\n");
	}	 
 return 0;
}

