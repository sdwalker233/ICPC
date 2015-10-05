#include <iostream>
#include <memory.h>
#include <string>
#include <algorithm> 

using namespace std;

const int MAX = 102400;

struct Seg
{
	Seg(int _l = 0, int _r = 0)
	{ l = _l; r = _r; }
	int l, r;
};

int cmp(Seg x, Seg y)
{ return x.r < y.r; }

Seg pData[MAX];

int main()
{
	ios::sync_with_stdio(false);
	int N, nCnt = 0;
	string strData, strTmp;
	cin >> strData >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> strTmp;
		for(int j = 0; j < strData.length() - strTmp.length(); j++)
		{
			bool bFlag = true;
			for(int k = 0; k < strTmp.length(); k++)
			{
				if(strData[j + k] != strTmp[k])
				{ bFlag = false; break; }
			}
			if(bFlag)
			{ pData[++nCnt] = Seg(j, j + strTmp.length() - 1);
			}
		}
	}
	sort(pData + 1, pData + nCnt + 1, cmp);
	int ans = 0, pos = 0;
	for(int i = 0; i <= N; i++)
	{
		if(pData[i + 1].l <= pData[i].r)
		{
			ans = pData[i].r - 1;
		}
		else { break; }
	}
	if(ans < 0) { ans = 0; }
	for(int i = 1; i < N; i++)
	{
		if(ans < pData[i + 1].r - pData[i].l - 1)
		{
			ans = pData[i + 1].r - pData[i].l - 1;
			pos = pData[i].l + 1;
		}
	} 
	cout << ans << " " << pos << endl;
	return 0;
}

