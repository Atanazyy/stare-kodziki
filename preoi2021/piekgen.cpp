#include <bits/stdc++.h>

using namespace std;

mt19937 r;


int rr(int a, int b)
{
    return a + r() % (b - a + 1);
}

bool byl[1009][1009];

int main()
{
    int seed;
    cin >> seed;
    r.seed(seed);
    int n;
    n = rr(1, 3);
    cout << n << "\n";
    while(n--)
    {
        int a = rr(1, 3), b = rr(1, 3);
        while(byl[a][b])
        {
            a = rr(1, 10);
            b = rr(1, 10);
        }
        cout << a << " " << b << "\n";
    }
}