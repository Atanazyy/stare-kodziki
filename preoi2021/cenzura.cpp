#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;

vector <int> G[r];
vector <int> tab[r];
int wyn[r];

void dfs(int v)
{
    if(G[v].size() == 0)
        return;
    int ma = -1, gd;
    for(auto x : G[v])
    {
        dfs(x);
        if(ma < (int)tab[x].size())
        {
            ma = tab[x].size();
            gd = x;
        }
    }
    swap(tab[gd], tab[v]);
    for(auto x : G[v])
    {
        int j = tab[v].size() - 1;
        for(int i = tab[x].size() - 1; i >= 0; i--)
        {
            tab[v][j] += tab[x][i];
            j --;
        }
    }
    //cout << v << ": ";
    tab[v].push_back(G[v].size());
    ma = 1, gd = 0;
    int akt = 1;
    for(int i = tab[v].size() - 1; i >= 0; i--)
    {
        //cout << tab[v][i] << " ";
        if(ma < (int)tab[v][i])
        {
            gd = akt;
            ma = tab[v][i];
        }
        akt ++;
    }
    wyn[v] = gd;
    //cout << "\n";
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
        cout << wyn[i] << "\n";
}