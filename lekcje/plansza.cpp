#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;

vector <int> ind[r];
vector <int> G[r];
int start[r];
int odw[r];
vector <int> tem;
map <pair<int,int>, int > mapa;
vector <pair<int, int> > zap;

int pop;
int w = 1;

void dfs(int v)
{
    for(int i = start[v]; i < G[v].size(); i++)
    {
        start[v] = i;
        int u = G[v][i];
        int id = ind[v][i];
        if(!odw[id])
        {
            odw[id] = 1;
            dfs(u);
            i = start[v];
        }
    }
    mapa[{v, pop}] = w;
    mapa[{pop, v}] = w;
    w = -w;
    pop = v;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        zap.push_back({a, b + n});
        G[a].push_back(b + n);
        G[b + n].push_back(a);
        ind[a].push_back(i);
        ind[b + n].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        if(G[i].size() % 2 == 1)
        {
            G[i].push_back(2 * n + 1);
            G[2 * n + 1].push_back(i);
            ind[i].push_back(m);
            ind[2 * n + 1].push_back(m);
            m++;
        }
    }
    for(int i = n + 1; i <= 2 * n; i++)
    {
        if(G[i].size() % 2 == 1)
        {
            G[i].push_back(2 * n + 2);
            G[2 * n + 2].push_back(i);
            ind[i].push_back(m);
            ind[2 * n + 2].push_back(m);
            m++;
        }
    }
    if(G[2 *n + 1].size() % 2 == 1)
    {
        G[2 *n + 1].push_back(2 *n + 2);
        G[2 *n + 2].push_back(2 *n + 1);
        ind[2 *n + 1].push_back(m);
        ind[2 *n + 2].push_back(m);
    }
    pop = 2 * n + 3;
    for(int i = 1; i <= 2 * n + 2; i++)
    {
        if(start[i] == 0 && G[i].size() > 0)
            dfs(i);
    }
    for(auto x : zap)
    {
        cout << mapa[x] << "\n";
    }
}