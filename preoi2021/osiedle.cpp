#include <bits/stdc++.h>

using namespace std;

pair<int, int> roz[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool byl[55][55][55][55];
bool odw[55][55];
int n, m, q;

void dfs(int x, int y)
{
    odw[x][y] = 1;
    for(auto v : roz)
    {
        if(!odw[x + v.first][y + v.second] && !byl[x][y][x + v.first][y + v.second])
            dfs(x + v.first, y + v.second);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    while(q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        byl[x1][y1][x2][y2] = byl[x2][y2][x1][y1] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                odw[i][j] = 0;
        for(int i = 0; i <= n + 1; i++)
            odw[i][0] = odw[i][m + 1] = 1;
        for(int i = 0; i <= m + 1; i++)
            odw[0][i] = odw[n + 1][i] = 1;  
       /* for(int i = 0; i <= n + 1; i++)
        {
            for(int j = 0; j <= m + 1; j++)
                cout << odw[i][j] << " ";
            cout << "\n";
        } */
        dfs(1, 1);
        bool f = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(!odw[i][j])
                {
                    f = 1;
                    break;
                }
            }
            if(f)
                break;
        }
        if(f)
        {
            cout << "NIE\n";
            byl[x1][y1][x2][y2] = byl[x2][y2][x1][y1] = 0;
        }
        else
            cout << "TAK\n";
    }
}