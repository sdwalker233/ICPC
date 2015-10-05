#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define NMAX 128
using namespace std;
int pData[NMAX][NMAX],pSum[NMAX][NMAX];

int main()
{
	int N, M, ans = 0,i,j;
	string strTmp;
	scanf("%d%d",&N,&M);
	memset(pData,0,sizeof(pData));
	memset(pSum,0,sizeof(pSum));
	for(i = 1; i <= N; i++)
	{
		cin >> strTmp;
		for(j = 1; j <= M; j++)
		{
			if(strTmp[j - 1] == 'B') { pData[i][j] = -1; }
			if(strTmp[j - 1] == 'W') { pData[i][j] = 1; }
		}
	}
	for(i = N; i >= 1; i--)
	{
		for(j = M; j >= 1; j--)
		{
			pSum[i][j] = pSum[i][j + 1] + pSum[i + 1][j] - pSum[i + 1][j + 1];
			if(pSum[i][j] == pData[i][j]) { continue; }
			else
			{
				int k = pData[i][j] - pSum[i][j];
				if(k != 0) { pSum[i][j] += k; }
				ans++;
			}
			
		}
	}
	printf("%d",ans);
	return 0;
}
