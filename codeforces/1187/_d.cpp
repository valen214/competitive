
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

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

using namespace std;

const ull MAX_INT = 300005;

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ull t;
    cin >> t;
    vector<ll> counta(MAX_INT, 0);
    vector<ll> appeara(MAX_INT, -1); // first appearance

    vector<ll> countb(MAX_INT, 0);
    vector<ll> appearb(MAX_INT, -1); // last appearance
    vector<bool> safe(MAX_INT, 0);
    fori(tt, t){
        bool success = true;

        counta.clear(); counta.reserve(MAX_INT);
        appeara.clear(); appeara.reserve(MAX_INT);
        countb.clear(); countb.reserve(MAX_INT);
        appearb.clear(); appearb.reserve(MAX_INT);

        ull n;
        cin >> n;

        set<ll> seta;

        safe.clear(); safe.reserve(n);


        fori(i, n){
            ll a; cin >> a;
            if(!counta[a]) seta.insert(a);
            counta[a] += 1;
            if(appeara[a] == -1){ // first appearance
                appeara[a] = i;
            }
        }
        ull lastb;
        fori(i, n){
            ll b; cin >> b;
            countb[b] += 1;
            appearb[b] = i; // last appearance
        }

        fori(i, MAX_INT){
            if(counta[i] != countb[i]){
                success = false;
            }
            if(!success) break;
        }

        /*
        https://codeforces.com/contest/1187/submission/56321839
        */

        ll safe_count = 0;
        for(set<ll>::reverse_iterator rit = seta.rbegin();
                success && rit != seta.rend(); ++rit){
            ll aa = appeara[*rit];
            ll ab = appearb[*rit];
            // cout << "range of (" << *rit << "): " << aa << " " << ab << endl;
            if(aa <= ab){
                forab(i, aa, ab+1){
                    if(safe[i] == 0) safe_count += 1;
                    safe[i] = 1;
                }
            } else{
                forab(i, ab, aa+1){
                    if(!safe[i]){
                        success = false;
                        break;
                    }
                }
            }
            // cout << "safe_count: " << safe_count << endl;
            if(safe_count == n) break;
        }

        cout << (success ? "YES" : "NO") << endl;
    }
}
