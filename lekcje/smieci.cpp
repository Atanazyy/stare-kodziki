#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;
vector <int> id[r];
vector <int> G[r];
vector<int> wyn[r];
vector <int> tem;
int start[r];
bool odw[r];
bool byl[r];
int k;
bool byln[r];

void dfs(int v)
{
    byln[v] = 1;
    for(int i = start[v]; i < G[v].size(); i++)
    {
        start[v] = i;
        int u = G[v][i];
        int nr = id[v][i];
        if(!odw[nr])
        {
            odw[nr] = 1;
            dfs(u);
            i = start[v];
        }
    }
    if(!byl[v])
    {
        byl[v] = 1;
        tem.push_back(v);
    }
    else
    {
        wyn[k].push_back(v);
        while(tem[tem.size() - 1] != v)
        {
            wyn[k].push_back(tem[tem.size() - 1]);
            byl[tem[tem.size() - 1]] = 0;
            tem.pop_back();
        }
        wyn[k].push_back(v);
        k++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if(x != y)
        {
            G[a].push_back(b);
            G[b].push_back(a);
            id[a].push_back(i);
            id[b].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(G[i].size() % 2 == 1)
        {
            cout << "NIE";
            return 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!byln[i])
        {
            dfs(i);
        }
        for(auto x : tem) byl[x] = 0;
        tem.clear();
    }
    cout << k << "\n";
    for(int i = 0; i < k; i ++)
    {
        auto x = wyn[i];
        cout << x.size() - 1 << " ";
        for(auto y : x)
            cout << y << " ";
        cout << "\n";
    }
}