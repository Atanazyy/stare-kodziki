#include <bits/stdc++.h>

using namespace std;

int p( int a , int b) 
{
    return a + rand () %(b - a +1) ;
}

int main()
{
    int a;
    cin >> a;
    srand(a);
    int n = p(1, 2), N = 1;
    cout << n <<"\n";
    while(n--)
    {
        int x = p(1, 6);
        cout << x<< " ";
        N*= x;
    }
}