#include <bits/stdc++.h>
#include "zgalib.hpp"

using namespace std;

void solve()
{
    vector<int> res;
    int n = ile_liczb();
    for(int i = 1; i <= n; i++)
        res.push_back(jedna(i));
    odp(res);
}

int main()
{
    int z =init();
    while(z--)
    {
        solve();
    }
}
