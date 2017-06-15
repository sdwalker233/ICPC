#include <bits/stdc++.h>
using namespace std;
int l[5],s[5],r[5],p[5];

int main()
{
	int i;
	for(i=0;i<4;i++) scanf("%d%d%d%d",&l[i],&s[i],&r[i],&p[i]);
	for(i=0;i<4;i++){
		if(p[i]==0) continue;
		if(s[i]||l[i]||r[i]) break;
		if(l[(i+1)%4]) break;
		if(s[(i+2)%4]) break;
		if(r[(i+3)%4]) break;
	}
	if(i<4) printf("YES\n");
	else printf("NO\n");
 return 0;
}

