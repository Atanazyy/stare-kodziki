#include <bits/stdc++.h>

#define f first
#define s second
using namespace std;

const long long r = 1e6, p1 = 997, p2 = 313, mod1 = 1e9 + 9, mod2 = 1e9 + 7;
set <pair<long long, long long> > hasz[r];
pair<long long, long long> mno[r];
pair<long long, long long> dod[r];
int lit[r];
int kto[r];
vector<int> G[r];
int wyn[r];

long long pot(long long n, long long k, long long mod)
{
    if(k == 0)
        return 1;
    if(k % 2 == 0)
    {
        long long xd = pot(n, k / 2, mod);
        return (xd * xd) % mod;
    }
    long long xd = pot(n, k - 1, mod);
    return (n * xd) % mod;
}

void dfs(int v, int o)
{
    if(G[v].size() == 1 && v != 1)
    {
        kto[v] = v;
        hasz[v].insert({lit[v], lit[v]});
        mno[v] = {1, 1};
        dod[v] = {0, 0};
        wyn[v] = 1;
        return;
    }
    int prz = 0;
    for(auto x : G[v])
    {
        if(x == o)
            continue;
        dfs(x, v);
        if(hasz[kto[prz]].size() < hasz[kto[x]].size())
            prz = x;
    }
    kto[v] = kto[prz];
    //cout << v << " " << kto[v] << "\n";
    mno[kto[v]] = {(mno[kto[v]].f * p1) % mod1, (mno[kto[v]].s * p2) % mod2};
    dod[kto[v]] = {(dod[kto[v]].f * p1 + lit[v]) % mod1, (dod[kto[v]].s * p2 + lit[v]) % mod2};
    pair<long long, long long> akt = {lit[v], lit[v]};
    pair<long long, long long> inw = {pot(mno[kto[v]].f, mod1 - 2, mod1), pot(mno[kto[v]].s, mod2 - 2, mod2)};
    hasz[kto[v]].insert({(inw.f * ((mod1 + akt.f - dod[kto[v]].f) % mod1)) % mod1, (inw.s * ((mod2 + akt.s - dod[kto[v]].s) % mod2)) % mod2});
    for(auto x : G[v])
    {
        if(x == prz || x == o)
            continue;
        for(auto y : hasz[kto[x]])
        {
            akt = {(((y.f * mno[kto[x]].f + dod[kto[x]].f) % mod1) * p1 + lit[v]) % mod1, (((y.s * mno[kto[x]].s + dod[kto[x]].s) % mod2) * p2 + lit[v]) % mod2};
            hasz[kto[v]].insert({(inw.f * ((mod1 + akt.f - dod[kto[v]].f) % mod1)) % mod1, (inw.s * ((mod2 + akt.s - dod[kto[v]].s) % mod2)) % mod2});
        }
    }
    /*cout << v << " " << mno[kto[v]] << " " << dod[kto[v]] << " " << ": ";
    for(auto x : hasz[kto[v]])
        cout << x << " ";
    cout << "\n";*/
    wyn[v] = hasz[kto[v]].size();
}

void solve()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        lit[i] = kto[i] = wyn[i] = 0;
        mno[i] = dod[i] = {0, 0};
        hasz[i].clear();
        G[i].clear();
    }
    for(int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        lit[i] = x;
        //cout << lit[i] << "\n";
    }
    if(n == 1)
    {
        cout << "1\n";
        return;
    }
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++)
        cout << wyn[i] << " ";
    cout << "\n";
}

int main()
{
    int z;
    cin >> z;
    while(z--)
    {
        solve();
    }
}
