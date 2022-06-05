#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<int> tab;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tab.push_back(x);
    }
    long long wyn = 1e18;
    for(int i = 0; i < n; i++)
    {
        long long akt = 0;
        long long ost = 0;
        for(int j = i + 1; j < n; j++)
        {
            long long ile = ceil((long double)ost / tab[j]);
            //cout <<ile;
            if(ile * tab[j] == ost)
                ile++;
            akt += ile;
            ost = ile * tab[j];
        }
        ost = 0;
        for(int j = i - 1; j >= 0; j--)
        {
            long long ile = ceil((long double)ost / tab[j]);
            if(ile * tab[j] == ost)
                ile++;
            akt += ile;
            ost = ile * tab[j];
        }
        wyn = min(wyn, akt);
    }
    cout << wyn << "\n";
}

int main()
{
    //int t;
    //cin >> t;
    //while(t--)
        solve();
}