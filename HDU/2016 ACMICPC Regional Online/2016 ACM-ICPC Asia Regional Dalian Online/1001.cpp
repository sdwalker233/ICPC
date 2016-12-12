#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <cassert>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;
const ll mod = (ll)(1e9) + 7;

struct Matrix{
    int row, col;

    ll data[10][10];

    Matrix () {}
    Matrix (int k) {
        row = col = 2;
        data[1][1] = 0, data[1][2] = 1;
        data[2][1] = k - 2, data[2][2] = k - 3;
    }

    Matrix operator * (const Matrix& rhs) const {
        Matrix res;
        res.row = row, res.col = rhs.col;
        for(int i = 1; i <= res.row; ++i) {
            for (int j = 1; j <= res.col; ++j) {
                res.data[i][j] = 0;
                for(int k = 1; k <= col; ++k) {
                    res.data[i][j] += data[i][k] * rhs.data[k][j];
                }
                res.data[i][j] %= mod;
            }
        }
        return res;
    }

    Matrix operator ^ (const int m) const {
        Matrix res, tmp;
        tmp.row = res.row = row, tmp.col = res.col = col;
        memset(res.data, 0, sizeof(res.data));
        for(int i = 1; i <= row; ++i) res.data[i][i] = 1;
        memcpy(tmp.data, data, sizeof(data));

        int mm = m;
        while(mm) {
            if(mm & 1) res = res * tmp;
            tmp = tmp * tmp;
            mm >>= 1;
        }
        return res;
    }
};

inline ll phi(ll x)
{
    ll res = x;
    for(ll i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            res = res / i * (i - 1);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) res = res / x * (x - 1);
    return res;
}

ll solve(int len, int k)
{
    Matrix res, tmp;
    tmp = Matrix(k);
    tmp = tmp ^ len;

    res.row = 2, res.col = 1;
    res.data[1][1] = 1, res.data[2][1] = 0;
    res = tmp * res;
    return res.data[1][1];
}

ll quick_pow(int x, ll m)
{
    ll res = 1, tmp = x;
    while(m) {
        if(m & 1) res = res * tmp % mod;
        tmp = tmp * tmp % mod;
        m >>= 1;
    }
    return res;
}

int main()
{
    int n, k;
    while(~scanf("%d%d", &n, &k)) {
        ll ans = 0;
        for(int i = 1; i * i <= n; ++i) {
            if(n % i) continue;
            ans = (ans + phi(n / i) * solve(i, k) % mod) % mod;
            if(n / i == i) continue;
            ans = (ans + phi(i) * solve(n / i, k) % mod) % mod;
        }
        printf("%lld\n",ans * k % mod * (k - 1) % mod * quick_pow(n, mod - 2) % mod);
    }
    return 0;
}
