#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;

vector <int> G[r];
vector <int> tab[r];
pair <int, int> wyn[r];

void dfs(int v)
{
    if(G[v].size() == 0)
        return;
    int ma = -1, gd;
    for(auto x : G[v])
    {
        dfs(x);
        if(ma <= (int)tab[x].size())
        {
            ma = tab[x].size();
            gd = x;
        }
    }
    swap(tab[gd], tab[v]);
    wyn[v] = wyn[gd];
    wyn[v].first ++;
    //for(auto x : tab[v]) cout << x << " ";
    //cout << wyn[v].first << " " << wyn[v].second <<"\n";
   // cout << v <<": "; 
    for(auto x : G[v])
    {
        int j = tab[v].size() - 1;
        int gle = 2;
        for(int i = tab[x].size() - 1; i >= 0; i--)
        {
            tab[v][j] += tab[x][i];
            //cout << tab[v][j] << " ";
            if(tab[v][j] == wyn[v].second)
                wyn[v].first = min(wyn[v].first, gle);
            else if(tab[v][j] > wyn[v].second)
                wyn[v] = {gle, tab[v][j]};
            gle++;
            j--;
        }
    }
   // cout << wyn[v].first << " " << wyn[v].second <<"\n";
   // cout << "\n";
    tab[v].push_back(G[v].size());
    //cout << v << ": ";
    //for(auto x : tab[v]) cout << x << " ";
    //cout <<"\n";
    if((int)G[v].size() >= wyn[v].second)
        wyn[v] = {1, G[v].size()};
    if(wyn[v].second == 1) wyn[v].first = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        G[x].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
        cout << wyn[i].first << "\n";
}