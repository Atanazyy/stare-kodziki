#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;

int taba[r];
int tabb[r];
bool byl[r];

vector<int> per;
vector<int> sol;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> taba[i];
    for(int i = 1; i <= n; i++)
        cin >> tabb[i];
    if(n <= 8)
    {
        for(int i = 1; i <= n; i++)
            per.push_back(i);
        long long wyn = 1e18;
        do
        {
            long long akt = 0;
            for(int i = 1; i <= n; i++)
                byl[i] = 1;
            for(auto x: per)
            {
                int naj = 0;
                int wna = 1e9 + 9;
                for(int i = 1; i <= n; i++)
                    if(byl[i] && abs(taba[i] - tabb[x]) < wna)
                    {
                        naj = i;
                        wna = abs(taba[i] - tabb[x]);
                    }
                byl[naj] = 0;
                akt += wna;
            }
            if(akt < wyn)
            {
                wyn = akt;
                sol = per;
            }
        } while (next_permutation(per.begin(), per.end()));
        cout<< wyn << "\n";
        for (auto x : sol)
            cout << x << " ";
        return 0;
    }
    long long wyn = 0;
    for(int i = 1; i <= n; i++)
        wyn += abs(tabb[i] - taba[i]);
    cout << wyn << "\n";
    for(int i = 1; i <= n; i++)
        cout << i << " ";
    return 0;
}