#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,y;
	cin >> n;
	cout<<"YES"<<endl;
	while(n-->0){
		scanf("%d%d",&x,&y);
		cout<<(x&1)+1+(y&1)*2<<endl;
		scanf("%d%d",&x,&y);
	}
 return 0;
}

