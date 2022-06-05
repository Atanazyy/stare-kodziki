#include <bits/stdc++.h>

using namespace std;

const int r = 2e6 + 9;
long long sil[r];
long long kil[r];
long long sum[r];
int n;
int m;

long long bez(int x)
{
    return (sil[x - 1] * kil[x + 1]) % m;
}

int main()
{
    cin >> n >> m;
    sil[0] = 1;
    kil[n] = 1;
    for(int i = 1; i <= n; i++)
    {
        sil[i] = (sil[i - 1] * i) % m;
    }
    for(int i = n - 1; i >= 1; i--)
    {
        sum[i] = (sum[i + 1] + i) % m;
        kil[i] = (kil[i + 1] * i) % m;
    }
    long long wyn = (((sum[1] + n) % m) * sil[n - 1]) % m;
    wyn = (wyn * (n - 1)) % m;
    for(int i = 1; i <= n - 1; i++)
    {
        wyn = (wyn + (((bez(i) * sum[n - i]) % m) * n)) % m;
    }
    for(int i = 1; i <= n; i++)
    {
        long long odj = kil[n - i + 1];
        odj = (((odj * n) % m) * (n - 1)) % m;
        wyn = (m + wyn - odj) % m;
    }
    cout << wyn;
}