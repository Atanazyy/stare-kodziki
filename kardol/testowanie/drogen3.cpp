#include <bits/stdc++.h>

using namespace std;

mt19937 r;

int rr(int a, int b)
{
    return a + r() % (b - a + 1);
}

vector<int> rp(int n)
{
    vector<int> vec;
    for(int i = 0; i < n; i++)
        vec.push_back(i);
    for(int i = 0; i < n; i++)
        swap(vec[rr(0, n - 1)], vec[rr(0, n - 1)]);
    return vec;
}

int main() // do podzadania 4 5
{
    int seed;
    cin >> seed;
    r.seed(seed);
    vector <pair<int,int> > edg;
    int n = rr(1, 50000), m = 0;
    vector <int> per = rp(n);
    for(int i = 2; i <= n; i++)
    {
        int o = rr(0, i - 1);
        if(o != 0)
        {
            edg.push_back({o, i});
            m++;
        }
    }
    cout << n << " " << m << "\n";
    for(auto x : edg)
        cout << per[x.first - 1] + 1 << " " << per[x.second - 1] + 1 << "\n";
}