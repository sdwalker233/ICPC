#include<stdio.h>
#include<string.h>
int a[510],b[510],c[1010],m[510][1010];
char op,s1[510],s2[510];
int la,lb,lc,lm[510];

inline int max(int x,int y)
{
	return x>y?x:y;
}

void print1()
{
	int i,l=max(la,max(lb+1,lc)),ll=max(lb+1,lc);
	
	for(i=1;i<=l-la;i++) putchar(' ');;
	for(i=1;i<=la;i++) putchar(a[la-i+1]+'0');
	putchar('\n');
	
	for(i=1;i<=l-lb-1;i++) putchar(' ');;
	putchar(op);
	for(i=1;i<=lb;i++) putchar(b[lb-i+1]+'0');
	putchar('\n');
	
	for(i=1;i<=l-ll;i++) putchar(' ');;
	for(i=1;i<=ll;i++) putchar('-');;
	putchar('\n');
	
	for(i=1;i<=l-lc;i++) putchar(' ');;
	for(i=1;i<=lc;i++) putchar(c[lc-i+1]+'0');
	putchar('\n');
}

void print2()
{
	int i,j,l=max(max(la,lb+1),lc),ll;
	for(i=1;i<=lb;i++)
		l=max(l,lm[i]);
	
	for(i=1;i<=l-la;i++) putchar(' ');;
	for(i=1;i<=la;i++) putchar(a[la-i+1]+'0');
	putchar('\n');
	
	for(i=1;i<=l-lb-1;i++) putchar(' ');;
	putchar(op);
	for(i=1;i<=lb;i++) putchar(b[lb-i+1]+'0');
	putchar('\n');
	
	ll=max(lb+1,lm[1]);
	for(i=1;i<=l-ll;i++) putchar(' ');;
	for(i=1;i<=ll;i++) putchar('-');;
	putchar('\n');
	
	for(i=1;i<=lb;i++){
		for(j=1;j<=l-lm[i];j++) putchar(' ');;
		for(j=1;j<=lm[i]-i+1;j++) putchar(m[i][lm[i]-j+1]+'0');
		putchar('\n');
	}
	
	ll=max(lc,lm[lb]);
	for(i=1;i<=l-ll;i++) putchar(' ');;
	for(i=1;i<=ll;i++) putchar('-');;
	putchar('\n');
	
	for(i=1;i<=l-lc;i++) putchar(' ');;
	for(i=1;i<=lc;i++) putchar(c[lc-i+1]+'0');
	putchar('\n');
}

void f3()
{
	int i,j,tmp=0;
	memset(m,0,sizeof(m));
	memset(c,0,sizeof(c));
	for(i=1;i<=lb;i++){
		tmp=0;
		for(j=1;j<=la;j++){
			m[i][i+j-1]=a[j]*b[i]+tmp;
			tmp=m[i][i+j-1]/10;
			m[i][i+j-1]%=10;
		}
		m[i][i+la]=tmp;
	}
	for(i=1;i<=lb;i++){
		lm[i]=i+la;
		while(lm[i]>i&&m[i][lm[i]]==0) lm[i]--;
	}
	for(i=1;i<=lb;i++)
		for(j=i;j<=lm[i];j++)
			c[j]+=m[i][j];
	lc=la+lb;tmp=0;
	for(i=1;i<=lc;i++){
		c[i]+=tmp;
		tmp=c[i]/10;
		c[i]%=10;
	}
	while(lc>1&&c[lc]==0) lc--;
	if(lb==1) print1();
	else print2();
}

void f2()
{
	int i,tmp=0;
	memset(c,0,sizeof(c));
	lc=la;
	for(i=1;i<=lc;i++){
		c[i]=a[i]-tmp-b[i];
		if(c[i]<0){
			c[i]+=10;
			tmp=1;
		}
		else tmp=0;
	}
	while(lc>1&&c[lc]==0) lc--;
	print1();
}

void f1()
{
	int i,tmp=0;
	memset(c,0,sizeof(c));
	lc=max(la,lb);
	for(i=1;i<=lc;i++){
		c[i]=a[i]+b[i]+tmp;
		tmp=c[i]/10;
		c[i]%=10;
	}
	if(tmp) c[++lc]=tmp;
	print1();
}

void fuck()
{
	int i,p,l;
	char ch,s[1010];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	la=lb=0;
	scanf("%s",s+1);
	l=strlen(s+1);
	for(i=1;i<=l;i++)
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'){
			op=s[i];p=i;break;
		}
	la=p-1;lb=l-p;
	for(i=1;i<p;i++)
		s1[i]=s[i];
	for(i=p+1;i<=l;i++)
		s2[i-p]=s[i];
	for(i=1;i<=la;i++)
		a[la-i+1]=s1[i]-'0';
	for(i=1;i<=lb;i++)
		b[lb-i+1]=s2[i]-'0';
	if(op=='+') f1();
	if(op=='-') f2();
	if(op=='*') f3();
	putchar('\n');
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}

