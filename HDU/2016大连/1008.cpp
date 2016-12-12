#include <bits/stdc++.h>
using namespace std;
const double eps=1e-8;
int k;
double mq[100010];

void fuck()
{
	k++;
	int i;
	mq[0]=1;
	for(i=1;i<=k;i++){
		mq[i]=mq[i-1]*(k-i)/(k+1-i);
	}
	double w=0;
	for(i=1;i<=k;i+=2){
		w+=1.0/(k+1-i)*mq[i-1];
	}
	if(fabs(w-0.5)<eps) printf("0\n");
	else if(w>0.5) printf("1\n");
	else printf("2\n");
}

int main()
{
	while(~scanf("%d",&k)) fuck();
 return 0;
}

