#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;

int tab[r];
int fil[r];
int byl[r];

int main()
{
    long long wyn = 0, akt = 0;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    for(int i = 1; i <= m; i++)
        cin >> fil[i];
    for(int i = 1; i <= n; i++)
    {
        akt = 0;
        for(int j = 1; j <= m; j++)
            byl[j] = 0;
        for(int j = i; j <= n; j++)
        {
            if(byl[tab[j]] == 0) 
                akt += fil[tab[j]];
            if(byl[tab[j]] == 1)
                akt -= fil[tab[j]];
            byl[tab[j]] ++;
            wyn = max(wyn, akt);
        }
    }
    cout << wyn;
}