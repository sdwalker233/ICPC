#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
char s[100001];
int t[10000001],l,t2[10000001],count=0,a[27];
vector<int> v[27];

 int t_query(int ll,int rr,int left,int right,int p)
 {
 	int m=(left+right)>>1;
 	if(ll>rr) return 0;
 	if(ll==left&&rr==right) return t[p];
 	if(m>=rr) return t_query(ll,rr,left,m,p<<1);
 	if(m<ll) return t_query(ll,rr,m+1,right,(p<<1)+1);
 	return t_query(ll,m,left,m,p<<1)+t_query(m+1,rr,m+1,right,(p<<1)+1);
 }

 void t_create(int left,int right,int p)
 {
 	int m=(left+right)>>1;
 	if(left==right){
 		t[p]=a[s[left]-'a'+1];
 		return;
 	}
 	t_create(left,m,p<<1);
 	t_create(m+1,right,(p<<1)+1);
 	t[p]=t[p<<1]+t[(p<<1)+1];
 }

 void t2_create(int left,int right,int p,int nn)
 {
 	printf("%d %d\n",left,right);
 	int m=(left+right)>>1;
 	if(left==right){
 		t2[p]=0;
 		return;
 	}
 	t2_create(left,m,p<<1,nn);
 	t2_create(m+1,right,(p<<1)+1,nn);
 	t2[p]=t2[p<<1]+t2[(p<<1)+1];
 	if(m+1==right) t2[p]+=t_query(v[nn][m]+1,v[nn][right]-1,0,l-1,1);
 	if(left!=m) t2[p]+=a[nn];
	if(t2[p]==0)
		count++;
 }

int main()
{
	int i;
	for(i=1;i<=26;i++)
		scanf("%d",&a[i]);
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i++)
		v[s[i]-'a'+1].push_back(i);
	t_create(0,l-1,1);
	for(i=1;i<=26;i++){
		if(v[i].size()) t2_create(0,v[i].size()-1,1,i);
	}
		
	printf("%d\n",count);
 return 0;
}

