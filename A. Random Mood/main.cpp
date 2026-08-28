#include "bits/stdc++.h"
#define int long long
#define pii pair < int, int >
#define vi vector < int >
#define pb push_back

using namespace std;

/*
    a, b         e, f           ae + bg, af + bh
            x             =
    c, d         g, h           ce + dg, cf + dh



    1 - p,   p
       p,  1 - p

*/

const int NMAX = 2;

struct Matrix{
    double m[NMAX][NMAX];
};

Matrix Multiply(Matrix a, Matrix b){
    Matrix ans = {};

    for(int i = 0; i < NMAX; i++){
        for(int j = 0; j < NMAX; j++){
            for(int k = 0; k < NMAX; k++){
                ans.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return ans;
}

Matrix lgput(Matrix base, int exp){
    Matrix ans = {};

    ans.m[0][0] = 1;
    ans.m[1][1] = 1;

    while(exp){
        if(exp & 1 == 1){
            ans = Multiply(ans, base);
        }
        base = Multiply(base, base);
        exp >>= 1;
    }
    return ans;
}

int n;
double p;

void Solve(){
    cin >> n >> p;

    Matrix M = {{
        {1.0 - p, p},
        {p, 1.0 - p}
    }};

    Matrix ans = lgput(M, n);

    cout << fixed << setprecision(10) << ans.m[0][0];
}

signed main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
