#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    string s;
    cin >> n >> s;
    long long wyn = -1000*1000*1000;
    long long x = 0;
    long long y = 0;
    int i = 1;
    for(auto a: s)
    {
        if(a == 'D')
            y--;
        else
            y++;
        x++;
        if(i == n)
            continue;
        long long z = n * y;
        z = floor((long double)z / (long double)x);
        z++;
        wyn = max(wyn, z);
        i++;
        //cout << n << " " << y <<" "<< x << " " <<z << " "<< max((long long)0, wyn + 7) << "\n";
    }
    cout << max((long long)0, wyn - y);
}