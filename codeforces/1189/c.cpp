
#ifdef WTF
/*
https://codeforces.com/contest/1189/problem/C
*/
#endif

#include <bits/stdc++.h>

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uint8;

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
uint8 s[100005];
map<pair<int, int>, pair<uint8, uint>> cache;
ll q;

pair<uint8, uint> dp(int left, int right){
    if(left == right){
        return make_pair(s[left], 0);
    } else if(right - left == 1){
        return make_pair(
            (s[left] + s[right]) % 10,
            s[left] + s[right] >= 10 ? 1 : 0
        );
    } else if(right - left == 3){
        uint digit = 0;
        uint candies = 0;
        int i = left;
        while(i < right){
            uint d = s[i] + s[i+1];
            if(d >= 10) ++candies;
            digit += (d % 10);
            i += 2;
        }
        if(digit >= 10) ++candies;
        digit %= 10;
        return make_pair(digit, candies);
    } else{
        auto key = make_pair(left, right);
        auto q = cache.find(key);
        if(q != cache.end()){
            return q->second;
        }
        ull mid = (left + right) / 2;
        auto a = dp(left, mid);
        auto b = dp(mid+1, right);
        auto c = make_pair(
                (a.first + b.first) % 10,
                a.second + b.second + (a.first + b.first >= 10 ? 1 : 0)
        );
        cache[key] = c;
        return c;
    }
}

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    fori(i, n){
        cin >> s[i];
        s[i] -= '0';
    }
    cin >> q;


    fori(i, q){
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << dp(a, b).second << endl;
    }
}
