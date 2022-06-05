#include <bits/stdc++.h>

using namespace std;

int r[100009];
int b[100009];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> r[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    cout << "\033[34m  *\n ***\n\033[31m  *\n ***\n*****\n\033[0m";
    for(int i = 1; i <= n + m; i++)
    {
        long long wyn=0;
        for(int j = 1 ; j < i; j++)
        {
            wyn += r[j] * b[i-j];
        }
        cout << wyn << " ";
    }
}