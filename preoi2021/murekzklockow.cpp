#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9, inf = 1e9;
vector <int> tab[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        tab[x].push_back(i);
    }
    for(int i = 1e6; i >= 1; i--)
    {
        int w1 = inf, w2 = inf;
        for(int j = i; j <= 1e6; j += i)
        {
            for(auto x : tab[j])
            {
                if(x <= w1)
                {
                    w2 = w1;
                    w1 = x;
                }
                else if(x <= w2)
                    w2 = x;
            }
        }
        if(w1 != inf && w2 != inf)
        {
            cout << i << "\n" << w1 << " " << w2;
            return 0;
        }
    }
}