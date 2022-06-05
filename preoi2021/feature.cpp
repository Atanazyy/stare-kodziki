#include <bits/stdc++.h>

using namespace std;

const int r = 509;
bool tab[r][r];
int wyn[r][r];
pair<int, int> rozv[4] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
pair<int, int> roze[4] = {{0, 0}, {-1, 0}, {0, -1}, {-1, -1}};      
bool rozk[4] = {1, 0, 0, 1};
deque <pair<int, int> > kol;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    if((n + m) % 2 == 1) 
    {
        cout << "NIE";
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        char p = '/';
        for(int j = 0; j < m; j++)
        {
            if(s[j] == p) tab[i][j] = 0;
            else tab[i][j] = 1;
        }
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            wyn[i][j] = -1;
    wyn[0][0] = 0;
    kol.push_front({0, 0});
    while (!kol.empty())
    {
        int x = kol.front().first, y = kol.front().second;
        kol.pop_front();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + rozv[i].first, ny = y + rozv[i].second;
            if(nx < 0 || ny < 0 || nx > n || ny > m) 
                continue;
            int k = 1;
            if(tab[x + roze[i].first][y + roze[i].second] == rozk[i]) 
                k = 0;
            if(wyn[nx][ny] != -1 && wyn[nx][ny] <= wyn[x][y] + k) 
                continue;
            wyn[nx][ny] = wyn[x][y] + k;
            if(k == 0)
                kol.push_front({nx, ny});
            else
                kol.push_back({nx, ny});
        }
    }
    /*for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            cout << wyn[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << wyn[n][m];
}