

/*
https://codeforces.com/contest/1186/problem/E

g++ -o e.exe e.cpp && ./e.exe < e.in


https://www.hackerearth.com/zh/practice/algorithms/
dynamic-programming/2-dimensional/tutorial/


*/

#include <bits/stdc++.h>

#define min(x, y) (x > y ? y : x)
#define max(x, y) (x < y ? y : x)
#define fori(i, len) for(ull i = 0; i < len; ++i)
#define forr(i, len) for(ull i = len-1; i >= 0; --i)

const double EPSILON = 0.0000000000001;

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

bool fractional(double d){
    return modf(d, NULL);
}

ull n, m, q;
ull n2, m2;
vector<vector<bool>> input;
vector<vector<ull>> cache;

ull dpf(ull x1, ull y1, ull x2, ull y2, bool inverted){
    if(x1 != 0 || y1 != 0){
        return dpf(0, 0, x2, y2) - dpf(0, 0, x2, y1) - dpf(0, y1, x1, y2);
    } else if(y2 < m && x2 < n){
        return inverted ? n*m - cache[y2][x2] : cache[y2][x2];
    } else if(y2 < m2 && x2 < n){
        // return cache[m-1][n-1] + dpf(0, 0, x2-n, y2-m, 1);
    } else if(y2 < m && x2 < n2){

    } else if(y2 < m2 && x2 < n2){

    }

    cache[y2][x2] = 0;
    if(x2 < n && y2 < m){
        forr(i, y2){
            forr(j, x2){

            }
            if(cache[i][x2]){
                cache[y2][x2] += cache[i][x2];
                break;
            }
            if(input[i][x2]) cache[y2][x2] += 1;
        }
        return cache[y2][x]
    }
}

void init(){
    cin >> n >> m >> q;
    n2 = n * 2;
    m2 = m * 2;

    cache.resize(n);
    input.resize(n);

    fori(i, n){
        cin >> line;

        input[i].resize(m, 0);
        cache.resize(m, 0);
        fori(j, m){
            if(j >= 1){
                cache[i][j] += cache[i][j-1];
            }
            if(i >= 1){
                cache[i][j] += cache[i-1][j];
            }
            if(i >= 1 && j >= 1){
                cache[i][j] -= cache[i-1][j-1];
            }
            if(line[j] == '1'){
                input[i][j] = 1;
                cache[i][j] += 1;
            }
        }
    }
}

int main(){

    string line;

    fori(_q, q){
        ull x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
    }

}
