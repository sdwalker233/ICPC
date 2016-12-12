#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> ans;
	int n;
	string s;
	cin>>n>>s;
	s+='W';
	int tmp=0;
	for(auto ch:s){
		if(ch=='B') tmp++;
		else if(tmp){
			ans.push_back(tmp);
			tmp=0;
		}
	}
	if(ans.size()==0){
		printf("0\n");
	}
	else{
		printf("%d\n",ans.size());
		for(auto it:ans) printf("%d ",it);
	}
 return 0;
}

