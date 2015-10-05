#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,t[11];
char s[110],x[110];
bool ok;
int right(int l,int r,int &last)
{
	int i;
	for(i=l;i<=r;i++){
		if(x[i]==47) continue;
		if(x[i]=='<'||x[i]=='>'){
			if(ok&&last!=i) x[last]=47;
			last=i;ok=1;
			if(x[i]=='>') continue;
			if(x[i]=='<') return i;
		}
		else{
			t[x[i]-'0']++;
			x[i]--;
			ok=0;
		}
	}
	return i;
}

int left(int l,int r,int &last)
{
	int i;
	for(i=r;i>=l;i--){
		if(x[i]==47) continue;
		if(x[i]=='<'||x[i]=='>'){
			if(ok&&last!=i) x[last]=47;
			last=i;ok=1;
			if(x[i]=='<') continue;
			if(x[i]=='>') return i;
		}
		else{
			t[x[i]-'0']++;
			x[i]--;
			ok=0;
		}
	}
	return i;
}

int main()
{
	int i,j,l,r,ll,rr,last=0;
	scanf("%d%d%s",&n,&q,s+1);
	for(i=1;i<=q;i++){
		scanf("%d%d",&l,&r);
		memcpy(x,s,sizeof(s));
		memset(t,0,sizeof(t));
		ll=l;rr=r;ok=0;last=0;
		while(ll>=l&&rr<=r){
			rr=right(ll,r,last);
			//printf("%d %d\n",ll,rr);
			//printf("%s\n",x+1);
			if(rr>r) break;
			ll=left(l,rr,last);
			//printf("%d %d\n",ll,rr);
			//printf("%s\n",x+1);
		}
		for(j=0;j<=9;j++)
			printf("%d ",t[j]);
		printf("\n");
	}
 return 0;
}

