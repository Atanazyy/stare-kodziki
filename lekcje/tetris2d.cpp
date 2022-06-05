#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 9;
int m[2 * N];
int M[2 * N];
int am;

void maxH(int a, int b, int w, int u, int v)
{
    am = max(M[w], am);
    if(u > a && v < b)
    {
        am = max(m[w], am);
        return;
    }
    if((u + v) / 2 > a)
        maxH(a, b, w*2, u, (u + v) / 2);
    if((u + v) / 2 + 1<b)
        maxH(a, b, w * 2 + 1, (u + v) / 2 + 1, v);
}

void akt(int a, int b, int w, int u, int v)
{
    m[w] = max(m[w], am);
    if(u >= a && v <= b)
    {
        M[w] = max(M[w], am);
        return;
    }
    if((u + v) / 2 >= a)
    {
        akt(a, b, w * 2, u, (u + v) / 2);
    }
    if((u + v) / 2 + 1 <= b)
        akt(a, b, w * 2 + 1, (u + v) / 2 + 1, v);
}

int main()
{
    int d, n;
    cin>> d >> n;
    if(d == 1)
    {
        cout << n;
        return 0;
    }
    d =ceil(log2(d));
    d = 1 << d;
    while(n--)
    {
        int a, b, dl;
        cin >> dl >> a;
        b = a + dl;
        am = 0;
        maxH(a, b, 1, 1, d);
        am++;
        akt(a, b, 1, 1, d);
    }
    cout << m[1];
}
