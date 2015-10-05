#include<stdio.h>

int main()
{
	char s;
	long long int sum,ans;
	while(1){
		s=getchar();
		if(s=='0') break;
		sum=s-'0';
		while(1){
			s=getchar();
			if(s=='\n') break;
			sum+=s-'0';
		}
		for(ans=sum;ans>=10;sum=ans){
			ans=0;
			while(sum){
				ans+=sum%10;
				sum/=10;
			}
		}
		printf("%I64d\n",ans);
	}
 return 0;
}

