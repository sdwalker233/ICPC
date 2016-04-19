#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,cnt=1;
	int f[110],f1=1,f2=0;
	string s;
	f[1]=1;
	while(1){
		cin>>s;
		if(s[0]=='+'){
			f[++cnt]=1;
			f1++;
		}
		if(s[0]=='-'){
			f[++cnt]=-1;
			f2++;
		}
		if(s[0]=='='){
			cin>>s;
			break;
		}
	}
	int res,n;
	stringstream ss;
	ss<<s;
	ss>>n;
	res=n+f2;
	if(res<f1||res>n*f1){
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	int ave=res/f1,m=res%f1;
	for(i=1;i<=cnt;i++){
		if(i>1) printf(f[i]==1?" + ":" - ");
		if(f[i]==1){
			if(m){
				printf("%d",ave+1);
				m--;
			}
			else printf("%d",ave);
		}
		else{
			printf("1");
		}
	}
	printf(" = %d\n",n);
 return 0;
}

