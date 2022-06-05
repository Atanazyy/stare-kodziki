#include <bits/stdc++.h>

using namespace std;

long long romb(int n)
{
    long long wyn = n;
    while(n > 0)
    {
        wyn *= n % 10;
        n /= 10;
    }
    return wyn;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int wyn = 0;
    for(int i = 1; i <= b; i++)
    {
        long long x = romb(i);
        if(x >= a && x <= b)
            wyn++;
    }
    cout << wyn;
}