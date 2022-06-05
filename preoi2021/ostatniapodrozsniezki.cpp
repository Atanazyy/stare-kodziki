#include <bits/stdc++.h>

using namespace std;

const int r = 2e6 + 9;
vector <pair<int ,int> > G[r];
priority_queue <pair<long long, int> > kol;
long long wyn[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        G[a].push_back({n + b, s});
        G[b].push_back({n + a, s});
        G[n + a].push_back({b, s});
        G[n + b].push_back({a, s}); 
    }
    int Z, D;
    cin >> Z >> D;
    for(int i = 1; i <= 2 * n; i++)
        wyn[i] = -1;
    kol.push({0, Z});
    while(!kol.empty())
    {
        int v = kol.top().second;
        long long x = -kol.top().first;
        kol.pop();
        if(wyn[v] != -1)
            continue;
        wyn[v] = x;
        for(auto u : G[v])
        {
            if(wyn[u.first] == -1)
                kol.push({-x - u.second, u.first});
        }
    }
    cout << wyn[D] << " " << wyn[n + D] <<"\n";
}