#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        long long x;
        cin >> x;
        long long m = 1;
        long long g = 2 * x + m - m * m;
        long long ans;
        long long p;
        while(g > 0)
        {
            if(g % (2 * m) == 0)
            {
                p = g / (2 * m);
                ans = m;
            }
            m++;
            g = 2 * x + m - m * m;
        }
        cout << p << " " << p + ans - 1 << "\n";
    }
}
