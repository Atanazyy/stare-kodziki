#include <bits/stdc++.h>

using namespace std;

const int r = 2e3 + 9;
long long mod = 1e9 + 7;
pair<int, long long> tab[r][r]; 

int main()
{
    int n, m;
    string s1, s2;
    cin >> n >> m >> s1 >> s2;
    tab[0][0] = {0, 1};
    for(int i = 1; i <= n; i++)
    {
        tab[i][0] = {i, 1};
    }
    for(int i = 1; i <= m; i++)
    {
        tab[0][i] = {i, 1};
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                tab[i][j] = {tab[i - 1][j - 1].first + 1, tab[i -1][j - 1].second};
            }
            else
            {
                tab[i][j].first = 1 + min(tab[i - 1][j].first, tab[i][j - 1].first);
                if(tab[i][j].first - 1 == tab[i - 1][j].first) tab[i][j].second = (tab[i][j].second + tab[i-1][j].second) % mod;
                if(tab[i][j].first - 1 == tab[i][j - 1].first) tab[i][j].second = (tab[i][j].second + tab[i][j - 1].second) % mod;
            }
           //cout<<"{"<<tab[i][j].first<< " " <<tab[i][j].second<<"} ";
        }
        //cout<<"\n";
    }
    cout<<tab[n][m].second;
}