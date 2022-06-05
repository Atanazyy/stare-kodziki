#include <bits/stdc++.h>

using namespace std;

const int r = 2e5 + 9;
const int p1 = 313, p2 = 997, N = 1e9 + 7, M = 1e9 + 9;
long long h1[r], h2[r], pot1[r], pot2[r];
int n;
vector <pair<int, int> > dos;

inline pair<long long, long long> hasz(int poc, int siz)
{
    return {(h1[poc + siz] - ((h1[poc] * pot1[siz]) % N) + N) % N, (h2[poc + siz] - ((h2[poc] * pot2[siz]) % M) + M) % M};
}

inline bool czy(int x)
{
    int poc = 0;
    dos.clear();
    while(poc + x <= n)
    {
        dos.push_back(hasz(poc, x));
        poc ++;
    }
    sort(dos.begin(), dos.end());
    for(int i = 1; i < dos.size(); i++)
        if(dos[i] == dos[i - 1]) 
            return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> n >> s;
    pot1[0] = 1;
    pot2[0] = 1;
    for(int i = 0;i < s.size(); i++)
    {
        h1[i + 1] = (h1[i] * p1 + s[i]) % N;
        h2[i + 1] = (h2[i] * p2 + s[i]) % M;
        pot1[i + 1]=(pot1[i] * p1) % N;
        pot2[i + 1]=(pot2[i] * p2) % M;
    }
    int p = 0, k = n;
    while(p < k)
    {
        int sr = (p + k) / 2;
        if(czy(sr))
            p = sr + 1;
        else
            k = sr;
    }
    cout << k - 1;
    /*int x;
    cin >> x;
    cout << czy(x);
    int a, b, roz;
    cin >> a >> b >> roz;
    cout << hasz(a - 1, roz).first << " " << hasz(a - 1, roz).second << "\n";
    cout << hasz(b - 1, roz).first << " " << hasz(b - 1, roz).second << "\n";*/
}