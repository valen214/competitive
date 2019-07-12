
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

int n;
int k;
uint a[1005];
uint min_diff[1005][1005];
bool tok[1005];

void gen_min_diff(){
    fori(i, n){
        min_diff[i][i] = 0;
        if(i < n-1) min_diff[i][i+1] = min_diff[i+1][i] = abs(a[i] - a[i+1]);
        if(i > 0) min_diff[i][i-1] = min_diff[i-1][i] = abs(a[i] - a[i-1]);
    }
}

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    fori(i, n){
        cin >> a[i];
        tok[i] = i < k;
    }

    gen_min_diff();
}
