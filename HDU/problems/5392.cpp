#include<stdio.h>
#include<string.h>
const int BUFSIZE=120<<20;
char Buf[BUFSIZE+1],*buf=Buf;
unsigned int mod=3221225473;
int a[3000010],b[3000010],n,num[3000010];
bool vis[3000010];

template<class T>
inline void scan(T&a){
  for (a=0;*buf<'0'||*buf>'9';buf++);
  while (*buf>='0'&&*buf<='9'){a=a*10+(*buf-'0');buf++; }
}

int quick_pow(int a,int b)
{
	int res=1,base=a;
	while(b!=0){
		if(b&1) res*=base;
		base=base*base;
		b>>=1;
	}
	return res;
}

inline float InvSqrt(float x)
{
	int i;
	float xhalf=0.5*x,y=x;
	i=*(int *) &y;     
	i=0x5f375a86 - ( i >> 1 ); 
	y=*(float *) &i;
	y=y*(1.5-(xhalf*y*y)); 
	y=y*(1.5-(xhalf*y*y));  	
	y=y*(1.5-(xhalf*y*y)); 
	return x*y;
}

int max(int x,int y)
{
	return x>y?x:y;
}

void fuck()
{
	int i,j,t=0,p,cnt,x,tmp;
	long long ans=1;
	memset(num,0,sizeof(num));
	memset(vis,0,sizeof(vis));
	//scanf("%d",&n);
	scan(n);
	for(i=1;i<=n;++i){
		scan(a[i]);
		//scanf("%d",&a[i]);
	}
	for(i=1;i<=n;++i){
		if(vis[i]) continue;
		p=i;cnt=0;
		while(!vis[p]){
			vis[p]=1;
			p=a[p];
			++cnt;
		}
		b[++t]=cnt;
	}
	for(i=1;i<=t;++i){
		x=InvSqrt((float)b[i]);
		//printf(" %d %d\n",a[i],x);
		for(j=2;j<=x&&b[i]!=1;++j){
			tmp=0;
			while(b[i]%j==0){
				tmp++;
				b[i]/=j;
			}
			num[j]=max(num[j],tmp);
		}
		num[b[i]]=max(num[b[i]],1);
	}
	for(i=1;i<=n;++i){
		if(num[i])	ans=(ans*quick_pow(i,num[i]))%mod;
	}
	printf("%lld\n",ans);
}

int main()
{
	fread(Buf,1,BUFSIZE,stdin);
	int t;
	scan(t);
	while(t--)
		fuck();
 return 0;
}


