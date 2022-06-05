#include <bits/stdc++.h>

using namespace std;

mt19937 r;


int rr(int a, int b)
{
    return a + r() % (b - a + 1);
}

string tab[509];
set <string> slo;

int main()
{
    int seed;
    cin >> seed;
    r.seed(seed);
    int n, l;
    n = rr(1, 500);
    l = rr(4, 100);
    cout << n << " " << l << "\n";
    int nr = 0;
    slo.insert("");
    while(n--)
    {
        while(slo.find(tab[nr]) != slo.end())
        {
            tab[nr] = "";
            for(int i = 0; i < l; i++)
                tab[nr] = tab[nr] + (char)rr('a', 'z');
        }
        slo.insert(tab[nr]);
        nr++;
        //cout << tab[nr];
    }
    sort(tab, tab + nr);
    for(int i = 0;  i < nr; i++)
      cout << tab[i] << "\n";
}