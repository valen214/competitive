
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

using namespace std;

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull n; cin >> n;
    string s; cin >> s;
    ull m; cin >> m;
    vector<ull> out(m, 0);

    ull chars[m][26];
    ull remain[m];
    fori(i, m){
        fori(j, 26){
            chars[i][j] = 0;
        }

        string _s;
        cin >> _s;
        fori(j, _s.size()){
            chars[i][_s[j]-'a'] += 1;
        }
        remain[i] = _s.size();

    }

    ull now[26];
    fori(i, 26){
        now[i] = 0;
    }
    fori(i, n){
        ull c = s[i]-'a';
        now[c] += 1;
        bool hasRemain = 0;
        fori(j, m){
            if(remain[j] && chars[j][c] == now[c]){
                remain[j] -= now[c];
                if(remain[j] == 0){
                    out[j] = i;
                }
            }
            if(remain[j]) hasRemain = 1;
        }
        if(!hasRemain) break;
    }
    fori(i, m){
        cout << (out[i] + 1) << endl;
    }
}
