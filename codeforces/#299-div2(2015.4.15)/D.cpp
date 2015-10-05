#include<stdio.h>
#include<string.h>
#define mod 1000000007
int m,n,p[1000010],pos[1000010],l;
char b[1000010];
bool match[1000010]={0};

 void KMP(){
 	int i,j=0,cnt=0;
 	p[1]=0;
 	for(i=2;i<=l;i++){
 		while(j>0&&b[j+1]!=b[i])
 			j=p[j];
 		if(b[j+1]==b[i]) j++;
 		p[i]=j;
 	}
 }

int main()
{
	int i,j,now=0;
	long long ans=1;
	p[0]=0;
	scanf("%d%d",&n,&m);
	scanf("%s",b+1);
	for(i=1;i<=m;i++)
		scanf("%d",&pos[i]);
	l=strlen(b+1);
	if(m==0){
		for(i=1;i<=n;i++)
			ans=(ans*26)%mod;
		printf("%I64d\n",ans);
		return 0;
	}
	KMP();
	i=l;
	for(i=l;i>=1;i--)
		if(p[i]!=p[i-1]+1) break;
	//printf("%d %d\n",i,l);
	if(p[i]) i--;
	for(j=i;j<=l;j+=i)
		match[j+1]=1;
	if(i==l&&b[1]==b[l]) match[l]=1;
	//for(i=1;i<=l;i++)
		//printf("%d ",match[i]);
	for(i=1;i<pos[1];i++) //ans++;
		ans=(ans*26)%mod;
	for(i=1;i<m;i++){
		//printf("%I64d\n",ans);
		if(pos[i+1]-pos[i]<l){
			if(match[pos[i+1]-pos[i]+1]) continue;
			else{
				ans=0;
				break;
			}
		}
		else{
			for(j=1;j<=pos[i+1]-pos[i]-l;j++) //ans++;
				ans=(ans*26)%mod;
		}
	}
	if(pos[i]+l<=n)
		for(i=pos[i]+l;i<=n;i++) //ans++;
			ans=(ans*26)%mod;
	printf("%I64d\n",ans);
 return 0;
}
