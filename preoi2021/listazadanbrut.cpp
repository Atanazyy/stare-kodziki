#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;

int tab[r];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tab[i];
    }
    for(int i = 0; i < n; i++)
    {
        int wyn = 0;
        for(int j = i - 1; j >= 0; j--)
        {
            if(tab[j] < tab[i]) wyn++;
        }
        cout << wyn <<"\n";
    }
}