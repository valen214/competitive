
#ifdef WTF
/*

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

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull n; cin >> n;
    string s; cin >> s;
    ull a[105];

    a[0] = 0;
    fori(i, s.size()){
        if(i > 0) a[i] = a[i-1];
        a[i] += ( s[i] - '0' );
    }
    if(n % 2 == 0 && a[n-1]*2 == n){
        cout << 2 << endl;
        cout << s[0] << " " << s.substr(1) << endl;
    } else{
        cout << 1 << endl;
        cout << s << endl;
    }
}
