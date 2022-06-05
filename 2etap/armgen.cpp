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
    cout << seed << " " << 1 << " " << 1;
}