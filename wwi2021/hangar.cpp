#include <bits/stdc++.h>

using namespace std;

const int r = 1e3 + 9;
bool zap[r][r];
bool tab[r][r];
bool odw[r][r];
pair<int, int> roz[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}

void dfs(int x, int y)
{
    odw[x][y] = 1;
    for(auto x : roz)
}

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i ++)
    {
        string a;
        cin >> a;
        int j = 1;
        for(auto x : a)
        {
            if(a == '#')
                tab[i][j] = 1; 
            j++;
        }
    }
    for(int i = 0; i <= n + 1; i++)
    {
        tab[0][i] = 1;
        tab[i][0] = 1;
        tab[n + 1][i] = 1;
        tab[i][n + 1] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            zap[i][j] = tab[i][j];
        }
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout<<odw[i][j]<<"";
        }
        cout<<"\n";
    }
}