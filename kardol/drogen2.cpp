#include <bits/stdc++.h>

using namespace std;

mt19937 r;

int rr(int a, int b)
{
    return a + r() % (b - a + 1);
}

int main() // do podzadan 3 4 5
{
    int seed;
    cin >> seed;
    r.seed(seed);
    vector <pair<int,int> > edg;
    int n = rr(1, 50000), m = 0;
    for(int i = 2; i <= n; i++)
    {
        int o = rr(0, i - 1);
        if(o != 0)
        {
            edg.push_back({o, i});
            m++;
        }
    }
    cout << n << " " << m << "\n";
    for(auto x : edg)
        cout << x.first << " " << x.second << "\n";
}