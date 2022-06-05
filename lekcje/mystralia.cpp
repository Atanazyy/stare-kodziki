#include <bits/stdc++.h>
const int N = 101;
const int p = 1e9 + 7;
struct matrix{
    int s;
    long long mat[N][N];
    };
matrix mult(matrix a, matrix b, int s) {
    matrix m;
    m.s = s;
    long long temp;
    for(int ry = 0; ry < s; ry++) {
        for(int rx = 0; rx < s; rx++) {
            temp = 0;
            for(int c = 0; c < s; c++) {
                temp = (temp + a.mat[c][ry]*b.mat[rx][c])%p;
                }
            m.mat[rx][ry] = temp;
            }
        }
    return m;
    }

matrix matrixExpo(matrix m, int s, long long po) {
    matrix res;
    res.s = s;
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
        //res.mat[j][i] = (s - i - 1 == j);
        res.mat[j][i] = (i==j);
            }
        }
    while(po > 0) {
        if(po%2 == 1) {
            res = mult(res, m, s);
            }
            po = po/2;
            m = mult(m, m, s);
        }
    return res;
    }
int main() {
    std::ios_base::sync_with_stdio(0);
    long long ms, po;
    matrix mx;
    std::cin>>ms>>po;
    for(int y = 0; y < ms; y++) {
        for(int x = 0; x < ms; x++) {
            std::cin>>mx.mat[x][y];
            }
        }
    matrix mx1 = matrixExpo(mx, ms, po);
    for(int i = 0; i < ms; i++) {
        for(int j = 0; j < ms; j++) {
            std::cout<<mx1.mat[j][i]<<" ";
            }
        std::cout<<"\n";
        }
    }