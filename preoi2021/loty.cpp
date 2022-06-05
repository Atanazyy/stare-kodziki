#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n % 4 == 2 || n % 4 == 3)
    {
        cout << "NIE\n";
        return 0;
    }
    cout << "TAK\n";
    if(n == 1)
    {
        cout << "1 1";
        return 0;
    }
    if(n == 4)
    {
        cout << "3 4 2 3 2 4 1 1";
        return 0;
    }
    if(n == 5)
    {
        cout << "1 1 3 4 5 3 2 4 2 5";
        return 0;
    }
    if(n % 4 == 0)
    {
        int k = n / 2;
        for(int i = n; i >= 2; i -= 2)
            cout << i << " ";
        cout << n - 1 << " ";
        for(int i = 2; i <= n; i += 2)
            cout << i << " ";
        cout << k - 1 << " ";
        for(int i = n - 3; i >= k + 1; i -= 2)
            cout << i << " ";
        for(int i = k - 3; i >= 3; i -= 2)
            cout << i << " ";
        cout << n - 1 << " " << k - 1 << " ";
        for(int i = 3; i <= k - 3; i += 2)
            cout << i << " ";
        cout << "1 1 ";
        for(int i = k + 1; i <= n - 3; i += 2)
            cout << i << " ";
        return 0;
    }
    int k = n / 2;
    for(int i = n - 1; i >= 2; i -= 2)
        cout << i << " ";
    cout << n << " ";
    for(int i = 2; i <= n - 1; i += 2)
        cout << i << " ";
    cout << k - 1 << " ";
    for(int i = n - 2; i >= k + 1; i -= 2)
        cout << i << " ";
    for(int i = k - 3; i >= 3; i -= 2)
        cout << i << " ";
    cout << k - 1 << " " << n << " ";
    for(int i = 3; i <= k - 3; i += 2)
        cout << i << " ";
    cout << "1 1 ";
    for(int i = k + 1; i <= n - 2; i += 2)
        cout << i << " ";
}