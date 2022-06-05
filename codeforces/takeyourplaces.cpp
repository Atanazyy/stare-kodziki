#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;
const long long inf = 1e15; 

struct Solve
{
    int tab[r];

    long long count(int n)
    {
        vector <int> jed;
        for(int i = 1; i <= n; i++)
        {
            if(tab[i] % 2 == 0)
                jed.push_back(i);
        }
        if(2 * jed.size() - n != 0 && 2 * jed.size() - n != 1)
            return inf;
        long long wyn = 0;
        for(int i = 1; i <= n; i += 2)
        {
            wyn += abs(jed[i / 2] - i); 
        }
        return wyn;
    }

    void solve()
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> tab[i];
        long long ans = count(n);
        for(int i = 1; i <= n; i++)
            tab[i] ++;
        ans = min(count(n), ans);
        if(ans == inf) 
            cout << "-1\n";
        else 
            cout << ans << "\n";
        return;
    }
};


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        Solve s;
        s.solve();
    }
}