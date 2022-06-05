#include <bits/stdc++.h>
using namespace std;
 
vector <long long> vec;
vector <long long> nie;

void primeFactors(long long n) //z geeks for geeks
{
    if(n % 2 == 0)
        vec.push_back(2);
    while (n % 2 == 0)
    {
        n = n/2;
    }
    for (long long i = 3; i <= sqrt(n); i = i + 2)
    {
        if(n % i == 0)
            vec.push_back(i);
        while (n % i == 0)
        {
            n = n/i;
        }
    }
    if (n > 2)
        vec.push_back(n);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n, k, c;
    cin >> n >> k >> c;
    long long byl = 0, start = 1;
    if(n > 1000 * 1000)
    {
        primeFactors(n);
        for(auto x : vec)
        {
            long long y = x;
            while(y <= n)
            {
                nie.push_back(y);
                y += x;
            }
        }
        sort(nie.begin(), nie.end());
        cout << nie.size();
        long long ost = 0;
        long long ile = 0;
        long long pop = 0;
        for(auto x : nie)
        {
            if(ost == x)
                continue;
            long long prze = x - 1 - pop;
            pop++;
            //cout << prze << " " << x << "\n";
            if(prze >= k)
            {
                start = ost + 1;
                break;
            }
            ile = prze;
            ost = x;
        }
        //cout << start << " " << ile ;
        byl = ile;
    }
    for(long long i = start; i <= n; i++)
    {
        if(__gcd(n, i) == 1)
        {
            byl ++;
            if(byl >= k)
                cout << i << " ";
        }
        if(byl >= k + c - 1)
            return 0;
    }
}