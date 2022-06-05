#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int r = 1e6 + 9;
int dp[2][4][4][4][4];
int tab[r];

int ile(int a, int b, int c)
{
    int p[4] = {0, 0, 0};
    p[a] ++;
    p[b] ++;
    p[c] ++;
    int wyn =0;
    if(p[0] > 0) wyn++;
    if(p[1] > 0) wyn++;
    if(p[2] > 0) wyn++;
    return wyn;
}

int main()
{
    int n;
    cin >> n;
    string d;
    cin >> d;
    for(int i = 0; i < d.size(); i++)
    {
        char x = d[i];
        if(x == 'M') tab[i + 1] = 0;
        if(x == 'B') tab[i + 1] = 1;
        if(x == 'F') tab[i + 1] = 2;
    }
    for(int ff = 0; ff < 4; ff++)
        for(int fs = 0; fs < 4; fs++)
            for(int sf = 0; sf < 4; sf++)
                for(int ss = 0; ss < 4; ss++)
                    dp[0][ff][fs][sf][ss] = -inf;
    dp[0][3][3][3][3] = 0;
    int wyn = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int ff = 0; ff < 4; ff++)
            for(int fs = 0; fs < 4; fs++)
                for(int sf = 0; sf < 4; sf++)
                    for(int ss = 0; ss < 4; ss++)
                        dp[1][ff][fs][sf][ss] = -inf;
        for(int ff = 0; ff < 4; ff++)
            for(int fs = 0; fs < 4; fs++)
                for(int sf = 0; sf < 4; sf++)
                    for(int ss = 0; ss < 4; ss++)
                    {
                        dp[1][fs][tab[i]][sf][ss] = max(dp[1][fs][tab[i]][sf][ss], dp[0][ff][fs][sf][ss] + ile(ff, fs, tab[i]));
                        dp[1][ff][fs][ss][tab[i]] = max(dp[1][ff][fs][ss][tab[i]], dp[0][ff][fs][sf][ss] + ile(sf, ss, tab[i]));
                        wyn = max(wyn, dp[1][fs][tab[i]][sf][ss]);
                        wyn = max(wyn, dp[1][ff][fs][ss][tab[i]]);
                    }
        swap(dp[0], dp[1]);
    }
    cout << wyn;
}