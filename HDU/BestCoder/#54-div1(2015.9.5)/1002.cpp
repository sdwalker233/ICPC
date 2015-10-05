#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
 
const int N=1000;
const double PI=acos(-1.0);
 
struct complex{
    double r,i;
    complex(double _r=0.0,double _i=0.0){
        r=_r;i =_i;
    }
    complex operator +(const complex &b){
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b){
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b){
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
 
void change(complex y[],int len)
{
    int i,j,k;
    for(i=1,j=len/2;i<len-1;i++){
        if(i<j) swap(y[i],y[j]);
        k=len/2;
        while(j>=k){
            j-=k;
            k/=2;
        }
        if(j<k) j+=k;
    }
}
 
void FFT(complex y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1){
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j=0;j <len;j+=h){
            complex w(1,0);
            for(int k=j;k < j+h/2;k++){
                complex u=y[k];
                complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1)
        for(int i=0;i<len;i++)
           y[i].r/=len;
}

complex a[N],b[N],c[N];
 
void multiply(char s1[],char s2[],int ans[],int &len)
{
    int i,j,len1,len2;
    len1=strlen(s1);
    len2=strlen(s2);
    len=1;
    while(len<(len1<<1)||len<(len2<<1)) len<<=1;
    for(i=0;i<len1;i++)
		a[i]=complex(s1[len1-i-1]-'0',0);
    for(;i<len;i++)
		a[i]=complex(0,0);
    for(i=0;i<len2;i++)
		b[i]=complex(s2[len2-i-1]-'0',0);
    for(;i<len;i++)
		b[i]=complex(0,0);
    FFT(a,len,1);
    FFT(b,len,1);
    for(i=0;i<len;i++)
		c[i]=a[i]*b[i];
    FFT(c,len,-1);
    for(i=0;i<len;i++)
		ans[i]=(int)(c[i].r+0.5);
    len=len1+len2-1;
    for(i=0;i<len;i++){
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    while(ans[len]<=0&&len>0) len--;
}

bool is_zero(char s[])
{
	if(strlen(s)==1&&s[0]=='0') return 1;
	return 0;
}

bool is_equal(int a[],int l1,int b[],int l2)
{
	if(l1!=l2) return 0;
	int i;
	for(i=0;i<=l1;i++)
		if(a[i]!=b[i]) return 0;
	return 1;
}

void print(int a[],int len)
{
	int i;
	for(i=0;i<=len;i++)
		printf("%d",a[i]);
	printf("\n");
}

bool fuck()
{
	int i,j,k,n,l,num1[210],num2[210],len1,len2;
	char s[110][110];
	bool all_zero=1,zero=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",&s[i][0]);
		l=strlen(s[i])-1;
		j=0;
		while(j<l&&s[i][j]=='0') j++;
		for(k=0;k<=l-j;k++)
			s[i][k]=s[i][k+j];
		s[i][k]=0;
	}
	//for(i=1;i<=n;i++)
		//printf("%s\n",s[i]);
	if(n==1) return 1;
	if(n==2){
		if(is_zero(s[1])&&is_zero(s[2])) return 1;
		if(is_zero(s[1])||is_zero(s[2])) return 0;
		else return 1;
	}
	for(i=1;i<=n;i++)
		if(!is_zero(s[i])) all_zero=0;
		else zero=1;
	if(zero){
		if(all_zero) return 1;
		else return 0;
	}
	for(i=1;i<=n-2;i++){
		multiply(s[i],s[i+2],num1,len1);
		multiply(s[i+1],s[i+1],num2,len2);
		//print(num1,len1);
		//print(num2,len2);
		if(!is_equal(num1,len1,num2,len2)) return 0;
	}
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
		if(fuck()) printf("Yes\n");
		else printf("No\n");
 return 0;
}

