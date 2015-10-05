#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int num[100001],l=-1;
 
 int f(char s) {
 	if(s<='9'&&s>='0') return s-48;
 	switch(s){
 		case 'A':
 		case 'B':
 		case 'C': return 2;
 		case 'D':
 		case 'E':
 		case 'F': return 3;
 		case 'G':
 		case 'H':
 		case 'I': return 4;
 		case 'J':
 		case 'K':
 		case 'L': return 5;
 		case 'M':
 		case 'N':
 		case 'O': return 6;
 		case 'P':
 		case 'R':
 		case 'S': return 7;
 		case 'T':
 		case 'U':
 		case 'V': return 8;
 		case 'W':
 		case 'X':
 		case 'Y': return 9;
 	}
 }
 
 int cmp(const void *a, const void *b)  
 {  
    return *(int *)a - *(int *)b;  
 }

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	clock_t begin=clock();
	int t,i,j,n,r;
	char s;
	bool ok=0;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		j=0;n=0;
        while(j<7){
        	s=getchar();
       	    //printf("%d %d\n",s,j);
        	if(s==10||s=='-') continue;
        	//printf("%d ",s);
        	j++;
			n*=10;
        	n+=f(s);
        }
        //printf("%d\n",n);
        num[++l]=n;
       	//printf("%d\n",l);
       }
    //printf("%d",clock()-begin);
    qsort(num,l+1,sizeof(int),cmp);
    i=1;
    while(i<=l){
    	r=1;
    	while(num[i]==num[i-1]){
    		r++;
    		i++;
    	}
    	if(r>1){
    		ok=1;
			printf("%03d-%04d %d\n",num[i-1]/10000,num[i-1]%10000,r);
		}
    	i++;
       }
   if(ok==0) printf("No duplicates.\n");
   //printf("%d",clock()-begin);
 return 0;
}
