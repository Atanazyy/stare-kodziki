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
    int n = p(1, 10);
    int m = p(1,15);
    cout<< n <<" "<< m<<"\n";
    
    while(m--)
    {
        int v1 = p(1,n);
        int v2 = p(1,n);
        while(v1 == v2) v2 = p(1,n);
        cout<<v1<<" "<<v2<<"\n";
    }
}