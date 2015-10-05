#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;
priority_queue<double> q;

int main()
{
	bool inf=0;
	int n,i,x0,y0,x,y,count=0;
	double last=1000000;
	scanf("%d%d%d",&n,&x0,&y0);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x==x0) inf=1;
		else q.push((double)(y-y0)/(double)(x-x0));
	}
	while(!q.empty()){
		if(fabs(q.top()-last)>1e-10) count++;
		last=q.top();
		q.pop();
	}
	printf("%d\n",count+inf);
 return 0;
}

