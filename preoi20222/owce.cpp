#include <bits/stdc++.h>

using namespace std;

struct pkt
{
    long double x;
    long double y;
};

pkt t[1009];

int main()
{
    int n;
    long double r;
    cin >> n >> r;
    for(int i = 0; i < n; i++)
    {
        cin >> t[i].x >> t[i].y;
    }
    int wyn = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                continue;
            if(abs((t[j].y - t[i].y) * t[i].x - t[i].y * (t[i].x - t[j].x)) > r * sqrt((t[j].y - t[i].y) * (t[j].y - t[i].y) + (t[j].x - t[i].x) * (t[j].x - t[i].x)) || ())
                 wyn ++;
        }
    cout << wyn / 2;
}
