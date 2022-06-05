#include <bits/stdc++.h>

using namespace std;

pair<int, int> o[509][509];

pair<int, int> F(pair<int , int> x)
{
    if(o[x.first][x.second] == x)
        return x;
    o[x.first][x.second] = F(o[x.first][x.second]);
    return o[x.first][x.second];
}

bool U(pair<int, int> a, pair<int, int> b)
{
    //cout << a.first << " " << a.second <<", " << b.first << " " << b.second <<"\n";
    auto oa = F(a);
    auto ob = F(b);
    if(oa == ob)
    {
        return 0;
    }
    o[oa.first][oa.second] = ob;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            o[i][j] = {i, j};
        }
    }
    for(int i = 0; i < m; i++)
    {
        U({0, i}, {0, i + 1});
        U({n, i}, {n, i + 1});
    }
    for(int i = 0; i < n; i++)
    {
        U({i, 0}, {i + 1, 0});
        U({i, m}, {i + 1, m});
    }
    for(int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2)
        {
            if (U({x1, min(y1, y2)}, {x1 - 1, min(y1, y2)}))
                cout << "TAK\n";
            else
                cout << "NIE\n";
        }
        if(y1 == y2)
        {
            if(U({min(x1, x2), y1}, {min(x1, x2), y1 - 1}))
                cout << "TAK\n";
            else
                cout << "NIE\n";
        }
    }
}