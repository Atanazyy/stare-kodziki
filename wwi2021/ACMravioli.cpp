#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, pop, akt;
    cin >> n;
    cin >> pop;
    for (int i = 1;i < n;i ++)
    {
        cin >> akt;
        if (abs(akt - pop) > 1)
        {
            cout << "NIE";
            return 0;
        }
        pop = akt;
    }
    cout << "mmm... ravioli";
    return 0;
}