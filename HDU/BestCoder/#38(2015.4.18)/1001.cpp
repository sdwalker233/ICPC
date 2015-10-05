#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long x[5],y[5],z[5];

 long long dis(int a,int b)
 {
 	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])+(z[a]-z[b])*(z[a]-z[b]);
 }

 bool run()
 {
 	int i;
	long long d;
 	vector<int> a;
 	for(i=1;i<=4;i++){
 		scanf("%I64d%I64d%I64d",&x[i],&y[i],&z[i]);
 		a.push_back(i);
 	}
 	for(i=1;i<=12;i++){
 		d=dis(a[0],a[1]);
 		if(d==2*dis(a[0],a[2])&&d==2*dis(a[0],a[3])&&d==2*dis(a[1],a[2])&&d==2*dis(a[1],a[3])&&d==dis(a[3],a[2])) return 1;
 		next_permutation(a.begin(),a.end());
 		next_permutation(a.begin(),a.end());
 	}
 	return 0;
 }

int main()
{
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		printf("Case #%d: ",k);
		if(run()) printf("Yes\n");
		else printf("No\n");
	}
 return 0;
}

