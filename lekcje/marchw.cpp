#include <bits/stdc++.h>

using namespace std;

const long long r = 1e6;
long long roz;
long long tree[r], gw[r];
const long long inf = 1e17;
bool pra[r];
int g1, g2;
int g1sum, g2sum;

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
            //cout << v - roz << "\n";
            //cout << "\n" << v + 1 - roz << "\n";
            if(pra[v]) 
            {
                ini(v, inf);
                g1sum ++;
                g2sum --;
            }
            else
            {
                pra[v] = 1;
                ini(v, g1 - g2 + tree[v]);
                g2sum++;
            }
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
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m >> g2 >> g1;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ini(i + roz, g2 - x);
    }
    for(int i = n + roz; i < 2 * roz; i++)
        ini(i, inf);
    //spr(1);
    //cout << g1sum << " " << g2sum << "\n";
    //return 0;
    while(m--)
    {
        int a, b, x;
        cin >> a >> b >> x;
        ubdat(a, b, 1, 1, roz, - x);
        ubdat(1, n, 1, 1, roz, - 1);
        spr(1);
        spr(1);
        cout << g1sum << " " << g2sum << "\n";
    }
}
