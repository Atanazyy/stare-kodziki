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
    int n = rr(1, 1000 * 1000), m = rr(1, 1000 * 1000);
    cout << n << " " << m <<"\n";
    while(m--)
    {
        cout << rr(1, n) << " " << rr(1, n) << " " <<(1000 * 1000 * 1000) << "\n";
    }
    cout << "1 2";
}