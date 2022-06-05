#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k, c;
    cin >> n >> k >> c;
    int byl = 0;
    for(int i = 1; i <= n; i++)
    {
        if(__gcd(n, i) == 1)
        {
            byl ++;
            if(byl >= k)
                cout << i << " ";
        }
        if(byl >= k + c - 1)
            return 0;
    }
}