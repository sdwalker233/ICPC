#include <bits/stdc++.h>
using namespace std;
int n;
int ans[1010],a[1010];
vector<int> v1,v2;

void f()
{
	cout<<v1.size()<<endl;
	for(auto it:v1) cout<<it<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(auto it:v2) ans[it]=min(ans[it],a[it]);
	cout<<v2.size()<<endl;
	for(auto it:v2) cout<<it<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(auto it:v1) ans[it]=min(ans[it],a[it]);
}

int main()
{
	int i,j,step=1;
	cin>>n;
	for(i=1;i<=n;i++) ans[i]=2e9;
	for(step=1;step<n;step<<=1){
		v1.clear();v2.clear();
		for(i=1;i<=n;i++){
			if(((i-1)/step)%2) v1.push_back(i);
			else v2.push_back(i);
		}
		f();
	}
	cout<<-1<<endl;
	for(i=1;i<=n;i++) cout<<ans[i]<<" ";
 return 0;
}

