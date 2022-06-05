#include <bits/stdc++.h>

using namespace std;

const int r = 5e5 + 9;
int tab[r];
int tyl[r];

int main()
{
    int n;
    long long sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i];
        sum += tab[i];
    }
    if(sum % 3 != 0)
    {
        cout << 0;
        return 0;
    }
    sum = sum / 3;
    long long akt = 0;
    for(int i = n; i >= 1; i--)
    {
        akt += tab[i];
        tyl[i] = tyl[i] + tyl[i + 1];
        if(akt == sum)
            tyl[i] ++;
    }
    long long wyn = 0;
    akt = 0;
    for(int i = 1; i <= n - 2; i++)
    {
        akt += tab[i];
        if(akt == sum)
            wyn += tyl[i + 2]; 
    }
    cout << wyn;
    return 0;
}