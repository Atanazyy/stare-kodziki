#include <bits/stdc++.h>

using namespace std;

const long long XD = 1e10;

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

long long odw(long long m, long long n)
{
    long long w1 = m, w2 = 1, w3 = n;
    long long a = w1, b = -w3, c = w2; 
    long long x, y;
    long long g = gcd(abs(a), abs(b), x, y);
    if (c % g) 
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
    return max(x + (b / g)  * XD, x - (b / g) * XD);
}

int main()
{
    long long n1, n2, a1, a2;
    cin >> n1 >> n2 >> a1 >> a2;
    long long m1 = n2, m2 = n1;
    long long om1 = odw(m1, n1) % n1, om2 = odw(m2, n2) % n2;
    long long N = n1 * n2;
    //cout << om1 << "_" << om2;
    cout << (((a1 * om1) % n1) * n2 + ((a2 * om2) % n2) * n1) % N;
}