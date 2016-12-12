#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
string unit[] = {
    "zero","one","two","three","four","five","six","seven","eight","nine",
    "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",
},
ten[] = {
    "zero","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety",
};
string s[1010];

string tran(int num)
{
	if(num==1000) return "one thousand";
    string res = "";
    if(num>=100)
        res += unit[num/100] + " hundred";
    num %= 100;
    if(num > 0){
        if (res.length() > 0) res += " and";
        if(num<20){
            if(res.length() > 0) res += " ";
            res += unit[num];
		}
        else{
            if(res.length() > 0) res += " ";
            res += ten[num/10];
            if(num%10 > 0)
                res += '-' + unit[num%10];
		}
	}
    return res;
}

int main()
{
	int t,n,i,j;
	for(i=1;i<=1000;i++){
		s[i]=tran(i);
		//cout<<i<<" "<<s[i]<<endl;
	}
	scanf("%d",&t);
	while(t-->0){
		int cnt=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			for(j=0;j<s[i].length();j++)
				if(s[i][j]>='a'&&s[i][j]<='z') cnt++;
		}
		printf("%d\n",cnt);
	}
 return 0;
}

