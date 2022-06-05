#include <bits/stdc++.h>

using namespace std;

const int r = 1e7 + 9;
const int inf = 1e9;
int tab[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> tab[i];
    for(int i = 0; i < n; i++)
    {
        int d = 0;
        while(tab[i] >= tab[min(n - 1, i + d)] && tab[i] >= tab[max(0, i - d)] && d <= n)
            d++;
        if(d == n + 1) cout << "inf ";
        else cout << d << " ";
    }
}