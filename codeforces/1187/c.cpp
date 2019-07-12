
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

    ull n, m;
    cin >> n >> m;

    vector<int> c(n+5, 0);
    vector<ull> out(n, 1);

    ull t[m];
    ull l[m];
    ull r[m];

    fori(i, m){
        cin >> t[i] >> l[i] >> r[i];
        l[i] -= 1;
        r[i] -= 1;

        if(t[i]){
            forab(j, l[i]+1, r[i]+1){
                c[j] = 1;
            }
        }
    }

    bool success = true;
    fori(i, m){
        if(!t[i]){
            bool found = false;
            forab(j, l[i]+1, r[i]+1){
                if(c[j] != 1){
                    found = true;
                    break;
                }
            }
            if(!found){
                success = false;
                break;
            }
        }
    }


    if(success){
        cout << "YES" << endl;

        ll now = 500000;
        cout << now;
        fori(i, n-1){
            now += c[i+1] ? 1 : -1;
            cout << " " << now;
        }
        cout << endl;
    } else{
        cout << "NO" << endl;
    }
}
