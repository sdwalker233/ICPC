#include <stdio.h>
#include <ctype.h>
const int buf_len = 20<<20;
char buf[buf_len], *bufb(buf), *bufe(buf + 1);
#define readBuf() { \
    if (++ bufb == bufe) \
        bufe = (bufb = buf) + fread(buf, 1, sizeof(buf), stdin); \
}
#define readInt(_y_) { \
    register int _s_(0); \
    do { \
        readBuf(); \
    } while (!isdigit(*bufb)); \
    do { \
        _s_ = (_s_<<1) + (_s_<<3) + *bufb - '0'; \
        readBuf(); \
    } while (isdigit(*bufb)); \
    _y_ = _s_; \
}

int a[1010],n;

int max(int x,int y)
{
	return x>y?x:y;
}

void fuck()
{
	int i,j,k,ans=0;
	readInt(n);
	for(i=1;i<=n;i++)
		readInt(a[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j) continue;
			for(k=j+1;k<=n;k++){
				if(k==i) continue;
				ans=max(ans,a[i]^(a[j]+a[k]));
			}
		}
	}
	printf("%d\n",ans);
}

int main()
{
	int t;
	readInt(t);
	while(t-->0)
		fuck();
 return 0;
}
