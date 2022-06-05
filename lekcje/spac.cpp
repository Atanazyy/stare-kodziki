#include <bits/stdc++.h>

using namespace std;

string wzo[1000];
string mac[1000];

bool czy(int x, int y, int dx, int dy)
{
    for(int i = 0; i < dx; i++)
    {
        for(int j = 0; j < dy; j++)
        {
            if(wzo[i][j] != mac[i + x][j + y])
                return 0;
        }
    }
    return 1;
}

int main()
{
    cout << 1079915910 % 1000000007;
}