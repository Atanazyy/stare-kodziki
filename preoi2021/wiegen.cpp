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
    seed -=100;
    r.seed(seed);
    int n;
    n = rr(1, 10);
    cout << n << "\n";
    while(n--)
    {
        if(rr(1, 2) == 1)
            cout << 'D';
        else
            cout << 'G';
    }
}