#include <bits/stdc++.h>

using namespace std;

const int r = 2e6 + 9;

vector <int> ind[r];
vector <int> G[r];
bool odwe[r];
bool odwn[r];
vector<int> res;
int start[r];

void dfs(int v)
{
    odwn[v] = 1;
    for(int i = start[v]; i < G[v].size(); i ++)
    {
        start[v] = i;
        int u = G[v][i];
        int id = ind[v][i];
        if(!odwe[id])
        {
            odwe[id] = 1;
            dfs(u);
        }
    }
    res.push_back(v);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        ind[a].push_back(i);
        ind[b].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        if(G[i].size() % 2 != 0)
        {
            cout << "NIE\n";
            return 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(G[i].size() > 0)
        {
            dfs(i);
            break;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!odwn[i] && G[i].size() != 0)
        {
            cout << "NIE\n";
            return 0;
        }
    }
    cout << "TAK\n";
    for(int i =  0; i < res.size() - 1; i ++)
        cout << res[i] << " ";
}