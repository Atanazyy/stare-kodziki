#include <bits/stdc++.h>

using namespace std;

const long long p = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    long long x = 1;
    cout << "{1, ";
    for(int i = 1; i <= 1e9; i++)
    {
        x = (x * i) % p;
        if(i == 5) cout << x;
        //if(i % (int)1e6 == 0) cout << x << ", ";
    }
    cout <<"}";
}