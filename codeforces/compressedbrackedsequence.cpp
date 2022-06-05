#include <bits/stdc++.h>

using namespace std;

const int r = 1e3 + 9;

long long tab[r];

int main()
{
    int n;
    cin >> n;
    unsigned long long wyn = 0;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 0) 
            continue;
        long long po = 1, ko = tab[i];
        for(int j = i + 1; j <= n; j++)
        {
            if(j % 2 == 0)
            {
                if(ko < 0)
                    break;
                if(po > )
                wyn += min(tab[i], tab[j] - ko) - max((long long)1, po) + 1;
                po = max((long long)0, po - tab[j]);
                ko = ko - tab[j];
            }
            else
            {
                po += tab[j];
                ko += tab[j];
            }
        }
    }
    cout << wyn;
}