#include <bits/stdc++.h>

using namespace std;

const int r = 69; //xD
bool tab[r][r];
bool odw[r];
int wyn[r];
int n, m;

void dfs(int v)
{
    odw[v] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(!odw[i] && tab[v][i])
        {
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        tab[a][b] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= n; k++)
        {
            if(i == k) continue;
            for(int j = 1; j <= n; j++) odw[j] = 0;
            dfs(i);
            wyn[i] += odw[k];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << wyn[i] << "\n";
    }
}
