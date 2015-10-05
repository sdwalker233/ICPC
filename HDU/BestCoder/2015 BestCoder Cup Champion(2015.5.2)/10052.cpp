#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[210];

 void fuck()
 {
 	int i,j,p,sum=0,c[210];
 	bool b[210];
 	scanf("%d%d",&n,&m);
 	for(i=1;i<=m;i++){
 		scanf("%d",&a[i]);
 	}
 	if(m==1){
 		for(i=1;i<=n;i++) c[i]=i;
 		p=1;
 		for(i=n;i>1;i--){
 			if(p!=1) p--;
 			p=(p+a[1]-1)%i+1;
 			for(j=p;j<=i&&p!=1;j++)
 				c[j-1]=c[j];
 		}
 		printf("1\n%d\n",c[1]);
 		return;
 	}
 	for(j=n;j>=1;j--){
 		memset(b,0,sizeof(b));
 		for(i=1;i<=n;i++){
 			b[(a[i]-1)%j+1]=1;
 		}
 		sum=0;
 		for(i=1;i<=200;i++)
	 		if(b[i]){
	 			p=i;
	 			sum+=b[i];
	 		}
 	}
 	
	if(sum>1){
		p=0;
		printf("%d\n",n);
	}
	else printf("%d\n",n-1);
	if(p!=n){
		for(i=1;i<n;i++){
			if(i!=p) printf("%d ",i);
		}
		printf("%d\n",i);
	}
	else{
		for(i=1;i<n-1;i++){
			if(i!=p) printf("%d ",i);
		}
		printf("%d\n",i);
	}
 }

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}
