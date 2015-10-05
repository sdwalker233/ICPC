#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,m,hh,mm,ss,time;
	char s[10];
	bool ok;
	double dis,ave;
	scanf("%d%lf",&n,&dis);
	while(scanf("%d",&m)!=EOF){
		ok=1;
		time=0;
		getchar();
		printf("%3d: ",m);
		for(i=1;i<=n;i++){
			scanf("%s",s);
			if(s[0]=='-') ok=0;
			else{
				hh=s[0]-'0';
				mm=(s[2]-'0')*10+s[3]-'0';
				ss=(s[5]-'0')*10+s[6]-'0';
				time+=ss+mm*60+hh*3600;
			}
		}	
			if(ok==0){
				printf("-\n");
				continue;
			}
			//printf("%lf\n",time);
			ave=floor((double)time/dis+0.5);
			mm=(int)ave/60;
			ss=(int)(ave)%60;
			printf("%d:%02d min/km\n",mm,ss);
	}
 return 0;
}

