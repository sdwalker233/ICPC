#include<bits/stdc++.h>
using namespace std;
int a[100010];

int main()
{
    int n,m,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int p=1,sum=0;
	i=1;
	vector<int> ans;
	while(1){
		if(p<=n&&i==a[p]){
			i++;p++;
			continue;
		}
		sum+=i;
		if(sum>m) break;
		ans.push_back(i);
		i++;
	}
	printf("%d\n",ans.size());
	for(auto it:ans) cout<<it<<" ";
 return 0;
}

