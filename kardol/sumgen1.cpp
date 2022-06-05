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
    int s =1;
    int m = rr(1, 200);
    int q = rr(1,10*1000);
    cout << s << " " << m <<" " << q <<"\n";
    while(q--)
        cout << rr(1, 200) <<"\n";
}