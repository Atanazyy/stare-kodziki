#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b, long long& x, long long& y) 
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    long long w1, w2, w3;
    cin >> w1 >> w2 >> w3;
    long long a = w1, b = -w3, c = w2; 
    long long x, y;
    long double g = gcd(abs(a), abs(b), x, y);
    if (c % (long long)g) 
    {
        cout << "NIE";
        return 0;
    }
    x *= c / g;
    y *= c / g;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    //cout << x << " " << y;
    //cout << g << "\n" << a << " * " << x << " + " << b << " * " << y << " = " << c;
   // cout << -x * g / b<< " " << ceil(-x * g / b) - 1 << "\n";
    
    if(x * (long long)g * b < 0)
    {
        long long xd = ((long long)ceil(-x * g / b) ) * b / (long long)g  + x;
        if(xd >= 0)
            cout << xd;
        else
            cout << max(xd + b / (long long)g, xd - b / (long long)g);
        return 0;
    }
    else
    {
       // cout << "xd";
        long long xd = ((long long)floor(-x * g / b)) * b / (long long)g  + x;
        if(xd >= 0)
            cout << xd;
        else
            cout << max(xd + b / (long long)g, xd - b / (long long)g);
        return 0;
    }
}