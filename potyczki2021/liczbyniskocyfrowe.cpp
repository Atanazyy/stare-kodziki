#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin >> a;
    if((a % 10) < 5 && (a / 10) % 10 < 5 && (a / 100) % 10 < 5)
        cout << "TAK";
    else 
        cout << "NIE";
}