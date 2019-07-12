
#include <bits/stdc++.h>

#ifndef DEBUG
#define DEBUG 0
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define forab(i, a, b) for(ull i=a, max=b; i < max; ++i)
#define fori(i, n) for(ull i=0, max=n; i < max; ++i)
#define forr(i, n) for(ull i = n; i >= 0; --i)
#define bit(n, i) ((n >> i) & 1)
#define bin(n, l) ( bitset<l>(n).to_string() )
#define dbg(x) if(DEBUG) cout << #x << ": " << x << endl;

using namespace std;

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull T;
    cin >> T;

    fori(t, T){
        string input;
        cin >> input;

        ull b = 0;
        ull e = 0;
        fori(i, input.size()){
            switch(input[i]){
            default:
            case 'A': break;
            case 'B': ++b; break;
            case '.': ++e; break;
            }
        }

        char out = 'Y';
        if(e == 0){
            out = 'N';
        } else if(b < e){
            out = 'N';
        }
        cout << "Case #" << (t+1) << ": " << out << endl;
    }
}
