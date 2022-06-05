#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int tab[10009][69];
int nas = 1;

int zas[300];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    if(n < 6)
    {
        cout << 0;
        return 0;
    }
    tab[0][1] = 1;
    zas[s[0]] = 1;
    for(int i = 1; i < n; i++)
    {
        if(zas[s[i]] == 0)
        {
            nas++;
            zas[s[i]] = nas;
        }
        for(int j = 1; j <= nas; j++)
            tab[i][j] = tab[i - 1][j];
        tab[i][zas[s[i]]]++;
    }
    long long wyn = 0;
    int kwa = 1; 
    for(int i = 2; i < n; i++)
    {
        kwa = kwa - tab[i - 2][zas[s[i - 1]]] * tab[i - 2][zas[s[i - 1]]] + tab[i - 1][zas[s[i - 1]]] * tab[i - 1][zas[s[i - 1]]];
        //cout << kwa << " ";
        for(int j = i + 1; j < n; j++)
        {
            if(s[j] != s[i]) 
                continue;
            for(int k = 1; k <= nas; k++)
            {
                if(k == zas[s[i]])
                    continue;
                long long tem = (i - tab[i - 1][k] - tab[i - 1][zas[s[i]]]) * (i - tab[i - 1][k] -  tab[i - 1][zas[s[i]]]) - kwa;
                tem += tab[i - 1][k] * tab[i - 1][k];
                tem += tab[i - 1][zas[s[i]]] * tab[i - 1][zas[s[i]]];
                tem /= 2;
                tem = (long long)tem * (tab[j][k] - tab[i - 1][k]);
                tem = (long long)tem * (tab[n - 1][k] - tab[j - 1][k]);
                wyn = (wyn + tem) % mod;
                //if(tem != 0) cout << i << " " << j << " " << (char)(k + 'a') << " " <<  tem << "\n";
            }
        }
    }
    cout << wyn % mod;
}