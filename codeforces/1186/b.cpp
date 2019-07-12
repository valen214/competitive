
#include <bits/stdc++.h>

#define min(x, y) (x > y ? y : x)
#define max(x, y) (x < y ? y : x)

typedef unsigned long long ull;

using namespace std;

/*
3 3 => 2
3 4 => 3
4 4 => 3
4 5 => 4
4 6 => 5

*/

ull func(ull n, ull m){
    ull width_span = ((n+1) / 2);
    ull height_span = (m / 3);

    ull remaining = m - height_span * 3;
    ull out = width_span * height_span;
    switch(remaining){
    case 0: break;
    case 1: out += max(0, (n+1) / 3); break;
    case 2: out += width_span; break;
    }

    // cout << width_span << " " << height_span << " " << remaining << endl;

    return out;
}

int main(){
    ull n, m;
    cin >> n >> m;

    ull a = func(n, m);
    ull b = func(m, n);

    cout << max(a, b) << endl;
}
