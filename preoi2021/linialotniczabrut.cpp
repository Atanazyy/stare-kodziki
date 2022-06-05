#include <bits/stdc++.h>

using namespace std;

vector<int> ust;

const int r = 5e6;

int tab[r];

bool spr(int n)
{
    for(int i = 1; i <= 2 * n; i++)
        tab[i] = 0;
    int i = 1;
    for(auto x : ust)
    {
        while(tab[i] != 0)
            i++;
        if(i + x > 2 * n)
            return 0;
        if(tab[i + x] != 0)
            return 0;
        tab[i] = x;
        tab[i + x] = x;
    }
    return 1;
}

void wyp(int n)
{
    for(int i = 1; i <= 2 * n; i++)
        tab[i] = 0;
    for(auto x : ust)
    {
        int i = 1;
        while(tab[i] != 0)
            i++;
        tab[i] = x;
        tab[i + x] = x;
    }
    for(int i = 1; i <= 2 * n; i++)
        cout << tab[i] << " ";
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        ust.push_back(i);
    do
    {
        if(spr(n))
        {
            cout << "TAK\n";
            wyp(n);
            return 0;
        }
    }
    while(next_permutation(ust.begin(), ust.end()));
    cout << "NIE\n";
}