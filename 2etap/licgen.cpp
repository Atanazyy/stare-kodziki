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
    int n = rr(20, 1000 * 1000), k = rr(1, 5), c = rr(1, 5);
    cout << n << " " << k << " " << c <<"\n";
}