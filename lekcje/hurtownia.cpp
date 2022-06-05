#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int r = 1e6;
int dos[r];
pair<int, int> zap[r];
long long drz[r];
int osd[r];
int roz;
int w;

int ost(int b)
{
    int a = roz;
    if(a == b) return osd[a] - roz + 1;
    int wyn = max(osd[a], osd[b]);
    while(a / 2 != b / 2)
    {
        if(a % 2 == 0) wyn = max(wyn, osd[a + 1]);
        if(b % 2 == 1) wyn = max(wyn, osd[b - 1]);
        a /= 2;
        b /= 2;
    }
    return wyn - roz + 1;
}

void akt(int a, int war)
{
    drz[a] = war;
    if(war > 0) osd[a] = a;
    else osd[a] = -inf;
    while(a > 1)
    {
        a/=2;
        osd[a] = max(osd[a * 2], osd[a * 2 + 1]);
        drz[a] = drz[a * 2] + drz[a * 2 + 1];
    }
}

long long sum(int a, int b)
{
    if(a == b) return drz[a];
    long long wyn = drz[a] + drz[b];
    while(a / 2 != b / 2)
    {
        if(a % 2 == 0) wyn += drz[a + 1];
        if(b % 2 == 1) wyn += drz[b - 1];
        a /= 2;
        b /= 2;
    }
    return wyn;
}

int main()
{
    int n;
    cin >> n;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(int i = 1; i <= 2 * roz; i++) 
        osd[i] = -inf;
    for(int i = 1; i <= n; i++)
    {
        cin >> dos[i];
        akt(i + roz - 1, dos[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> zap[i].first;
        zap[i].second = i;
    }
    sort(zap + 1, zap + n + 1);
    //for(int j = 1; j < 2 * roz; j++) cout << osd[j] << " ";
    for(int i = 1; i <= n; i++)
    {
        int S = zap[i].first;
        int V = zap[i].second;
        //cout << S << " "<< sum(roz, V + roz - 1) << "\n";
        if(S <= sum(roz, V + roz - 1)) 
        {
            w++;
            while(S > 0)
            {
                //for(int j = 1; j < 2 * roz; j++) cout << osd[j] << " ";
                //cout << "\n" << i << " " << S << " " << V << "\n";
                V = ost(V + roz - 1);
                if(S < drz[V + roz - 1])
                {
                    akt(V + roz - 1, drz[V + roz - 1] - S);
                    S = 0;
                }
                else
                {
                    S -= drz[V + roz - 1];
                    akt(V + roz - 1, 0);
                }
                V--;
            }
        }
    }
    cout << w;
}
