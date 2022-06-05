#include <bits/stdc++.h>

using namespace std;

const long long rm = 1e6 + 9;
long long roz;
long long tree[rm][6];
long long tab[rm];

void dod(long long v, long long x)
{
    tab[v] += x;
    for(long long i = 1; i <= 5; i++)
        if(tab[v] % i == 0)
            tree[v][i] = 1;
        else
            tree[v][i] = 0;
    v /= 2;
    while(v > 0)
    {
        for(long long i = 1; i <= 5; i++)
            tree[v][i] = tree[v * 2][i] + tree[v * 2 + 1][i];
        v /= 2;
    }
}

long long czyt(long long l, long long r, long long k)
{
    if(l == r) return tree[l][k];
    long long wyn = tree[l][k] + tree[r][k];
    while(l / 2 != r / 2)
    {
        if(l % 2 == 0) wyn += tree[l + 1][k];
        if(r % 2 == 1) wyn += tree[r - 1][k];
        l /= 2;
        r /= 2;
    }
    return wyn;
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
        dod(i + roz, 0);
    }
    while(q--)
    {
        string s;
        cin >> s;
        if(s[0] == 'D')
        {
            long long v, x;
            cin >> v >> x;
            dod(v - 1 + roz, x);
        }
        else
        {
            long long l, r, k;
            cin >> l >> r >> k; 
            cout << czyt(l - 1 + roz, r - 1 + roz, k) << "\n";
        }
    }
}
