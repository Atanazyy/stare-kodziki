#include <bits/stdc++.h>

using namespace std;

const int r = 509;
const long long inf = 1e9;
long long tab[r][r];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i != j) tab[i][j] = inf;
            else tab[i][i] = 0;
        }
    while(m--)
    {
        long long a, b, x;
        cin >> a >> b >> x;
        tab[a][b] = min(x, tab[a][b]);
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(tab[i][k] != inf && tab[k][j] != inf)
                {
                    if(tab[i][k] + tab[k][j] <= -inf) tab[i][j] = -inf;
                    else tab[i][j] = min(tab[i][j], tab[i][k] + tab[k][j]);
                }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(tab[i][j] == inf) 
            {
                cout << "* ";
                continue;
            }
            bool f = 0;
            for(int k = 1; k <= n; k++)
            {
                if(tab[i][k] != inf && tab[k][j] != inf && tab[k][k] < 0)
                {
                    f = 1;
                    break;
                }
            }
            if(f) cout << "-oo ";
            else cout << tab[i][j] << " "; 
        }
        cout << "\n";
    }
}