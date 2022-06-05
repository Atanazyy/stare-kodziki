#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
const long long inf = 1e18;
long long war[r];
long long zpy[r];

void zep(int v)
{
    war[v] += zpy[v];
    zpy[v * 2] += zpy[v];
    zpy[v * 2 + 1] += zpy[v];
    zpy[v] = 0;
}

void dod(int v, int p, int k, int a, int b, int d)
{
    zep(v);
    if(p > b || k < a)
        return;
    if(a <= p && b >= k)
    {
        zpy[v] += d;
        zep(v);
        return;
    }
    int sr = (p + k) / 2;
    dod(v * 2, p, sr, a, b, d);
    dod(v * 2 + 1, sr + 1, k, a, b, d);
    war[v] = min(war[v * 2], war[v * 2 + 1]);
}

long long kur(int v, int p, int k, int a, int b)
{
    zep(v);
    if(p > b || k < a)
        return inf;
    if(a <= p && k <= b)
        return war[v];
    int sr = (p + k) / 2;
    return min(kur(v * 2, p, sr, a, b), kur(v * 2 + 1, sr + 1, k, a, b));
}

int main()
{
    int n, q;
    cin >> n >> q;
    int roz = ceil(log2(n));
    roz = 1 << roz;
    for(int i = roz; i < 2 * roz; i ++)
        war[i] = inf;
    for(int i = roz; i < roz + n; i ++)
        cin >> war[i];
    for(int i = roz - 1; i > 0; i--)
        war[i] = min(war[i * 2], war[i * 2 + 1]);
    while(q--)
    {
        char c;
        cin >> c;
        if(c == '?')
        {
            int a, b;
            cin >> a >> b;
            cout << kur(1, 1, roz, a, b) << "\n";
        }
        else
        {
            int a, b, d;
            cin >> a >> b >> d;
            dod(1, 1, roz, a, b, d);
        }
    }
}
