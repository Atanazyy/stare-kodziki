#include <bits/stdc++.h>

using namespace std;

const int p1 = 313, p2 = 997, N = 1e9 + 7, M = 1e9 + 9, r = 1e6;
long long h1[r], h2[r], pot1[r], pot2[r];

pair<int, int> hasz(int p, int roz)
{
    return {(h1[p + roz] - (h1[p] * pot1[roz]) % N + N) % N, (h2[p + roz] - (h2[p] * pot2[roz]) % M + M) % M};
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int q;
    pot1[0] = 1;
    pot2[0] = 1;
    for(int i = 0; i < n; i++)
    {
        pot1[i + 1] = (pot1[i] * p1) % N;
        pot2[i + 1] = (pot2[i] * p2) % M;
        h1[i + 1] = (h1[i] * p1 + s[i]) % N;
        h2[i + 1] = (h2[i] * p2 + s[i]) % M;
    }
    cin >> q;
    while(q--)
    {
        int a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;
        int poc = solve(a, b, l);
        //cout << poc << " ";
        if(poc == l + 1)
            cout << "=\n";
        else if(s[a + poc - 1] > s[b + poc - 1])
            cout << ">\n";
        else
            cout << "<\n";
    }
}