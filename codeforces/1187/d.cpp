
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
    fori(tt, t){
        bool success = true;

        ull n;
        cin >> n;

        set<ll> seta;
        vector<ll> counta(MAX_INT, 0);
        vector<ll> appeara(MAX_INT, -1); // first appearance

        vector<ll> countb(MAX_INT, 0);
        vector<ll> appearb(MAX_INT, -1); // last appearance

        vector<pair<ll, ll>> safe;

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

        for(set<ll>::reverse_iterator rit = seta.rbegin();
                success && rit != seta.rend(); ++rit){
            ll aa = appeara[*rit];
            ll ab = appearb[*rit];
            if(aa <= ab){
                vector<ll> need_merge;
                for(ll i = 0; i < safe.size(); ++i){
                    if(safe[i].first > ab+1 || safe[i].second < aa-1) continue;
                    need_merge.push_back(i);
                }
                if(need_merge.size()){
                    ll i = need_merge[0];
                    safe[i].first = min(safe[i].first, aa);
                    safe[i].second = max(safe[i].second, ab);

                    for(ll j = need_merge.size()-1; j >= 1; --j){
                        ll nm = need_merge[j];
                        safe[i].first = min(safe[i].first, safe[nm].first);
                        safe[i].second = max(safe[i].second, safe[nm].second);
                        safe.erase(safe.begin()+nm);
                    }
                    cout << "merged pair: " << safe[i].first << " " << safe[i].second << endl;
                } else{
                    safe.push_back(make_pair(aa, ab));
                    cout << "making pair: " << aa << " " << ab << endl;
                }
            } else{
                bool found_safe = false;
                for(auto it = safe.begin(); it != safe.end(); ++it){
                    if(it->first <= aa && it->second >= ab){
                        found_safe = true;
                        break;
                    }
                }
                if(!found_safe){
                    success = false;
                }
            }

            if(safe.size() && safe[0].first == 0 && safe[0].second == n-1){
                cout << "YES BREAK!" << endl;
                break;
            }
        }

        cout << (success ? "YES" : "NO") << endl;
    }
}
