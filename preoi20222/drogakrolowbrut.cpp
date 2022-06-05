#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const int r = 1e6;
long long a[r];
long long b[r];
int dep[r], pre[r], wie[r];
vector<int> G[r];

struct S
{
    int preid, roz;
    void dfs(int v, int o)
    {
        wie[v] = 1;
        dep[v] = dep[o] + 1;
        pre[v] = preid;
        preid++;
        for(auto x : G[v])
        {
            if(x != o)
            {
                dfs(x, v);
                wie[v] += wie[x];
            }
        }
    }

    void dod(int p, int k, long long xa, long long xb)
    {
        p += roz;
        k += roz;
        if(p == k)
        {
            a[p] += xa;
            b[p] += xb;
            return;
        }

        a[p] += xa;
        b[p] += xb;
        a[k] += xa;
        b[k] += xb;
        while(p / 2 != k / 2)
        {
            if(p % 2 == 0)
            {
                a[p + 1] += xa;
                b[p + 1] += xb;
            }
            if(k % 2 == 1)
            {
                a[k - 1] += xa;
                b[k - 1] += xb;
            }
            p /= 2;
            k /= 2;
        }
        //cout << p << " " << k << " " << xa << " " << xb << "\n";
    }

    pair<long long, long long> sum(int v)
    {
        v += roz;
        long long wa = 0, wb = 0;
        while(v > 0)
        {
            wa += a[v];
            wb += b[v];
            v /= 2;
        }
        return {wa, wb};
    }

    void solve()
    {
        int n, q;
        cin >> n >> q;
        roz = ceil(log2(n));
        roz = 1 << roz;
        for(int i = 1; i <= 2 * roz; i++)
        {
            G[i].clear();
            pre[i] = 0;
            wie[i] = 0;
            dep[i] = 0;
            a[i] = 0;
            b[i] = 0;
        }
        for(int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        preid = 0;
        dfs(1, 0);
        while(q--)
        {
            int c;
            cin >> c;
            if(c == 1)
            {
                long long x, d;
                cin >> x >> d;
                dod(pre[x], pre[x] + wie[x] - 1, d, (-dep[x] + 1) * d);
            }
            else
            {
                int x;
                cin >> x;
                auto xd = sum(pre[x]);
                cout << xd.f * dep[x] + xd.s << "\n";
            }
        }
        /*for(int i = 1; i <= n; i++)
        {
            cout << i << " " << pre[i] << " " << wie[i] << " " << dep[i] <<"\n";
        }*/
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int z;
    cin >> z;
    while(z --)
    {
        S s;
        s.solve();
    }
}
