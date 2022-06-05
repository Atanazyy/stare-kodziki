#include <bits/stdc++.h>

using namespace std;

const double inf = 1e17;
const int r = 109;
double G[r][r];
double tab[r][r];
int n, m;

bool czy(double x)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(G[i][j] != -inf) tab[i][j] = G[i][j] - x;
            else tab[i][j] = -inf;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(tab[i][k] != -inf && tab[k][j] != -inf)
                {
                    if(tab[i][k] + tab[k][j] >= inf) tab[i][j] = inf;
                    else tab[i][j] = max(tab[i][j], tab[i][k] + tab[k][j]);
                }
    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << tab[i][j] << " ";
        cout << "\n";
    }*/
    for(int i = 1; i <= n; i++)
        if(tab[i][i] > 0) return 1;
    return 0;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            G[i][j] = -inf;
    while(m--)
    {
        long long a, b, x;
        cin >> a >> b >> x;
        G[a][b] = x;
    }
    double p = -1e6, k = 1e6, sr, eps = 0.00001;
    //czy(0);
    while(k - p > eps)
    {
        sr = (p + k) / 2;
        if(czy(sr))
            p = sr;
        else    
            k = sr;
    }
    cout << fixed;
    cout << setprecision(4) << k;
}