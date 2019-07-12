
/**
g++ d.cpp -o d.exe && ./d.exe < d.in
*/

#include <bits/stdc++.h>

#define min(x, y) (x > y ? y : x)
#define max(x, y) (x < y ? y : x)
#define fori(i, len) for(ull i = 0; i < len; ++i)

typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;

const ld EPSILON = 0.0000000000001;

using namespace std;

ld fractional(ld d){
    return modf(d, NULL);
}

int main(){
    ull n;
    cin >> n;

    vector<ld> v(n);
    vector<ll> out(n);

    ld diff = 0;
    fori(i, n){
        cin >> v[i];
        out[i] = (ll)trunc(v[i]);

        ld frac = fractional(v[i]);
        if(frac == 0.0) continue;

        if(v[i] < 0.0){
            if(diff > 0.0){
                diff -= (1 + frac);
                out[i] -= 1;
            } else{
                diff -= frac;
            }
        } else{
            if(diff < 0.0){
                diff += (1 - frac);
                out[i] += 1;
            } else{
                diff -= frac;
            }
        }
    }

    fori(i, n){
        cout << out[i] << endl;
    }
}
