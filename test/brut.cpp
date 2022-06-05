#include <bits/stdc++.h>

using namespace std;

int main()
{
    int wyn = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        wyn += x;
    }
    if(wyn % 100 == 0)
        cout << wyn + 1;
    else
        cout << wyn;
}
