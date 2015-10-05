#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int i,l,p1[100010],p2[100010],x1=0,x2=0,b[100010]={0},cnt=0;
    char s[100010];
    scanf("%s",s+1);
    l=strlen(s+1);
    for(i=1;i<l;i++){
        if(s[i]=='A'&&s[i+1]=='B'){
            b[i+1]=b[i]=1;
            cnt++;
        }
    }
    for(i=1;i<l;i++){
        if(s[i]=='B'&&s[i+1]=='A')
            if(cnt>=3||(b[i]==0&&b[i+1]==0&&cnt)||((b[i]^b[i+1])&&cnt>=2)){
                printf("YES\n");
                return 0;
            }
    }
    printf("NO\n");
 return 0;
}
