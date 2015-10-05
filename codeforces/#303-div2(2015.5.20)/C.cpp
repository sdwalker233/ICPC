#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n,i,j,p[100010],h[100010],cnt=0,pp;
	bool ok[100010]={0},l[100010]={0},r[100010]={0};
	scanf("%d",&n);
	if(n<=2){
		printf("%d\n",n);
		return 0;
	}
	for(i=1;i<=n;i++)
		scanf("%d%d",&p[i],&h[i]);
	l[1]=r[n]=1;
	for(i=2;i<=n;i++)
		if(p[i]-p[i-1]>h[i]) l[i]=1;
	for(i=1;i<n;i++)
		if(p[i+1]-p[i]>h[i]) r[i]=1;
	i=1;
	while(i<=n&&l[i]){
		i++;
		cnt++;
	}
	if(i>n){
		printf("%d\n",n);
		return 0;
	}
	for(pp=p[i-1];i<=n;i++){
		if(p[i]-pp>h[i]){
			cnt++;
			pp=p[i];
		}
		else{
			if(r[i]){
				cnt++;
				pp=p[i]+h[i];
			}
			else pp=p[i];
		}
	}
	printf("%d\n",cnt);
 return 0;
}

