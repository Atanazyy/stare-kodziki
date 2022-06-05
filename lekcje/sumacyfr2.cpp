#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9; 
pair<int, int> tab[r];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        tab[i].first = max(tab[i - 1].first, tab[i - 1].second) + x;
        tab[i].second = tab[i - 1].first + 9;
    }
    cout << max(tab[n].first, tab[n].second);
}