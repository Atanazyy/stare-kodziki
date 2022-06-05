#include <bits/stdc++.h>

using namespace std;

const long long r = 1e6;
long long roz;
long long tree[r], gw[r], wyn[r];
const long long inf = 1e17;
long long dz;

void zep(int v)
{
    tree[v] += gw[v];
    gw[v * 2] += gw[v];
    gw[v * 2 + 1] += gw[v];
    gw[v] = 0;
}

void ini(long long v, long long x)
{
    tree[v] = x;
    v /= 2;
    while(v > 0)
    {
        zep(v * 2);
        zep(v * 2 + 1);
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
        v /= 2;
    }
} 

void ubdat(long long a, long long b, long long v, long long p, long long k, long long x)
{
    zep(v);
    if(b < p || a > k)
        return;
    if(p >= a && k <= b)
    {
        tree[v] += x;
        gw[v * 2] += x;
        gw[v * 2 + 1] += x;
        return;
    }
    long long sr = (p + k) / 2;
    ubdat(a, b, v * 2, p, sr, x);
    ubdat(a, b, v * 2 + 1, sr + 1, k, x);
    tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    return;
}

void spr(long long v)
{
    zep(v);
    if(v >= roz)
    {
        if(tree[v] <= 0) 
        {
            //cout << "\n" << v + 1 - roz << "\n";
            wyn[v + 1 - roz] = dz;
            ini(v, inf);
        }
        return;
    }
    if(tree[v] <= 0)
    {
        spr(v * 2);
        spr(v * 2 + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m;
    cin >> n >> m;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(long long i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        ini(i + roz - 1, x);
    }
    //cout << "\n";
    dz = 0;
    while(m--)
    {
      //  for(long long j = 1; j < 2 * roz; j++)
        //    cout << tree[j] << " " << gw[j] << ", ";
        //cout << "\n";

        dz++;
        long long a, b, x;
        cin >> a >> b >> x;
        ubdat(a, b, 1, 1, roz, - x);

        //for(long long j = 1; j < 2 * roz; j++)
         //   cout << tree[j] << " " << gw[j] << ", ";
       // cout << "\n";

        spr(1);
    }
    for(long long i = 1; i <= n; i++)
    {
        if(wyn[i] == 0) cout <<"NIE\n";
        else cout << wyn[i] << "\n";
    }
}
