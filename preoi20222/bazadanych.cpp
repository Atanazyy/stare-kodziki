#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const long long N = 1e9 + 7, M = 1e9 + 9, a = 131, b = 997, r = 1e6;

//map<pair<pair<long long, long long>, pair<long long, long long> >, int> mapa;
vector<pair<long long, long long> > pie[r];
vector<pair<long long, long long> > ost[r];

vector<long long> pota;
vector<long long> potb;
string s;

/*pair<long long, long long> hasz(int o)
{
    return {(N + pie[i][s.size()].f - ((pota[o] * pie[i][s.size() - o].f)% N)) % N, (M + pie[i][s.size()].s - ((potb[o] * pie[i][s.size() - o].s)% M)) % M};
}*/

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        cin >> s;
        pota.clear();
        potb.clear();
        pota.push_back(1);
        potb.push_back(1);
        pie[i].push_back({0, 0});
        for(int j = 0; j < s.size(); j++)
        {
            pie[i].push_back({(a * pie[i][j].f + s[j]) % N, (b * pie[i][j].s + s[j]) % M});
            pota.push_back((pota[j] * a) % N);
            potb.push_back((potb[j] * b) % M);
        }
        int ile = 0;
        ost[i].push_back({0, 0});
        for(int j = s.size() - 1; j >= 0; j--)
        {
            ost[i].push_back({(ost[i][ile].f + pota[ile] * s[j]) % N, (ost[i][ile].s + potb[ile] * s[j]) % M});
            ile++;
        }
        /*for(int j = 0; j <= s.size(); j++)
        {
            cout << pie[i][j].f << " " << ost[i][j].f << "\n";
        }*/
    }
    while(q--)
    {
        cin >> s;
        pair<long long, long long> start;
        pair<long long, long long> kon;
        start = {0, 0};
        kon = {0, 0};
        int ile;
        for(int j = 0; j < s.size(); j++)
        {
            ile = j;
            if(s[j] == '*')
                break;
            start = {(a * start.f + s[j]) % N, (b * start.s + s[j]) % M};
        }
        for(int j = ile + 1; j < s.size(); j++)
        {
            //cout << s[j];
            kon = {(a * kon.f + s[j]) % N, (b * kon.s + s[j]) % M};
        }
        //cout << start.f << " " << kon.f << "\n";
        int wyn = 0;
        for(int j = 0; j < n; j++)
            if(start == pie[j][ile] && kon == ost[j][s.size() - ile - 1] && s.size() - 1 <= pie[j].size() - 1) wyn++;
        cout << wyn << "\n";
    }
}
