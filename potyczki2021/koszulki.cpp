#include <bits/stdc++.h>

using namespace std;

int tab[50000];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i];
    }
    sort(tab + 1, tab + n + 1);
    reverse(tab + 1, tab + n + 1);
    for(int i = 1; i <= n; i++)
    {
        cout << tab[i]<< " ";
    }
    m ++;
    while(m <= n && tab[m] == tab[m - 1])
        m++;
    cout << m - 1;
}