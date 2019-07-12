
#ifdef WTF
/*
https://www.codechef.com/JULY19B/problems/CIRMERGE
*/
#endif

#include <bits/stdc++.h>

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define forab(i, a, b) for(ll i=a, max=b; i < max; ++i)
#define fori(i, n) for(ll i=0, max=n; i < max; ++i)
#define forr(i, n) for(ll i = n; i >= 0; --i)
#define bit(n, i) ((n >> i) & 1)
#define bin(n, l) ( bitset<l>(n).to_string() )
#define dbg(x) cout << #x << ": " << x << endl;

#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

using namespace std;

ull a[100005];
int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull T; cin >> T;
    fori(_t, T){
        int N; cin >> N;
        ull sum = 0;
        fori(i, N){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % N == 0){
            ull mean = sum / N;
            ll ans = -1;
            fori(i, N){
                if(a[i] == mean){
                    ans = i;
                    break;
                }
            }
            if(ans >= 0){
                cout << (ans+1) << endl;
                continue;
            }
        }
        cout << "Impossible" << endl;
    }
}
