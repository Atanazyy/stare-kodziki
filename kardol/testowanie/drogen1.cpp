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

int main() // test do podzadan 1 2 5
{
    int seed;
    cin >> seed;
    r.seed(seed);
    vector <pair<int,int> > edg;
    int n = 0, m = 0;
    int ms = rr(1, 500);
    for(int i = 0; i < ms; i++)
    {
        int s = rr(2, 10);
        if(i > 0 && rr(0, 25)!= 0)
        {
            edg.push_back({rr(1, n), n + rr(1, s)});
            m++;
        }
        for(int j = n + 1; j < n + s; j++)
        {
            edg.push_back({j, j + 1});
            m++;
        }
        edg.push_back({n + s, n + 1});
        m++;
        n += s;
    }
    cout << n << " " << m << "\n";
    vector <int> per = rp(n);
    for(auto x : edg)
        cout << per[x.first - 1] + 1 << " " << per[x.second - 1] + 1 << "\n";
}