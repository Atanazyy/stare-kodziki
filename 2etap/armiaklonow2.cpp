#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18 + 9;
unordered_map <int, long long> tab[200 * 1000 + 9];
set <int> kol[200 * 1000 + 9];

int main()
{
    int n;
    long long a, b;
    cin >> n >> a >> b;
    long long wyn = inf;
    tab[1][0] = 0;
    kol[1].insert(0);
    //int lic = 0;
    for(int i = 1; i <= 2 * (n + 1); i++)
    {
        kol[i].insert(i);
        //lic += kol[i].size();
        for(auto j : kol[i])
        {
            if(i + j <= 2 * (n + 1)) 
            {
                if(tab[i + j].find(j) != tab[i + j].end()) 
                    tab[i + j][j] = min(tab[i][j] + b, tab[i + j][j]);
                else
                    tab[i + j][j] = tab[i][j] + b;
                kol[i + j].insert(j);
            }
            if(tab[i].find(i) != tab[i].end()) 
                tab[i][i] = min(tab[i][j] + a, tab[i][i]);
            else
                tab[i][i] = tab[i][j] + a;
            if(i > n) wyn = min(wyn, tab[i][j]);
        }
    }
    cout << wyn;
    /*for(auto x : tab)
    {
        cout << x.first.first << " " << x.first.second << " " << x.second <<"\n";
    }*/
}