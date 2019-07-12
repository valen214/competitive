
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

int N;
ull a[805];
bool init[805][805];
pair<ull, ull> cache[805][805];

pair<ull, ull> dp(int begin, int end){
    if(begin >= N && end >= N){
        begin = begin - N;
        end = end - N;
    }
    if(begin == end){
        return make_pair(a[end], 0);
    } else if(!init[begin][end]){
        ull value = -1;
        ull penalty = -1;
        fori(i, end-begin){
            auto a = dp(begin, begin+i);
            auto b = dp(begin+i+1, end);
            ull _p = a.first + a.second + b.first + b.second;
            if(_p < penalty){
                value = a.first + b.first;
                penalty = _p;
            }
        }
        auto out = make_pair(value, penalty);
        cache[begin][end] = out;
        init[begin][end] = 1;
        return out;
    } else{
        return cache[begin][end];
    }
}

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull T; cin >> T;


    /*
    a b c d
    a+b c d = a+b
    a+b+c d = a+b + a+b+c
    a+b c+d = a+b + c+d
    a+b+c+d = a+b + a+b+c + a+b+c+d = a+b + c+d + a+b+c+d

    */

    N = 0;
    fori(_t, T){
        fori(i, N*2) fori(j, N*2) init[i][j] = 0;

        cin >> N;
        fori(i, N){
            cin >> a[i];
            a[N+i] = a[i];
        }
        ull ans = -1;
        fori(i, N){
        	ull t = dp(i, N-1+i).second;
        	if(t < ans) ans = t;
        }
        cout << ans << endl;
    }
}
    
