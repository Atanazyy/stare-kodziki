#include <bits/stdc++.h>

using namespace std;

const long long r = 1e6;
long long tree[r], gw[r];
long long roz;
const long long inf = 1e17;

void zep(long long v)
{
    tree[v] += gw[v];
    gw[2 * v] += gw[v];
    gw[2 * v + 1] += gw[v];
    gw[v] = 0;
}

long long zap(long long a, long long b, long long v, long long p, long long k)
{
    zep(v);
    if(a > k || b < p)
    {
        return inf;
    }
    if(p >= a && k <= b)
    {
        return tree[v];
    }
    long long sr = (p + k) / 2;
    return min(zap(a, b, v * 2, p, sr), zap(a, b, v * 2 + 1, sr + 1, k));
}

void akt(long long a, long long b, long long v, long long p, long long k, long long x)
{
    zep(v);
    if(a > k || b < p)
    {
        return;
    }
    if(p >= a && k <= b)
    {
        gw[v] = x;
        zep(v);
        return;
    }
    long long sr = (p + k) / 2;
    akt(a, b, v * 2, p, sr, x);
    akt(a, b, v * 2 + 1, sr + 1, k, x);
    tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q;
    cin >> n >> q;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        tree[roz + i] = x;
    }
    for(long long i = roz - 1; i > 0; i--)
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    while(q--)
    {
        char z;
        cin >> z;
        if(z == '?')
        {
            long long a, b;
            cin >> a >> b;
            cout << zap(a, b, 1, 1, roz) << "\n";
        }
        else
        {
            long long a, b, x;
            cin >> a >> b >> x;
            akt(a, b, 1, 1, roz, x);
        }
    }
}