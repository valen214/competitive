
#include <bits/stdc++.h>


typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define forab(i, a, b) for(ull i=a, max=b; i < max; ++i)
#define fori(i, n) for(ull i=0, max=n; i < max; ++i)
#define forr(i, n) for(ull i = n; i >= 0; --i)
#define bit(n, i) ((n >> i) & 1)
#define bin(n, l) ( bitset<l>(n).to_string() )
#define dbg(x) cout << #x << ": " << x << endl;

#define min(a, b) (a > b ? b : a)
#define max(a, b) (a < b ? b : a)

using namespace std;

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull T;
    cin >> T;

    fori(_t, T){
        ll n, s, t;
        cin >> n >> s >> t;

        ll both = (s + t - n);
        ll rs = s - both;
        ll rt = t - both;

        ll ans;
        ans = max(s-both+1, t-both+1);
        cout << ans << endl;
    }
}
