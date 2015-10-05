#include<stdio.h>
#include<algorithm>
using namespace std;
int n;

 bool cmp(int x,int y)
 {
 	return x>y;
 }

 void run()
 {
 	int i,a[1001],b[1001],front=0,back=n-1,ans=0;
 	for(i=0;i<n;i++)
 		scanf("%d",&a[i]);
 	for(i=0;i<n;i++)
 		scanf("%d",&b[i]);
 	sort(a,a+n);
 	sort(b,b+n);
 	for(i=0;i<n;i++){
 		if(b[i]<=a[front]){
 			ans+=(b[i]<a[front])*200;
 			front++;
 		}
 		else{
 			ans-=(b[i]>a[back])*200;
 			back--;
 		}
 	}
 	printf("%d\n",a[0]);
 }

int main()
{
	while(scanf("%d",&n)!=EOF){
		run();
	}
 return 0;
}

