#include<stdio.h>
int n,a[10000],len;

 void run()
 {
    int i,j,tmp;
    a[0]=1;
    len=0;
    for(i=1;i<=n;i++){
        tmp=0;
        for(j=0;j<=len;j++){
            a[j]=i*a[j]+tmp;
            tmp=a[j]/10000;
            a[j]%=10000;
        }
        while(tmp){
            a[++len]=tmp%10000;
            tmp/=10000;
        }
    }
    //printf("%d\n",len);
    printf("%d",a[len]);
    for(i=len-1;i>=0;i--)
        printf("%04d",a[i]);
    printf("\n");
 }

int main()
{
    while(scanf("%d",&n)!=EOF){
        run();
    }
 return 0;
}
