
#ifdef WTF
/*
https://www.codechef.com/JULY19B/problems/PRTAGN
*/
#endif

#include <bits/stdc++.h>

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

#define forab(i, a, b) for(ll i=a, max=b; i < max; ++i)
#define fori(i, n) for(ll i=0, max=n; i < max; ++i)
#define forr(i, n) for(ll i = n; i >= 0; --i)
#define bit(n, i) ((n >> i) & 1)
#define bin(n, l) ( bitset<l>(n).to_string() )
#define dbg(x) cout << #x << ": " << x << endl;

using namespace std;

void func(ull &E, ull &O, ull c){
    ull one = 0, zero = 0;
    while(c > 0){
        c & 1 ? ++one : ++zero;
        c >>= 1;
    }
    one % 2 ? ++O : ++E;
}

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull T; cin >> T;
    bool a[262144]; fori(i, 262144) a[i] = 0;

    set<ull> b;
    fori(_t, T){
        for(auto it = b.begin(); it != b.end(); ++it) a[*it] = 0;
        b.clear();
        // fori(i, 262144) a[i] = 0;

        ull E = 0;
        ull O = 0;
        ull Q; cin >> Q;

        ull X;
        fori(_q, Q){
            cin >> X;
            if(!a[X]){
                set<uint> newB;
                for(auto it = b.begin(); it != b.end(); ++it){
                    ull y = (*it) ^ X;
                    if(!a[y]){
                        func(E, O, y);
                        a[y] = 1;
                        newB.insert(y);
                    }
                }
                b.insert(newB.begin(), newB.end());

                func(E, O, X);
                a[X] = 1;
                b.insert(X);
            }
            cout << E << " " << O << endl;
        }
    }
}
