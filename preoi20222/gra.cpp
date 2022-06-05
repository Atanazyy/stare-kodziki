#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

struct S
{
    void solve()
    {
        int n,k;
        cin >> n >> k;
        vector<int> xd;
        for(int i = 1; i <= n; i++)
            xd.push_back(i);
        long long wyn = 0;
        do
        {
            int akt = 0;
            for(int i = 1; i <= n; i++)
            {
                akt += max(i, xd[i - 1]);
            }
            if(akt == k)
                wyn ++;
        }
        while(next_permutation(xd.begin(), xd.end()));
        for(int i = 1; i <= n; i++)
            wyn = (wyn * i) % mod;
        cout << wyn << "\n";
    }
};

int main()
{
    int z;
    cin >> z;
    while(z --)
    {
        S s;
        s.solve();
    }
}
