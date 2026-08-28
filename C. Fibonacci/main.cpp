#include "bits/stdc++.h"
#define int long long
#define pii pair < int, int >
#define pb push_back
#define vi vector < int >

using namespace std;

const int NMAX = 2;
const int MOD = 1e9 + 7;

struct Matrix{
    int m[NMAX][NMAX];
};

Matrix Multiply(Matrix a, Matrix b){
    Matrix ans = {}

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                ans.m[i][j] = (ans.m[i][j] + (a.m[i][k] * a.m[k][j]) % MOD) % MOD;
            }
        }
    }
    return ans;
}

int n;

void Solve(){

}

signed main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
