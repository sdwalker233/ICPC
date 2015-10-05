#include<iostream>
#include<string>
using namespace std;
int l,a[10]={6,6,2,6,4,4,4,8,4,6},b[4]={2,6,8,4},c[10]={0,1,0,3,3,5,1,7,2,9};

 int f(int num[])
 {
 	int i,t,ans=c[a[num[0]]],temp;
 	for(i=l-1;i>=0;i--)
		if(num[i]) break;
	l=i+1;
	if(l<=1&&num[0]<=1) return 1;
	temp=num[0]/5;
	for(i=0;i<l;i++){
		num[i]=num[i+1]*2+temp;
		temp=num[i]/10;
		num[i]%=10;
	}
	t=(num[0]+num[1]*10)%4;
	ans=(ans+t)%4;
	return b[ans]*f(num)%10;
 }

int main()
{
	string s;
	int i,num[10000];
	while(getline(cin,s)){
		l=s.length();
		memset(num,0,sizeof(num));
		for(i=0;i<l;i++)
			num[i]=s[l-1-i]-'0';
		printf("%d\n",f(num));
	}
 return 0;
}

