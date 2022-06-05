#include "pra.h"

int *t;
bool *B;
int n;

void prepare(int x) {
    for(int i = 1; i <= n; ++i)
        B[i] = i == x;
}

int main() {
    n = init() * 2;
    /* jedyny sluszny sposob stworzenia tablicy o zmiennym rozmiarze bez użycia STL */
    t = new int[n + 1];
    B = new bool[n + 1];
    for(int i = 1; i <= n; ++i) {
        prepare(i);
        plug(B);
        for(int j = 1; j <= n; ++j)
            if(B[j] && j != i)
                t[i] = j;
    }
    answer(t);
    return 0;
}
