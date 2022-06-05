#include <bits/stdc++.h>

using namespace std;

mt19937 r;

int rr(int a, int b)
{
    return a + r() % (b - a + 1);
}

int main() 
{
    int seed;
    cin >> seed;
    r.seed(seed);
    int n = rr(2, 100);
    cout << n << "\n";
    int y = 2;
    for(int i = 1; i <= n; i++)
    {
        int x = rr(1, 2);
        if(x == 1)
        {
            cout << "? " << rr(1, y) << "\n";
        }
        else
        {
            cout << "Z " << rr(1, y) << "\n";
            y++;
        }
    }
}