#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long szy(long long p, long long w)
{
    if(w == 0) return 1;
    if(w % 2 == 1) return (p * szy(p, w - 1)) % mod;
    long long a = szy(p, w / 2);
    return (a * a) % mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    long long dwa = 2;
    int dod = 1;
    for(int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        if(a % 2 == 0) dod = -1;
        dwa = szy(dwa, a);
    }
    dwa = (szy(2, mod - 2) * dwa) % mod;
    cout << ((dwa - dod) * szy(3, mod - 2)) % mod << "/" << dwa; 
}