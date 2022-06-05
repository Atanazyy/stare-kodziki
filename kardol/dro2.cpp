#include <bits/stdc++.h>

using namespace std;

const int r = 5e3 + 9;
vector <int> tab[r];
bool odw[r];

void dfs(int v)
{
    odw[v] = 1;
    for(auto u : tab[v])
    {
        if(!odw[u])
        {
            dfs(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        tab[a].push_back(b);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) odw[j] = 0;
        dfs(i);
        int wyn = -1;
        for(int j = 1; j <= n; j++) wyn += odw[j];
        cout << wyn << "\n";
    }
}
