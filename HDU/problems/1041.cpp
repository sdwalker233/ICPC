#include<stdio.h>
int a[1001][500];
int main()
{
    int i,j,n,p,len[1001],tmp;
    a[1][0]=0;len[1]=0;p=1;
    for(i=2;i<=1000;i++){
        a[i][0]=a[i-1][0]*2+p;
        tmp=a[i][0]/10;
        a[i][0]%=10;
        for(j=1;j<=len[i-1];j++){
            a[i][j]=a[i-1][j]*2+tmp;
            tmp=a[i][j]/10;
            a[i][j]%=10;
        }
        len[i]=len[i-1];
        if(tmp){
            len[i]++;
            a[i][len[i]]=tmp;
        }
        p*=(-1);
    }
    while(scanf("%d",&n)!=EOF){
        for(i=len[n];i>=0;i--)
            printf("%d",a[n][i]);
        printf("\n");
    }
 return 0;
}
