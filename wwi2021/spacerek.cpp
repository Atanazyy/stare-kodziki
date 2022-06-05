#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int r = 1e7 + 9;
long long sil[2 * r];
long long jsl[2 * r];

long long szy(long long p, long long w)
{
    if(w == 0) return 1;
    if(w % 2 == 0)
    {
        long long a = szy(p, w/2);
        return (a * a) % mod;
    }
    return (szy(p, w - 1) * p) % mod;
}

long long dwu(long long a, long long b)
{
    long long wyn = sil[a];
    wyn = (wyn * jsl[b]) % mod;
    wyn = (wyn * jsl[a - b]) % mod;
    return wyn;
}

long long moz(long long a, long long b)
{
    if(a <= 0 || b <= 0) return 0;
    if(a == 1 || b == 1) return 1;
    return dwu(a + b - 2, a - 1); 
}

int main()
{
    int w, h;
    cin >> w >> h;
    int maxs = w + h;
    if(h == 1)
    {
        cout << 0;
        return 0;
    }
    sil[1] = 1;
    for(int i = 2; i<=maxs; i++)
    {
        sil[i] = (sil[i - 1] * i) % mod;
    }
    jsl[maxs] = szy(sil[maxs], mod - 2);
    for(int i = maxs; i > 1; i--)
    {
        jsl[i - 1] = (jsl[i] * i) % mod;
        cout<<sil[i - 1] << " "<< jsl[i - 1]<<"\n";
    }
    long long wyn = (moz(w,h) * moz(w,h)) % mod;
    //if(h % 2 == 0) 
    {
        cout << wyn;
        return 0;
    }
    for(int i = 1; i <= w; i++)
    {
        long long odp = moz(h / 2 + 1, i);
        odp = (odp * odp) % mod;
        long long gor =( 2 * moz(h / 2, w - i + 1) * moz(h / 2 + 1, w - i)) % mod;
        gor = (gor +  moz(h / 2, w - i + 1) *  moz(h / 2, w - i + 1)) % mod;
        odp = (odp * gor) % mod;
        wyn = (wyn + mod - odp) % mod;
    }
    cout << wyn;
}
