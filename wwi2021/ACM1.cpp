#include <bits/stdc++.h>
using namespace std;

const long long t = 4 * 1e5 + 9;
long long tab[t];
vector <long long> wek;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> tab[i];
    int ost = 0;
    long long sum = 0;
    for(int i = 0; i < n; i ++) {
        if(sum + tab[i] <= m) sum += tab[i];
        else {
            ost = i;
            sum = tab[i];
        }
    }
    sum = 0;
    int wynik = 1;
    for(int i = ost; i < n + ost; i ++) {
        if(sum + tab[i % n] <= m) sum += tab[i % n];
        else {
            wynik ++;
            sum = tab[i % n];
        }
    }
    cout << wynik;
    return 0;
}