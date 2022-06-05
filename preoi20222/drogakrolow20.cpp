#include <bits/stdc++.h>

using namespace std;

const int r = 2e5 + 9;
long long ma[r];
long long wyn[r];
vector<int> G[r];
int wie[r];
int ojc[r];
int n, q;

struct S
{
    void dfs(int v, int o)
    {
        ojc[v] = o;
        wie[v] = 1;
        for(auto x : G[v])
        {
            if(x != o)
            {
                dfs(x, v);
                wie[v] += wie[x];
            }
        }
    }

    void lic(int v, long long ile)
    {
        ile += ma[v];
        wyn[v] = wyn[ojc[v]] + ile;
        for(auto x : G[v])
        {
            if(x != ojc[v])
                lic(x, ile);
        }
    }
    void solve()
    {
        //cout << r;
        for(int i = 1; i <= n; i++)
        {
            G[i].clear();
            ma[i] = 0;
            ojc[i] = 0;
            wie[i] = 0;
        }
        for(int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1, 0);
        while(q--)
        {
            int c;
            cin >> c;
            if(c == 1)
            {
                int x, d;
                cin >> x >> d;
                ma[x] += d;
            }
            else
            {
                break;
            }
        }
        int v, c;
        lic(1, 0);
        cin >> v;
        cout << wyn[v] << "\n";
        while(q--)
        {
            cin >> c >> v;
            cout << wyn[v] << "\n";
        }
    }
};

struct S1
{
    void dfs(int v, int o)
    {
        ojc[v] = o;
        wie[v] = 1;
        for(auto x : G[v])
        {
            if(x != o)
            {
                dfs(x, v);
                wie[v] += wie[x];
            }
        }
    }

    void solve()
    {
        for(int i = 1; i <= n; i++)
        {
            G[i].clear();
            ma[i] = 0;
            ojc[i] = 0;
            wie[i] = 0;
        }
        for(int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1, 0);
        while(q--)
        {
            int c;
            cin >> c;
            if(c == 1)
            {
                int x, d;
                cin >> x >> d;
                ma[x] += d;
            }
            else
            {
                int v, roz = 1;
                long long wyn = 0;
                cin >> v;
                while(v != 0)
                {
                    wyn += roz * ma[v];
                    roz ++;
                    v = ojc[v];
                }
                cout << wyn << "\n";
            }
        }
    }
};

int main()
{
    int z;
    cin >> z;
    while(z --)
    {
        cin >> n >> q;
        if(n > 3000 || q > 3000)
        {
            S s;
            s.solve();
        }
        else
        {
            //cout << "xd";
            S1 s;
            s.solve();
        }
    }
}
